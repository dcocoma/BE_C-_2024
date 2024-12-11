#include "Mqtt.h"
#include "SenProx.h"
#include "SenSon.h"
#include "LCD.h"
#include "Potenciometre.h"
#include "Button.h"
#include "Securite.h"
#include "Buzzer.h"

// Hardware configuration
#define BUTTON_ACTIVATE_PIN D5              // Pin for the activate button
#define BUTTON_PASSCODE_PIN D8              // Pin for the passcode button
#define SENSOR_DISTANCE_PIN D7              // Pin for the passcode button
#define BUZZER_PIN D3              // Pin for the passcode button
#define SENSOR_DISTANCE_THRESHOLD 20        // Distance in cm to trigger an intrusion alert
#define LOOP_DELAY 1000                      // Delay in milliseconds between MQTT message sends

// Class objects
//Mqtt Server("Note 13p+", "123456789", "broker.emqx.io"); // MQTT server configuration
Buzzer buzz(BUZZER_PIN);
SenProx sensprox(SENSOR_DISTANCE_PIN);                   // Activate sensor
Button activate(BUTTON_ACTIVATE_PIN);                   // Activate button
Button Passcodetry(BUTTON_PASSCODE_PIN);                // Passcode button
Potenciometre pot;                                      // Potentiometer
LCD lcd;                                                // LCD display
Securite secure(&lcd);
Mqtt Server("Note 13p+", "123456789", "broker.emqx.io"); // MQTT server configuration

// Global variables
unsigned long lastMsg = 0;  // Tracks the time of the last message sent
bool Alarm = false;         // Tracks whether the alarm system is active or not
bool intruder = false;
String code = "0000";

// Function to initialize the system
void setup() {
  Serial.begin(115200); // Initialize the serial monitor for debugging
  lcd.Init();
  lcd.print("WiFi connection"); // Display connection status on LCD
  Server.setup_wifi();            // Connect to the Wi-Fi server

  String message = "WiFi connected"; 
  lcd.print(message); // Indicate that the system is ready
  Serial.println(message);
  
  delay(1000);

  lcd.print("Serv. Connection"); // Indicate attempting connection on LCD
  Server.reconnect();          // Attempt to reconnect to the server
  lcd.print("Serv. Connected");    // Indicate successful reconnection
  
  delay(1000);
  lcd.SetTextF1("Lect ON Alrm OFF"); // Initial display on the LCD
  lcd.Refresh();                     // Refresh the LCD to update the display

  Server.envoyermsgint("position", 0);
  Server.envoyermsgint("attemp", 0);
  Server.envoyermsgtxt("password", code);
  Server.envoyermsgtxt("Alrm","");
}

// Function to handle main security logic
void SecurityLoop() {
  // Read the potentiometer position and normalize it to a scale of 0-10
  int posi = pot.getPosPot();
  if (posi >= 10) posi = 15; // Handle edge case for potentiometer maximum position
  lcd.SetPosLCD(posi);       // Update the LCD with the potentiometer position
  sensprox.getDistance();

  // Send periodic updates to the server
  unsigned long now = millis(); // Get the current time in milliseconds
  if (now - lastMsg > LOOP_DELAY) {
    lastMsg = now; // Update the last message time
    Server.envoyermsgint("Distance", sensprox.getDistance()); // Send proximity sensor data
    Server.envoyermsgint("dB", Passcodetry.isPressed());      // Send passcode button state
    Server.envoyermsgint("position", secure.getPosPasse()+1);
    Server.envoyermsgint("attemp", secure.getTentatif());
    Server.envoyermsgtxt("password", lcd.getPasscode());
  }
}

// Function to handle the activate button logic
void HandleActivateButton() {
    Alarm = true;             // Activate the alarm
    lcd.print("Alarm working");
    lcd.SetTextF1("Lect ON Alrm ON"); // Update the LCD to show alarm is ON
    Server.envoyermsgtxt("Alrm", "Working"); // Notify via MQTT

    delay(1000);
    lcd.Refresh(); // Refresh the LCD 
}

// Function to handle the passcode button logic
void HandlePasscodeButton() {
    
    String msm = "val :" +  String(secure.getPosPasse()); 
    String m2 = "intentos: " + String(secure.getTentatif());
    Server.envoyermsgtxt("pos", msm);
    Server.envoyermsgtxt("pass", m2);
    int posi = pot.getPosPot(); // Read the potentiometer value

    if (posi <= 9){

      Server.envoyermsgint("msgs", posi); // Send the message via MQTT
      lcd.print(String(posi)); // Display the message on the LCD
      Serial.println(posi);
    
      secure.setMotEcrit(posi);
      lcd.setPasscode(secure.getMotEcrit());

      if(secure.getTentatif() > 3){ IntruderProtocol(); }
      if(secure.checkRightPass()){
        secure.resetTentatives();
        secure.ResetRightPass();
        Alarm = false;
        DeactivateAlarm();
      }

    } else {
      String message = "Erase"; // Convert the value to a message
      Server.envoyermsgtxt("msgs", message); // Send the message via MQTT
      lcd.print(message); // Display the message on the LCD
      Serial.println(message);
      secure.effacer();
      lcd.setPasscode(secure.getMotEcrit());
    }

    delay(1000);   // Add a delay to prevent multiple rapid triggers
    lcd.Refresh(); // Refresh the LCD display
}

// Function to check for intrusions
void CheckForIntrusion() {
  // If the alarm is active and the proximity sensor detects an object closer than the threshold
  if (sensprox.getDistance() < SENSOR_DISTANCE_THRESHOLD && !intruder) {
    IntruderProtocol();
  }
}

void IntruderProtocol(){
    buzz.setBuzzerON();
    intruder = true;
    String msgs = "INTRUDER!";
    lcd.print(msgs);            // Display intrusion alert on LCD
    Server.envoyermsgtxt("Alrm", msgs); // Notify via MQTT
    Serial.println(msgs);          // Print the alert for debugging
    lcd.SetTextF1(msgs);

}

void DeactivateAlarm(){
    buzz.setBuzzerOFF();
    intruder = false;
    secure.resetTentatives();
    lcd.print("Alarm desabled");            // Display intrusion alert on LCD
    Server.envoyermsgtxt("Alrm", "Alarm desabled"); // Notify via MQTT
    Serial.println("Alarm desabled");          // Print the alert for debugging
    delay(1000);
    lcd.SetTextF1("Lect ON Alrm OFF");
    lcd.Refresh();
}

// Main loop
void loop() {
  // Ensure the server is always connected
  if (!Server.Isconnected()) {
    lcd.print("Server Reconnect"); // Indicate attempting connection on LCD
    Server.reconnect();          // Attempt to reconnect to the server
    lcd.print("Reconnected");    // Indicate successful reconnection
    delay(1000);                 // Add delay for stability
    lcd.Refresh();               // Refresh the LCD display
  }
  
  Server.run(); // Keep the MQTT server connection alive

  // Call individual functions to handle specific logic
  SecurityLoop();         // Execute the main security loop
  
  if (Alarm){
    if(Passcodetry.isPressed()){ HandlePasscodeButton(); } // Handle the logic for the passcode button
    CheckForIntrusion();    // Check if there is an intrusion
  } else {
    if(activate.isPressed()){ HandleActivateButton(); } // Handle the logic for the activate button
  }
}

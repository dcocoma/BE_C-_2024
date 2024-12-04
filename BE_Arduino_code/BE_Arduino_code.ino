#include "Mqtt.h"
#include "SenProx.h"
#include "SenSon.h"
#include "LCD.h"
#include "Potenciometre.h"
#include "Button.h"

// Hardware configuration
#define BUTTON_ACTIVATE_PIN D5              // Pin for the activate button
#define BUTTON_PASSCODE_PIN D8              // Pin for the passcode button
#define SENSOR_DISTANCE_PIN D7              // Pin for the passcode button
#define SENSOR_DISTANCE_THRESHOLD 40        // Distance in cm to trigger an intrusion alert
#define LOOP_DELAY 500                      // Delay in milliseconds between MQTT message sends

// Class objects
Mqtt Server("Note 13p+", "123456789", "broker.emqx.io"); // MQTT server configuration
SenProx sensprox(SENSOR_DISTANCE_PIN);                   // Activate sensor
Button activate(BUTTON_ACTIVATE_PIN);                   // Activate button
Button Passcodetry(BUTTON_PASSCODE_PIN);                // Passcode button
Potenciometre pot;                                      // Potentiometer
LCD lcd;                                                // LCD display

// Global variables
unsigned long lastMsg = 0;  // Tracks the time of the last message sent
bool Alarm = false;         // Tracks whether the alarm system is active or not

// Function to initialize the system
void setup() {
  Serial.begin(115200); // Initialize the serial monitor for debugging
  lcd.print("Server connection"); // Display connection status on LCD
  Server.setup_wifi();            // Connect to the Wi-Fi server

  lcd.print("System initialized"); // Indicate that the system is ready
  Serial.println("System initialized");
  Server.envoyermsgtxt("msgs", "System initiated"); // Notify via MQTT that the system has started

  lcd.SetTextF1("Lect ON Alrm OFF"); // Initial display on the LCD
  lcd.Refresh();                     // Refresh the LCD to update the display
}

// Function to handle main security logic
void SecurityLoop() {
  // Read the potentiometer position and normalize it to a scale of 0-10
  int posi = pot.getPosPot();
  posi = ((10 * posi) / 1023);
  if (posi >= 10) posi = 15; // Handle edge case for potentiometer maximum position
  lcd.SetPosLCD(posi);       // Update the LCD with the potentiometer position

  Server.run(); // Keep the MQTT server connection alive

  // Send periodic updates to the server
  unsigned long now = millis(); // Get the current time in milliseconds
  if (now - lastMsg > LOOP_DELAY) {
    lastMsg = now; // Update the last message time
    Server.envoyermsgint("Distance", sensprox.getDistance()); // Send proximity sensor data
    Server.envoyermsgint("dB", Passcodetry.isPressed());      // Send passcode button state
  }
}

// Function to handle the activate button logic
void HandleActivateButton() {
  if (activate.isPressed()) { // Check if the activate button is pressed
    delay(100);               // Debounce to avoid multiple rapid presses
    Alarm = true;             // Activate the alarm
    lcd.SetTextF1("Lect ON Alrm ON"); // Update the LCD to show alarm is ON
    Server.envoyermsgtxt("msgs", "Alarm activated"); // Notify via MQTT
    lcd.Refresh(); // Refresh the LCD
  }
}

// Function to handle the passcode button logic
void HandlePasscodeButton() {
  if (Passcodetry.isPressed()) { // Check if the passcode button is pressed
    int posi = pot.getPosPot(); // Read the potentiometer value
    String message = String(posi / 100) + " sended"; // Convert the value to a message
    Serial.println(posi / 100); // Print the value for debugging
    Server.envoyermsgtxt("msgs", message); // Send the message via MQTT
    lcd.print(message); // Display the message on the LCD
    Alarm = false;

    delay(500);   // Add a delay to prevent multiple rapid triggers
    lcd.Refresh(); // Refresh the LCD display
  }
}

// Function to check for intrusions
void CheckForIntrusion() {
  // If the alarm is active and the proximity sensor detects an object closer than the threshold
  if (Alarm && sensprox.getDistance() < SENSOR_DISTANCE_THRESHOLD) {
    lcd.print("INTRUDER!");            // Display intrusion alert on LCD
    Server.envoyermsgtxt("Alrm", "INTRUDER!"); // Notify via MQTT
    Serial.println("INTRUDER!");          // Print the alert for debugging
  }
}

// Main loop
void loop() {
  // Ensure the server is always connected
  if (!Server.Isconnected()) {
    lcd.print("Server connect"); // Indicate attempting connection on LCD
    Server.reconnect();          // Attempt to reconnect to the server
    lcd.print("Reconnected");    // Indicate successful reconnection
    delay(1000);                 // Add delay for stability
    lcd.Refresh();               // Refresh the LCD display
  }

  // Call individual functions to handle specific logic
  HandleActivateButton(); // Handle the logic for the activate button
  HandlePasscodeButton(); // Handle the logic for the passcode button
  SecurityLoop();         // Execute the main security loop
  CheckForIntrusion();    // Check if there is an intrusion
}

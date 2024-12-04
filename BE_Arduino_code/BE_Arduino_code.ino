#include "Mqtt.h"
#include "SenProx.h"
#include "SenSon.h"
#include "LCD.h"

// Déclaration de la classe Mqtt
Mqtt Server("Note 13p+", "123456789", "broker.emqx.io");
SenProx sensprox(D7);
SenSon senson(A0);
LCD lcd;
// Declaration de variables globales

unsigned long lastMsg = 0;         // Dernier message envoyé

void setup() {
  Serial.begin(115200);
  Server.setup_wifi();
  Serial.println("Systeme initialisé.");
  lcd.SetTextF1("Security system working");
  lcd.Refresh();
}

void loop() {
  //Serial.println(ultrasonic.MeasureInCentimeters());
  if (!Server.Isconnected()) {
        Server.reconnect();
  }
  Server.run();
  unsigned long now2 = millis();
  if (now2 - lastMsg > 500) {
    lastMsg = now2;
  Server.envoyermsg("Distance",sensprox.getDistance());
  Server.envoyermsg("dB",senson.getDb());
  Server.envoyermsg("msgs",9);
  }
}

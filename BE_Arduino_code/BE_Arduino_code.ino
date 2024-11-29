#include "Ultrasonic.h"
#include "Application.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "Mqtt.h"

Ultrasonic ultrasonic(D7);
WiFiClient espClient;
unsigned long lastMsg = 0;         // Dernier message envoyé
// Déclaration de la classe Mqtt
Mqtt Server(espClient, "Note 13p+", "123456789", "broker.emqx.io");

void setup() {
  Serial.begin(115200);
  Server.setup_wifi();
  Serial.println("Systeme initialisé.");
}

void loop() {
  //Serial.println(ultrasonic.MeasureInCentimeters());
  if (!Server.Isconnected()) {
        Server.reconnect();
  }
  Server.run();

  unsigned long now2 = millis();
  
  if (now2 - lastMsg > 100) {
    lastMsg = now2;
  Server.envoyermsg("Distance",ultrasonic.MeasureInCentimeters());
  Server.envoyermsg("dB",5);
  Server.envoyermsg("msgs",9);
  }
}

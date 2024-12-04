#include "Mqtt.h"

/**
 * @brief Constructeur de la classe Mqtt
 */
Mqtt::Mqtt(const char* ssid, const char* password, const char* mqtt_server) : ssid(ssid), password(password), mqtt_server(mqtt_server), value(0) {
  
  client.setClient(NewClient);
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

/**
 * @brief Destructeur de la classe Mqtt
 */
Mqtt::~Mqtt() {}


void Mqtt::run() {
    client.loop(); // Mantener MQTT activo
}

bool Mqtt::Isconnected(){
    return client.connected();
    }

/**
 * @brief Connexion au réseau WiFi
 */
void Mqtt::setup_wifi() {
    delay(10);
    Serial.println();
    Serial.print("Connexion à ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    randomSeed(micros());
    Serial.println("\nWiFi connecté");
    Serial.print("Adresse IP : ");
    Serial.println(WiFi.localIP());
}

/**
 * @brief Reconnexion au serveur MQTT
 */
void Mqtt::reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic/msgs", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

/**
 * @brief Envoi d’un message sur un canal MQTT
 * @param canal Canal cible
 * @param message Contenu du message
 */
void Mqtt::envoyermsg(const char* canal, int val) {

    snprintf(msg, MSG_BUFFER_SIZE, "%d", val); // Convierte el valor a cadena y lo almacena en 'msg'
    String fullTopic = String("outTopic/") + String(canal);
    Serial.print("Publish message: ");
    //Serial.print("Message envoyé sur le sujet: ");
    Serial.print(fullTopic);
    Serial.print(" ");
    Serial.println(msg);

    client.publish(fullTopic.c_str(), msg); // Publicar en el canal correcto
}

/**
 * @brief Callback pour traiter les messages reçus
 * @param topic Sujet du message
 * @param payload Données du message
 * @param length Longueur des données
 */
void Mqtt::callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Message reçu sur le sujet: ");
    Serial.print(topic);
    Serial.print(" - Message: ");
    for (unsigned int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
    Serial.println();
}

/**
 * @brief Modifier le mot écrit (fonction personnalisée)
 */
void Mqtt::ModifierMotEcrit() {
    // Implémentation personnalisée
}

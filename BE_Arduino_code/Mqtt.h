#ifndef MQTT_H_
#define MQTT_H_

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>

// Buffer size for MQTT messages
#define MSG_BUFFER_SIZE (50)

/**
 * @class Mqtt
 * @brief Class to manage WiFi and MQTT connections and operations.
 */
class Mqtt {
private:
    const char* ssid;              // WiFi network name
    const char* password;          // WiFi network password
    const char* mqtt_server;       // MQTT broker address
    WiFiClient NewClient;          // WiFi client for network communication
    PubSubClient client;           // MQTT client for broker communication
    char msg[MSG_BUFFER_SIZE];     // Buffer for MQTT messages
    int value;                     // Value associated with the message

public:
    /**
     * @brief Constructor: Initializes WiFi and MQTT parameters.
     * @param ssid WiFi network name.
     * @param password WiFi network password.
     * @param mqtt_server MQTT broker address.
     */
    Mqtt(const char* ssid, const char* password, const char* mqtt_server);

    /**
     * @brief Destructor: Cleans up resources.
     */
    ~Mqtt();

    void run();                      // Keeps the MQTT client running
    bool Isconnected();              // Checks if MQTT client is connected
    void setup_wifi();               // Connects to WiFi
    void reconnect();                // Reconnects to MQTT broker
    void envoyermsgint(const char* canal, int val);  // Sends an integer message
    void envoyermsgtxt(const char* canal, String text); // Sends a text message
    static void callback(char* topic, byte* payload, unsigned int length); // Message callback
    void ModifierMotEcrit();         // Custom functionality placeholder
};

#endif


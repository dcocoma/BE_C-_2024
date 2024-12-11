#include "Mqtt.h"

/**
 * @brief Constructor: Initializes the MQTT client and sets its parameters.
 * @param ssid WiFi network name.
 * @param password WiFi network password.
 * @param mqtt_server MQTT server address.
 */
Mqtt::Mqtt(const char* ssid, const char* password, const char* mqtt_server) 
    : ssid(ssid), password(password), mqtt_server(mqtt_server) {
    client.setClient(NewClient);                 // Attach the WiFi client to the MQTT client
    client.setServer(mqtt_server, 1883);         // Set MQTT server and port
    client.setCallback(callback);               // Set the callback function for incoming messages
}

/**
 * @brief Destructor: Cleans up resources (if any).
 */
Mqtt::~Mqtt() {}

/**
 * @brief Keeps the MQTT connection active by processing incoming/outgoing messages.
 */
void Mqtt::run() {
    client.loop();
}

/**
 * @brief Checks if the MQTT client is connected to the broker.
 * @return True if connected, false otherwise.
 */

bool Mqtt::Isconnected() {
    return client.connected();
}

/**
 * @brief Connects to the specified WiFi network.
 */
void Mqtt::setup_wifi() {
    delay(10);
    Serial.println("\nConnecting to WiFi...");
    Serial.print("Connecting to: ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);           // Set WiFi mode to station
    WiFi.begin(ssid, password);    // Start connecting to WiFi

    // Wait until the connection is established
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    randomSeed(micros()); // Initialize the random number generator
    Serial.println("\nWiFi connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

/**
 * @brief Reconnects to the MQTT broker if the connection is lost.
 */
void Mqtt::reconnect() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        String clientId = "ESP8266Client-";     // Create a unique client ID
        clientId += String(random(0xffff), HEX);
        
        if (client.connect(clientId.c_str())) { // Attempt to connect
            Serial.println("Connected to MQTT broker.");
            client.publish("outTopic/msgs", "System connected");  // Publish a test message
            client.subscribe("inTopic");                     // Subscribe to a topic
        } else {
            Serial.print("Connection failed, rc=");
            Serial.print(client.state());
            Serial.println(". Retrying in 5 seconds...");
            delay(5000);
        }
    }
}

/**
 * @brief Sends an integer value as a message to a specified MQTT channel.
 * @param canal MQTT channel.
 * @param val Integer valu to send.
 */
void Mqtt::envoyermsgint(const char* canal, int val) {
    snprintf(msg, MSG_BUFFER_SIZE, "%d", val);  // Convert integer to a string
    String fullTopic = String("outTopic/") + String(canal); // Format the topic
    Serial.print("Publishing to: ");
    Serial.print(fullTopic);
    Serial.print(" Message: ");
    Serial.println(msg);
    client.publish(fullTopic.c_str(), msg); // Publish the message
}

/**
 * @brief Sends a text message to a specified MQTT channel.
 * @param canal MQTT channel.
 * @param text String to send.
 */
void Mqtt::envoyermsgtxt(const char* canal, const String text) {
    snprintf(msg, MSG_BUFFER_SIZE, "%s", text.c_str()); // Convert string to char array
    String fullTopic = String("outTopic/") + String(canal); // Format the topic
    Serial.print("Publishing to: ");
    Serial.print(fullTopic);
    Serial.print(" Message: ");
    Serial.println(msg);
    client.publish(fullTopic.c_str(), msg); // Publish the message
}

/**
 * @brief Callback function to process received MQTT messages.
 * @param topic Topic of the received message.
 * @param payload Message content.
 * @param length Length of the message content.
 */
void Mqtt::callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Message received on topic: ");
    Serial.print(topic);
    Serial.print(" Message: ");
    for (unsigned int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
    Serial.println();
}

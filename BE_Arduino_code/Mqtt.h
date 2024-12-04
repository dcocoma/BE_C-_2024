#ifndef MQTT_H_
#define MQTT_H_

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#define MSG_BUFFER_SIZE (50)
#include "Arduino.h"

/**
  * @class Mqtt
  * @brief Classe pour gérer la connexion MQTT
*/    
class Mqtt
{
private:
    const char* ssid;              // Nom du réseau WiFi
    const char* password;          // Mot de passe du réseau WiFi
    const char* mqtt_server;       // Adresse du serveur MQTT
    WiFiClient NewClient;          // Client WiFI
    PubSubClient client;           // Client MQTT
    char msg[MSG_BUFFER_SIZE];     // Tampon pour les messages MQTT
    int value;                     // Valeur associée au message
    

public:
    /**
     * @brief Constructeur avec paramètres
     * @param wifiClient Client WiFi
     * @param ssid Nom du réseau WiFi
     * @param password Mot de passe du réseau WiFi
     * @param mqtt_server Adresse du serveur MQTT
     */
    Mqtt(const char* ssid, const char* password, const char* mqtt_server);

    /**
     * @brief Destructeur
     */
    ~Mqtt();


    void run();

    bool Isconnected();

    /**
     * @brief Connexion au réseau WiFi
     */
    void setup_wifi(void);

    /**
     * @brief Envoi d’un message via MQTT
     * @param canal Canal MQTT
     * @param msg Message à envoyer
     */
    void envoyermsgint(const char* canal, int val);
    void envoyermsgtxt(const char* canal, String text);

    /**
     * @brief Reconnexion au serveur MQTT si la connexion est perdue
     */
    void reconnect();

    /**
     * @brief Callback pour gérer les messages reçus
     */


    /**
     * @brief Modifier le message écrit (fonctionnalité personnalisée)
     */
    void ModifierMotEcrit();

    static void callback(char* topic, byte* payload, unsigned int length);
};

#endif

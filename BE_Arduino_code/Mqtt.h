/*********************************************************************
 * @file  Mqtt.h
 * @author <davidlcr@live.com>
 * @brief Fichier header du Mqtt
 *********************************************************************/

#ifndef MQTT_H_
#define MQTT_H_
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

/**
  * @class Mqtt
  * @brief Classe Mqtt 
*/    
class Mqtt
{
    private:

    const char* ssid = "Note 13p+";
    const char* password = "123456789";
    const char* mqtt_server = "broker.emqx.io";

    WiFiClient espClient;
    PubSubClient client(espClient);
    unsigned long lastMsg = 0;
    #define MSG_BUFFER_SIZE	(50)
    char msg[MSG_BUFFER_SIZE];
    int value = 0;
  public :
    /**
     * @fn Mqtt();
     * @brief Constructeur par defaut
    */    
    Mqtt();
    /**
     * @fn Mqtt();
     * @brief Destructeur
    */    
    ~Mqtt();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'Mqtt
    */
    void setup_wifi(void);
    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'Mqtt
    */
    void envoyermsg(char canal, char msg);
    void reconnect();
    void callback(char* topic, byte* payload, unsigned int length)
    void ModifierMotEcrit();
};
#endif
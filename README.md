# Système de Sécurité avec ESP8266

## Description du Projet  
Ce projet consiste à développer un système de sécurité utilisant une carte ESP8266. Il inclut plusieurs fonctionnalités comme le contrôle via un potentiomètre, l'interaction avec des boutons, et l'affichage sur un écran LCD. Le système permet de configurer des codes de sécurité, de surveiller l'environnement avec des capteurs (proximité, son), et de communiquer avec un serveur MQTT pour des notifications ou des actions à distance.

---

## Fonctionnalités Principales  
1. **Affichage sur écran LCD**  
   - Affichage des numéros (0 à 9) pour entrer le mot de passe.  
   - Position du curseur dynamique pour l'entrée des chiffres.  
   - Symbole spécial pour effacer le dernier chiffre saisi à la 15ème position de l'écran LCD.  
   - Messages affichés sur l'écran pour indiquer si l'alarme est active ou si un intrus a été détecté.
   - 
2. **Contrôle par Potentiomètre**  
   - Permet de sélectionner les chiffres à afficher sur le LCD.  

3. **Boutons de Commande**  
   - Validation ou effacement des chiffres du mot de passe.  

4. **Capteurs Intégrés**  
   - **Capteur de Proximité** : Mesure des distances en centimètres.  
   - **Capteur Sonore** : Détecte l'intensité sonore en décibels.  

5. **Gestion des Codes de Sécurité**  
   - Entrée et validation d’un mot de passe à 4 chiffres.  
   - Signalisation en cas de tentative réussie ou échouée.
   - **Alarme sonore (Buzzer)** : Si trois tentatives incorrectes de mot de passe sont effectuées, un buzzer se déclenche pour signaler l'erreur.  

6. **Connexion au Serveur MQTT**  
   - Envoi de messages (texte ou numériques) à des canaux spécifiques.  
   - Réception et traitement des messages via des topics MQTT.  

---

## Matériel Utilisé  
- **ESP8266** : Microcontrôleur pour la gestion des fonctions.  
- **Écran LCD RGB** : Pour l'affichage des informations.  
- **Potentiomètre** : Pour le contrôle de la sélection.  
- **Capteur de Proximité Ultrasonique** : Pour mesurer la distance.  
- **Capteur Sonore** : Pour analyser les niveaux sonores.
- **Buzzer** : Signal sonore pour alerter en cas d'erreurs de mot de passe ou d'intrusion.  
- **Boutons** : Pour interagir avec le système (valider, effacer).  
- **`Buzzer.h / Buzzer.cpp`** : Gestion du buzzer pour l'alarme sonore en cas de mot de passe incorrect après le troisième tentatif.

---

## Dépendances  
Le projet utilise les bibliothèques suivantes :  
- `Arduino.h`  
- `Wire.h`  
- `rgb_lcd.h`  
- `WiFi.h`  
- `PubSubClient.h`  
- `Ultrasonic.h`  

---
## Installation et Utilisation
### Étape 1: Clonez ce répertoire GitHub sur votre machine locale : 
´´´bash
git clone https://github.com/dcocoma/BE_Cpp_2024.git
### Étape 2: Installez les Dépendances
Assurez-vous d'avoir les bibliothèques suivantes installées :

rgb_lcd.h
Ultrasonic.h
PubSubClient.h (pour MQTT)

### Étape 3: Configurez le Wi-Fi et le Serveur MQTT
Dans le fichier main.cpp, configurez le nom de votre réseau Wi-Fi, votre mot de passe et l'adresse du serveur MQTT 

Mqtt mqtt("SSID", "Senha", "broker.emqx.io");

### Étape 4 : Compilez et Chargez le Code
Ouvrez le projet dans l'IDE Arduino.
Configurez la carte ESP8266 dans Outils > Carte > ESP8266.
Connectez votre ESP8266 à votre ordinateur et téléchargez le code.

---

## Étapes de Configuration Matérielle et Logicielle
### Étape 1 : Configuration Matérielle  
1. Connecter tous les composants selon le schéma électrique (à fournir).  
2. Charger le firmware sur la carte ESP8266 via Arduino IDE.  

### Étape 2 : Configuration Logicielle  
1. Modifier les identifiants WiFi et le serveur MQTT dans le code (`ssid`, `password`, `mqtt_server`).  
2. Installer les bibliothèques nécessaires dans l'IDE Arduino.  

### Étape 3 : Test et Fonctionnement  
1. Alimenter l'ESP8266.  
2. Utiliser les boutons et le potentiomètre pour interagir avec le système.  
3. Vérifier l'affichage et les retours sur le LCD et le serveur MQTT.  

---

## Structure du Code  

### Fichiers Principaux  
- **`Button.h / Button.cpp`** : Gestion des boutons physiques.  
- **`LCD.h / LCD.cpp`** : Contrôle de l’écran LCD RGB.  
- **`Mqtt.h / Mqtt.cpp`** : Gestion des connexions et messages MQTT.  
- **`Potenciometre.h / Potenciometre.cpp`** : Lecture des valeurs du potentiomètre.  
- **`Securite.h / Securite.cpp`** : Système de validation des mots de passe.  
- **`SenProx.h / SenProx.cpp`** : Gestion du capteur de proximité.  
- **`SenSon.h / SenSon.cpp`** : Gestion du capteur sonore.  

---

## Améliorations Futures  
- Ajouter une fonctionnalité pour changer le mot de passe dynamiquement via MQTT.  
- Intégrer un capteur PIR pour détecter les mouvements.  
  

---

## Auteur  
Développé par Giovanna Alves Carvalho Grigolon et Leonardo Cocoma dos Reyes. 😊  

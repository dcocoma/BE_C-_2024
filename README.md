# Système de Sécurité avec ESP8266

## Description du Projet  
Ce projet consiste à développer un **système de sécurité intelligent** utilisant la carte ESP8266. Il permet la gestion d'une alarme via un mot de passe sécurisé, avec des fonctionnalités interactives grâce à un potentiomètre, des boutons physiques, et un écran LCD RGB. Le système surveille l'environnement en utilisant des capteurs de **proximité** et de **son**, et communique avec un serveur **MQTT** pour permettre des notifications et des actions à distance. Ce système est conçu pour être extensible et permet de gérer des alertes en cas d'intrusion, avec des tentatives de mot de passe sécurisées et des retours visuels et sonores sur l'état de l'alarme.

---

## Fonctionnalités Principales  
1. **Affichage sur écran LCD RGB**  
   - Affichage des chiffres de 0 à 9 pour entrer le mot de passe.  
   - Position dynamique du curseur pour l'entrée des chiffres.  
   - Affichage d'un symbole spécial pour effacer le dernier chiffre saisi à la 15ème position de l'écran LCD.  
   - Messages affichés pour indiquer si l'alarme est activée, si un intrus a été détecté ou si le mot de passe a été correctement ou incorrectement saisi.
  
2. **Contrôle par Potentiomètre**  
   - Permet de sélectionner les chiffres à afficher sur le LCD pour entrer un mot de passe ou sélectionner des options.
  
3. **Boutons de Commande**  
   - Validation ou effacement des chiffres du mot de passe.
   - Bouton pour activer l'alarme.
  
4. **Capteurs Intégrés**  
   - **Capteur de Proximité (Ultrasonique)** : Mesure des distances en centimètres pour détecter les objets ou personnes proches du système.  
   - **Capteur Sonore** : Détecte l'intensité sonore en décibels, ce qui permet de surveiller l'environnement sonore et de déclencher des alertes en cas de bruit anormal.
  
5. **Gestion des Codes de Sécurité**  
   - Entrée et validation d’un mot de passe à 4 chiffres.  
   - Validation en temps réel du mot de passe avec indication si la tentative est réussie ou échouée.  
   - **Alarme sonore (Buzzer)** : Si trois tentatives incorrectes de mot de passe sont effectuées, un buzzer se déclenche pour signaler l'erreur et prévenir de l'intrusion.
  
6. **Connexion au Serveur MQTT**  
   - Envoi de messages texte et numériques à des canaux spécifiques sur un serveur MQTT.  
   - Réception et traitement des messages via des topics MQTT, permettant des interactions à distance avec le système.

---

## Matériel Utilisé  
- **ESP8266** : Microcontrôleur pour la gestion des fonctions du système, y compris la communication Wi-Fi et MQTT.  
- **Écran LCD RGB** : Affichage des informations telles que les chiffres du mot de passe et les messages d'état du système.  
- **Potentiomètre** : Utilisé pour sélectionner les chiffres à afficher sur le LCD.  
- **Capteur de Proximité Ultrasonique** : Permet de mesurer la distance et de détecter les objets ou personnes proches.  
- **Capteur Sonore** : Capte l'intensité sonore pour surveiller les niveaux sonores de l'environnement.  
- **Buzzer** : Alerte sonore en cas d'erreurs multiples du mot de passe ou d'intrusion détectée.  
- **Boutons** : Permettent d'interagir avec le système pour valider, effacer des chiffres ou activer/désactiver l'alarme.  

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
```bash
git clone https://github.com/dcocoma/BE_Cpp_2024.git
```

### Étape 2: Installez les Dépendances  
Assurez-vous d'avoir les bibliothèques suivantes installées dans votre environnement de développement :
- `rgb_lcd.h`
- `Ultrasonic.h`
- `PubSubClient.h` (pour la communication MQTT)

### Étape 3: Configurez le Wi-Fi et le Serveur MQTT  
Dans le fichier `main.cpp`, configurez les informations de connexion Wi-Fi et le serveur MQTT :
```cpp
Mqtt mqtt("SSID", "Senha", "broker.emqx.io");
```

### Étape 4: Installez Node-RED  
Pour utiliser la communication MQTT avec votre système, vous devez installer Node-RED. Suivez le tutoriel d'installation officiel de Node-RED ici :  
[Installation de Node-RED](https://nodered.org/docs/getting-started/local).

### Étape 5: Créez le Flow MQTT dans Node-RED  
1. Après avoir installé Node-RED, ouvrez-le dans votre navigateur en accédant à [http://localhost:1880/](http://localhost:1880/).  
2. Créez un **flow** en ajoutant des blocs pour recevoir et envoyer des données via MQTT. Vous pouvez suivre le tutoriel sur la création d'un premier flow ici :  
[Créer un premier flow dans Node-RED](https://nodered.org/docs/tutorials/first-flow).
3. Pour configurer un flux pour ce projet, vous pouvez soit le créer manuellement, soit importer le flow que nous avons créé. Le fichier à importer s'appelle `flows (7).json`.  
   - Allez dans **Menu > Importer** et sélectionnez le fichier `flows (7).json` que vous avez téléchargé.
   - Cliquez sur **Deploy** pour lancer le serveur de communication MQTT.
   
4. Après avoir cliqué sur **Deploy**, le serveur MQTT (broker.emqx.io) sera activé et permettra à tous les nœuds de communiquer via MQTT. Vous pouvez également ajouter des nœuds supplémentaires et les configurer avec différents ports si nécessaire.

### Étape 6: Créez et configurez les blocs MQTT dans Node-RED  
- Pour créer des blocs de réception et d'envoi de messages, utilisez les nœuds MQTT disponibles dans Node-RED.
- Ajoutez un nœud **MQTT in** pour recevoir des messages (par exemple, un mot de passe valide ou une alarme).
- Ajoutez un nœud **MQTT out** pour envoyer des messages (par exemple, la détection d'intrusion ou un changement d'état de l'alarme).
  
Les détails de la création de ces blocs sont bien expliqués dans le tutoriel que vous pouvez suivre à l'adresse mentionnée ci-dessus.


### Étape 7 : Compilez et Chargez le Code  
1. Ouvrez le projet dans l'IDE Arduino.  
2. Configurez la carte ESP8266 dans **Outils > Carte > ESP8266**.  
3. Connectez votre ESP8266 à votre ordinateur via USB et téléchargez le code.

---

## Étapes de Configuration Matérielle et Logicielle  
### Étape 1 : Configuration Matérielle  
1. Connectez tous les composants selon le schéma électrique (à fournir).  
2. Téléchargez le firmware sur la carte ESP8266 via Arduino IDE.

### Étape 2 : Configuration Logicielle  
1. Modifiez les identifiants Wi-Fi et l'adresse du serveur MQTT dans le code (`ssid`, `password`, `mqtt_server`).  
2. Installez les bibliothèques nécessaires dans l'IDE Arduino.

### Étape 3 : Test et Fonctionnement  
1. Alimentez la carte ESP8266.  
2. Utilisez les boutons et le potentiomètre pour interagir avec le système.  
3. Vérifiez l'affichage sur l'écran LCD et les messages reçus via MQTT.

---

## Structure du Code  

### Fichiers Principaux  
- **`Button.h / Button.cpp`** : Gestion des boutons physiques pour l'interaction avec le système.  
- **`LCD.h / LCD.cpp`** : Contrôle de l’affichage LCD RGB.  
- **`Mqtt.h / Mqtt.cpp`** : Gestion des connexions et de la communication MQTT.  
- **`Potenciometre.h / Potenciometre.cpp`** : Lecture des valeurs du potentiomètre pour sélectionner des options.  
- **`Securite.h / Securite.cpp`** : Système de validation des mots de passe et gestion des tentatives.  
- **`SenProx.h / SenProx.cpp`** : Gestion du capteur de proximité pour détecter des objets ou des intrusions.  
- **`SenSon.h / SenSon.cpp`** : Gestion du capteur sonore pour surveiller l'intensité sonore.

---

## Améliorations Futures  
- Ajouter une fonctionnalité pour changer dynamiquement le mot de passe via MQTT.  
- Intégrer un capteur PIR (Passive Infrared) pour détecter les mouvements.  
- Ajouter une fonctionnalité d'activation à distance de l'alarme via une application mobile.

---

## Auteurs
Développé par **Giovanna Alves Carvalho Grigolon** et **Cocoma Reyes David Leonardo**. 😊  

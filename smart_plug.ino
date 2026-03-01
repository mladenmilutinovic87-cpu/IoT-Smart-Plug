#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#define RELAY_PIN 16  // D0 pin za relej

// ===== WIFI PODACI =====
const char* ssid = "wrt304z";
const char* password = "telekomunikacije304z";

// ===== MQTT SERVER =====
const char* mqtt_server = "bbbf806f2ac34684abeb14a7de31d2d9.s1.eu.hivemq.cloud";
const int mqtt_port = 8883; // TLS port
const char* mqtt_username = "Light_Control";
const char* mqtt_password = "Sijalica123";
const char* topic = "mojdom/sijalica";

// ===== KLIJENTI =====
WiFiClientSecure espClient;
PubSubClient client(espClient);

// ===== CALLBACK FUNKCIJA =====
void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Poruka stigla na topic [");
  Serial.print(topic);
  Serial.print("]: ");
  Serial.println(message);

  if (message == "Light ON") {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Sijalica upaljena");
  } else if (message == "Light OFF") {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Sijalica ugašena");
  }
}

// ===== POVEZIVANJE NA WIFI =====
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Povezivanje na WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int tries = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    tries++;
    if (tries > 30) {
      Serial.println("\nNe mogu da se povezem na WiFi!");
      return;
    }
  }

  Serial.println("\nPovezan na WiFi!");
  Serial.print("IP adresa: ");
  Serial.println(WiFi.localIP());
}

// ===== POVEZIVANJE NA MQTT =====
void reconnect() {
  while (!client.connected()) {
    Serial.print("Povezivanje na MQTT...");
    if (client.connect("ESP8266_Sijalica", mqtt_username, mqtt_password)) {
      Serial.println("povezan");

      // Subscribe na topic
      if (client.subscribe(topic)) {
        Serial.print("Subscribovao na topic: ");
        Serial.println(topic);
      } else {
        Serial.println("Greska pri subscribe!");
      }

    } else {
      Serial.print("nije uspelo, rc=");
      Serial.print(client.state());
      Serial.println(" - pokušavam ponovo za 5 sekundi");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  Serial.begin(9600);
  setup_wifi();

  // HiveMQ Cloud TLS, brzo testiranje
  espClient.setInsecure();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
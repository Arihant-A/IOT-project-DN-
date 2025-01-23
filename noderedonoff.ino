#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include <PubSubClient.h>


#define LedPin      LED_BUILTIN  // NodeMCU onboard LED (D4 GPIO2)


// Wi-Fi and MQTT Broker details
const char* ssid = "LH";                      // Your Wi-Fi SSID
const char* password = "agarwal@18";           // Your Wi-Fi Password
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
    delay(10);
    Serial.println();
    Serial.print("Connecting to Wi-Fi: ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Wi-Fi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) 
{ 
    char msg = 0;
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("]: ");

    for (int i = 0; i < length; i++) 
    { 
        msg = (char)payload[i];
    }
    Serial.println(msg);
    
    if ('1' == msg) 
    { 
        digitalWrite(LedPin, LOW); // LOW to turn ON the LED for NodeMCU onboard LED
        client.publish("/testTopic", "led on");
    } 
    else if ('2' == msg) 
    { 
        digitalWrite(LedPin, HIGH); // HIGH to turn OFF the LED for NodeMCU onboard LED
        client.publish("/testTopic", "led off");
    }
}

void reconnect() {
    while (!client.connected()) {
        Serial.println("Attempting MQTT connection...");
        if (client.connect("ESPTestClient")) { // Connect with client ID
            Serial.println("MQTT connected");
            client.subscribe("/LedControl");
            client.publish("/testTopic", "Hello from NodeMCU!"); // Test message
        } else {
            Serial.print("MQTT connection failed, rc=");
            Serial.println(client.state());
            Serial.println("Retrying in 5 seconds...");
            delay(5000);
        }
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(LedPin, OUTPUT);
    digitalWrite(LedPin, HIGH); // Ensure LED is off initially
    setup_wifi();
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback);
}


void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
}


#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  
  // Reset the WiFi mode
  WiFi.mode(WIFI_OFF);        // Turn off WiFi initially
  delay(100);
  WiFi.mode(WIFI_STA);        // Set Wi-Fi mode to Station
  
  Serial.print("ESP8266 MAC Address: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
}

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "LH";   // Your Network SSID
const char* password = "@18";       // Your Network Password

int val;
int pin = A0; 

WiFiClient client;

unsigned long myChannelNumber = *******; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "****************"; //Your Write API Key

void setup()
{
  Serial.begin(115200);
  delay(10);
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
  pinMode(2, OUTPUT);
}

void loop()
{
  val = analogRead(pin); // Read Analog values and Store in val variable
  Serial.print("Value: ");
  Serial.print(val);                 // Print on Serial Monitor
  delay(1000);
  ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
}

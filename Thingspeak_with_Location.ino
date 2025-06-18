#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "LH";   // Your Network SSID
const char* password = "@18";       // Your Network Password

// Define RX and TX pins for GPS module
static const int RXPin = D7;  // GPIO13 (D7) for RX
static const int TXPin = D8;  // GPIO15 (D8) for TX
static const uint32_t GPSBaud = 9600;

WiFiClient client;
// The TinyGPSPlus object
TinyGPSPlus gps;
unsigned long myChannelNumber = *******; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "****************"; //Your Write API Key

// Use SoftwareSerial for GPS communication
SoftwareSerial SerialGPS(RXPin, TXPin);

void setup() {
  Serial.begin(115200); // Serial monitor
  SerialGPS.begin(GPSBaud); // GPS module communication
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);

  Serial.println(F("GPS Module with ESP8266"));
}

void loop() {
  while (SerialGPS.available()) {
    gps.encode(SerialGPS.read());
  }

  if (gps.location.isUpdated()) {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
    float latitude = (float)gps.location.lat();
    float longitude = (float)gps.location.lng();

    // Update ThingSpeak
    ThingSpeak.writeField(myChannelNumber, 3, latitude, myWriteAPIKey);
    ThingSpeak.writeField(myChannelNumber, 3, longitude, myWriteAPIKey);


  }
}

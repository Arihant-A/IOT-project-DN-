#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

// Define RX and TX pins for GPS module
static const int RXPin = D7;  // GPIO13 (D7) for RX
static const int TXPin = D8;  // GPIO15 (D8) for TX
static const uint32_t GPSBaud = 9600;

// The TinyGPSPlus object
TinyGPSPlus gps;

// Use SoftwareSerial for GPS communication
SoftwareSerial SerialGPS(RXPin, TXPin);

void setup() {
  Serial.begin(115200); // Serial monitor
  SerialGPS.begin(GPSBaud); // GPS module communication

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
  }
}

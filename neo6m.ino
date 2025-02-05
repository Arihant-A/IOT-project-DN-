#include <SoftwareSerial.h>
#include <TinyGPS++.h>  // Library for GPS parsing

#define RX_PIN D7  // GPS TX
#define TX_PIN D8  // GPS RX
#define GPS_BAUD 9600

SoftwareSerial gpsSerial(RX_PIN, TX_PIN);
TinyGPSPlus gps;

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(GPS_BAUD);
  Serial.println("GPS Module Initialized");
}

void loop() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());

    if (gps.location.isUpdated()) {
      Serial.print("Latitude: "); Serial.println(gps.location.lat(), 6);
      Serial.print("Longitude: "); Serial.println(gps.location.lng(), 6);
      Serial.print("Satellites: "); Serial.println(gps.satellites.value());
      Serial.print("HDOP (Accuracy): "); Serial.println(gps.hdop.hdop()-100);
      Serial.println("-------------------------");
    }
  }
} 


#include <Wire.h>
#include <VL53L0X.h>

// Create an instance of the VL53L0X sensor
VL53L0X sensor;
void setup() {
  Serial.begin(115200);
  delay(100); // Allow time for serial monitor to connect
  
  // Initialize I²C with custom pins
  Wire.begin(4, 5); // SDA = GPIO4, SCL = GPIO5

  // Initialize the sensor
  if (!sensor.init()) {
    Serial.println("Failed to initialize VL53L0X! Check your wiring.");
    while (1);
  }
  
  // Set measurement timing budget (optional)
  sensor.setTimeout(1000);
  sensor.setMeasurementTimingBudget(200000); // 200ms timing budget
  
  Serial.println("VL53L0X initialized successfully!");
}

void loop() {
  // Read distance in millimeters
  uint16_t distance = sensor.readRangeSingleMillimeters();

  // Check for out-of-range or timeout
  if (sensor.timeoutOccurred()) {
    Serial.println("Sensor timeout!");
  } else {
    Serial.print("Distance (mm): ");
    Serial.println(distance);
  }
  
  delay(100); // Delay for readability
}

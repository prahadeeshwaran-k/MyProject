#include "PowerMonitor.h"

PowerMonitor monitor(36, 2.864);

void setup() {
  monitor.begin();
}

void loop() {
  String sensor_1 = monitor.update();
  Serial.print("Sensor 1 main loop: ");
  Serial.println(sensor_1);
  vTaskDelay(1000); // Add a delay to avoid flooding the serial output
}

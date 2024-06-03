#include "PowerMonitor.h"

PowerMonitor::PowerMonitor(int pin, double calibration) : _pin(pin), _calibration(calibration) {}

void PowerMonitor::begin() {
    Serial.begin(115200);
    _emon.current(_pin, _calibration);
}

String PowerMonitor::update() {
    double Irms = _emon.calcIrms(1480);  // Calculate Irms only
    float W = Irms * 220.0;              // Calculate apparent power
    
    char buffer[80];
    sprintf(buffer, "W: %.2f I: %.2f", W, Irms);
    Serial.println(buffer);

    char temp_jsonI[10];
    dtostrf(Irms, 3, 2, temp_jsonI);

    char temp_jsonW[10];
    dtostrf(W, 3, 2, temp_jsonW);

    StaticJsonDocument<100> doc;
    char output[100];
    doc["W"] = temp_jsonW;
    doc["I"] = temp_jsonI;
    serializeJson(doc, output);
    Serial.println(output);

    return output;

}

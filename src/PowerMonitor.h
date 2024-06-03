#ifndef POWERMONITOR_H
#define POWERMONITOR_H

#include <Arduino.h>
#include "EmonLib.h"             // Include Emon Library
#include "ArduinoJson.h"

class PowerMonitor {
public:
    PowerMonitor(int pin, double calibration);
    void begin();
    String update();
private:
    int _pin;
    double _calibration;
    EnergyMonitor _emon;
};

#endif // POWERMONITOR_H

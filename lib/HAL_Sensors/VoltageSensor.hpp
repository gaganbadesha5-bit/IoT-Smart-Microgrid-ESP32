#pragma once
#include <Arduino.h>

class VoltageSensor {
private:
    uint8_t _pin;
    float _r1;
    float _r2;
    float _referenceVoltage;

public:
    VoltageSensor(uint8_t pin, float r1 = 30000.0f, float r2 = 7500.0f, float refVoltage = 3.3f);
    void begin();
    float readVoltage();
};
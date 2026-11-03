#pragma once
#include <Arduino.h>

class TemperatureSensor {
private:
    uint8_t _pin;
    float   _refVoltage;

public:
    TemperatureSensor(uint8_t pin, float refVoltage = 3.3f);
    void begin();
    float readTemperatureC();
};
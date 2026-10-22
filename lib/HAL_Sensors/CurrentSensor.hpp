#pragma once 
#include <Arduino.h>

class CurrentSensor {
private:
    uint8_t _pin;
    float   _sensitivity;
    float   _zeroCurrentVoltage;
    float   _refVoltage;
    public:
    CurrentSensor(uint8_t pin, float sensitivity = 0.185f, float refVoltage = 3.3f);
    void begin();
    void calibrateZeroPoint(uint8_t sampleCount = 50);
    float readCurrent();
};
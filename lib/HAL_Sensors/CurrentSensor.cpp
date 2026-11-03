#include "CurrentSensor.hpp"

CurrentSensor::CurrentSensor(uint8_t pin, float sensitivity, float refVoltage)
    : _pin(pin), _sensitivity(sensitivity), _zeroCurrentVoltage(1.65f), _refVoltage(refVoltage) {
}

void CurrentSensor::begin() {
    pinMode(_pin, INPUT);
}
void CurrentSensor::calibrateZeroPoint(uint8_t sampleCount) {
    uint32_t totalRaw = 0;

    for (uint8_t i = 0; i < sampleCount; i++) {
        totalRaw += analogRead(_pin);
        delay(5);
    }

    float averageRaw = (float)totalRaw / (float)sampleCount;
    _zeroCurrentVoltage = (averageRaw / 4095.0f) * _refVoltage;
}
float CurrentSensor::readCurrent() {
    uint32_t totalRaw = 0;
    const uint8_t samples = 15;

    for (uint8_t i = 0; i < samples; i++) {
        totalRaw += analogRead(_pin);
        delayMicroseconds(100);
    }
    float averageRaw = (float)totalRaw / (float)samples;
    float pinVoltage = (averageRaw / 4095.0f) * _refVoltage;
    float currentAmps = (pinVoltage - _zeroCurrentVoltage) / _sensitivity;

    return currentAmps;
}
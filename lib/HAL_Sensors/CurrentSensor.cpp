#include "CurrentSensor.hpp"
#include <math.h>

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
    const uint32_t sampleWindowUs = 40000; // 40ms = 2 full 50Hz AC cycles
    uint32_t startMicros = micros();
    uint32_t sampleCount = 0;
    float sumSquared = 0.0f;

    while ((micros() - startMicros) < sampleWindowUs) {
        float pinVoltage = ((float)analogRead(_pin) / 4095.0f) * _refVoltage;
        float instCurrent = (pinVoltage - _zeroCurrentVoltage) / _sensitivity;
        sumSquared += (instCurrent * instCurrent);
        sampleCount++;
        delayMicroseconds(200);
    }

    if (sampleCount == 0) return 0.0f;

    float rmsCurrent = sqrtf(sumSquared / (float)sampleCount);
    return (rmsCurrent < 0.08f) ? 0.0f : rmsCurrent;
}
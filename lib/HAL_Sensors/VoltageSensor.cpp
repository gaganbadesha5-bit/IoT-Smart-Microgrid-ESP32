#include "VoltageSensor.hpp"

VoltageSensor::VoltageSensor(uint8_t pin, float r1, float r2, float refVoltage)
    : _pin(pin), _r1(r1), _r2(r2), _referenceVoltage(refVoltage) {
}
void VoltageSensor::begin() {
    pinMode(_pin, INPUT);
}
float VoltageSensor::readVoltage() {
    uint32_t totalRaw = 0;
    const uint8_t samples = 10;

    for (uint8_t i = 0; i < samples; i++) {
        totalRaw += analogRead(_pin);
        delayMicroseconds(100);
    }

    float averageRaw = (float)totalRaw / (float)samples;
    float pinVoltage = (averageRaw / 4095.0f) * _referenceVoltage;
    float actualVoltage = pinVoltage * ((_r1 + _r2) / _r2);

    return actualVoltage;
}
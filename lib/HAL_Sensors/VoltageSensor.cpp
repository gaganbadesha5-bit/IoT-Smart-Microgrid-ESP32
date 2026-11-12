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
float VoltageSensor::readACVoltageRMS() {
    const uint32_t sampleWindowUs = 40000; // 40ms window for 50Hz AC
    uint32_t startMicros = micros();
    uint32_t sampleCount = 0;
    float sumSquared = 0.0f;
    const float midPoint = _referenceVoltage / 2.0f; // ~1.65V DC bias

    while ((micros() - startMicros) < sampleWindowUs) {
        float pinVoltage = ((float)analogRead(_pin) / 4095.0f) * _referenceVoltage;
        float acInst = pinVoltage - midPoint;
        sumSquared += (acInst * acInst);
        sampleCount++;
        delayMicroseconds(200);
    }

    if (sampleCount == 0) return 0.0f;

    float vRms = sqrtf(sumSquared / (float)sampleCount) * _acCalibration;
    return (vRms < 15.0f) ? 0.0f : vRms;
}
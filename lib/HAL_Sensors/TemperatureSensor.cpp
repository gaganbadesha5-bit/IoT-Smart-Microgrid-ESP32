#include "TemperatureSensor.hpp"

TemperatureSensor::TemperatureSensor(uint8_t pin, float refVoltage)
    : _pin(pin), _refVoltage(refVoltage) {
}

void TemperatureSensor::begin() {
    pinMode(_pin, INPUT);
}

float TemperatureSensor::readTemperatureC() {
    uint32_t totalRaw = 0;
    const uint8_t samples = 10;

    for (uint8_t i = 0; i < samples; i++) {
        totalRaw += analogRead(_pin);
        delayMicroseconds(100);
    }

    float averageRaw = (float)totalRaw / (float)samples;
    float pinVoltage = (averageRaw / 4095.0f) * _refVoltage;

    // LM35 outputs 10mV (0.01V) per degree Celsius
    float tempC = pinVoltage * 100.0f;

    return tempC;
}
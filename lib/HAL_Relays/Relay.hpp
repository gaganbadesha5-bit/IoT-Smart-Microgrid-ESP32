#pragma once
#include <Arduino.h>

class Relay {
private:
    uint8_t _pin;
    bool _isActiveLow;
    bool _currentState;
public:
    Relay(uint8_t pin, bool isActiveLow = true);
    void begin();
    void turnOn();
    void turnOff();
    bool isOn();
};
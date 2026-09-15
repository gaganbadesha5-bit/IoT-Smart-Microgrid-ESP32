#include "Relay.hpp"

Relay::Relay(uint8_t pin, bool isActiveLow)
    : _pin(pin), _isActiveLow(isActiveLow), _currentState(false) {
}

void Relay::begin() {
    pinMode(_pin, OUTPUT);
    turnOff();
}

void Relay::turnOn() {
    if (_isActiveLow) {
        digitalWrite(_pin, LOW);
    } else {
        digitalWrite(_pin, HIGH);
    }
    _currentState = true;
}

void Relay::turnOff() {
    if (_isActiveLow) {
        digitalWrite(_pin, HIGH);
    } else {
        digitalWrite(_pin, LOW);
    }
    _currentState = false;
}

bool Relay::isOn() {
    return _currentState;
}
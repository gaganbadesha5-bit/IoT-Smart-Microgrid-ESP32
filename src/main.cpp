#include <Arduino.h>
#include "Config.hpp"
#include "Relay.hpp"

Relay solarRelay(Config::Relays::SOLAR_INVERTER, Config::Relays::IS_ACTIVE_LOW);
    void setup() {
    Serial.begin(115200);
    solarRelay.begin();
    Serial.println("Microgrid Relay Initialized.");
}

void loop() {
    Serial.println("Switching Solar Inverter ON...");
    solarRelay.turnOn();
    delay(2000);

    Serial.println("Switching Solar Inverter OFF...");
    solarRelay.turnOff();
    delay(2000);
}
#include <Arduino.h>
#include "Config.hpp"
#include "Relay.hpp"
#include "VoltageSensor.hpp"

Relay solarRelay(Config::Relays::SOLAR_INVERTER, Config::Relays::IS_ACTIVE_LOW);
VoltageSensor batterySensor(Config::Sensors::BATTERY_VOLTAGE_PIN);

void setup() {
    Serial.begin(115200);
    solarRelay.begin();
    batterySensor.begin();
    Serial.println("System Initialized.");
}

void loop() {
    float voltage = batterySensor.readVoltage();
    Serial.print("Battery Voltage: ");
    Serial.print(voltage);
    Serial.println(" V");

    delay(1000);
}
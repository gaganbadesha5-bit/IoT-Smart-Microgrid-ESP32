#include <Arduino.h>
#include "Config.hpp"
#include "Relay.hpp"
#include "VoltageSensor.hpp"
#include "CurrentSensor.hpp"

// Hardware instances
Relay solarRelay(Config::Relays::SOLAR_INVERTER, Config::Relays::IS_ACTIVE_LOW);
VoltageSensor batterySensor(Config::Sensors::BATTERY_VOLTAGE_PIN);
CurrentSensor loadCurrentSensor(
    Config::Sensors::LOAD_CURRENT_PIN,
    Config::Sensors::ACS712_30A_SENSITIVITY,
    Config::Sensors::ADC_REF_VOLTAGE
);

void setup() {
    Serial.begin(115200);

    solarRelay.begin();
    batterySensor.begin();
    loadCurrentSensor.begin();

    Serial.println("Calibrating Current Sensor zero point (no load)...");
    loadCurrentSensor.calibrateZeroPoint();
    Serial.println("Sensors ready!");
}

void loop() {
    float vBatt = batterySensor.readVoltage();
    float iLoad = loadCurrentSensor.readCurrent();

    Serial.print("Battery: ");
    Serial.print(vBatt, 2);
    Serial.print(" V  |  Load Current: ");
    Serial.print(iLoad, 2);
    Serial.println(" A");

    delay(1000);
}
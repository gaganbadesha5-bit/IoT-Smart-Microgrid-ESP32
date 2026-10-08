#pragma once
#include <Arduino.h>
#include "SystemStates.hpp"

struct MicrogridTelemetry {

    float solarVoltage;
    float solarCurrent;
    float batteryVoltage;
    float loadCurrent;

    bool isGridAvailable;
    bool isSolarAvailable;
    PowerSourceMode activeMode;
    SystemHealth healthStatus;
};
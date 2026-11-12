#pragma once
#include <Arduino.h>
#include "SystemStates.hpp"

struct MicrogridTelemetry {

    float batteryVoltage;
    float gridVoltage;
    float genVoltage;
    float loadCurrent;
    float panelTempC;

    bool isGridAvailable;
    bool isSolarAvailable;
    bool isGenAvailable;
    PowerSourceMode activeMode;
    SystemHealth healthStatus;
};
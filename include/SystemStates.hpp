#pragma once
#include <Arduino.h>

enum class PowerSourceMode : uint8_t {
    ALL_OFF = 0,
    MAINS_GRID,
    SOLAR_PRIORITY,
    GENERATOR,
    AUTO
};
enum class SystemHealth : uint8_t {
    NORMAL,
    LOW_BATTERY,
    OVERLOAD,
    EMERGENCY_SHUTDOWN
};

inline const char* toString(PowerSourceMode mode) {
    switch (mode) {
        case PowerSourceMode::ALL_OFF:        return "ALL_OFF";
        case PowerSourceMode::MAINS_GRID:     return "MAINS_GRID";
        case PowerSourceMode::SOLAR_PRIORITY: return "SOLAR_PRIORITY";
        case PowerSourceMode::GENERATOR:      return "GENERATOR";
        case PowerSourceMode::AUTO:           return "AUTO";
        default:                              return "UNKNOWN";
    }
}

inline const char* toString(SystemHealth health) {
    switch (health) {
        case SystemHealth::NORMAL:             return "NORMAL";
        case SystemHealth::LOW_BATTERY:        return "LOW_BATTERY";
        case SystemHealth::OVERLOAD:           return "OVERLOAD";
        case SystemHealth::EMERGENCY_SHUTDOWN: return "EMERGENCY_SHUTDOWN";
        default:                               return "UNKNOWN";
    }
}
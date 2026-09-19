#pragma once
#include <Arduino.h>
namespace Config {
    namespace Relays {
        
        constexpr uint8_t SOLAR_INVERTER   = 18;
        constexpr uint8_t GRID_TIE         = 19;
        constexpr uint8_t BATTERY_LOAD     = 21;
        constexpr uint8_t CRITICAL_LOAD    = 22;

       
        constexpr bool IS_ACTIVE_LOW = true;
    }
}
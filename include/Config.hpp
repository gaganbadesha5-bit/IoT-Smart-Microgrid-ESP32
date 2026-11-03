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
    namespace Sensors {
    constexpr uint8_t BATTERY_VOLTAGE_PIN    = 34;
    constexpr uint8_t LOAD_CURRENT_PIN       = 35;
    constexpr uint8_t AMBIENT_TEMP_PIN       = 36;
    
    constexpr float   ADC_REF_VOLTAGE        = 3.3f;
    constexpr float   ACS712_30A_SENSITIVITY = 0.066f;
}
}
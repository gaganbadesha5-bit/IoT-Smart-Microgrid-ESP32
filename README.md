# IoT-Enabled Smart Microgrid Source Selector (ESP32)

## Project Overview
An automated microgrid source selection and emergency protection system designed around the ESP32 microcontroller. The system monitors AC voltage via a ZMPT101B sensor, manages automatic changeover between Grid Power and an Auxiliary Generator, and features fault isolation logic with Blynk cloud telemetry.

> **Note:** This repository currently contains system architecture documentation and AutoCAD Electrical schematics. Custom C++ firmware modules are actively being written and tested.

---

## Hardware Stack
- **Microcontroller:** ESP32 (32-bit dual-core Wi-Fi/BLE)
- **Voltage Sensing:** ZMPT101B AC Voltage Sensor Module
- **Switching Control:** 4-Channel 5V Optocoupler Relay Module
- **Documentation:** AutoCAD Electrical Single-Line Schematics

---

## System Documentation
- Schematic Diagram: [`01_SLD_Power_Distribution-Model..pdf`](./01_SLD_Power_Distribution-Model..pdf) 

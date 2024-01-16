/*
    * PressureMonitoring.h
    *
    *  Created on: 15.06.2017
    * 
    * Creating a class for the pressure monitoring system
    * It will be using MPX5010DP pressure sensor
    * Will have three functions:
        * readPlantPressure()
        * readICUPressure()
        * readWardPressure()
    
    * The constructor will initialize the 3 analogue pins for the pressure sensor on the esp32 NodeMCU-32S board pins 33, 32, 35
    * set resolution to 12 bits (0-4095) which will be used to map the pressure range from 0-50kPa
    * Reading the pressure from Plant Pressure Chamber
    * Reading the pressure from the ICU Pressure Chamber
    * Reading the pressure from the Ward Pressure Chamber

*/

#ifndef PRESSUREMONITORING_H
#define PRESSUREMONITORING_H

#include <Arduino.h>

class PressureMonitor {
    private:
        int pinPlantPressure;
        int pinICUPressure;
        int pinWardPressure;
    public:
        PressureMonitor(int pinPlantPressure, int pinICUPressure, int pinWardPressure);
        float readPlantPressure();
        float readICUPressure();
        float readWardPressure();
        ~PressureMonitor();
};


#endif
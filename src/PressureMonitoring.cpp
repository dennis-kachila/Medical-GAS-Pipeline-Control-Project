/*  
    *Implementing of the PressureMonitoring.h header file
    * 
    * 
*/

#include <Arduino.h>
#include "PressureMonitoring.h"

/**
 * @brief Constructor for the PressureMonitor class.
 * 
 * @param pinPlantPressure The pin number to which the plant pressure sensor is connected.
 * @param pinICUPressure The pin number to which the ICU pressure sensor is connected.
 * @param pinWardPressure The pin number to which the ward pressure sensor is connected.
 */

PressureMonitor::PressureMonitor(int pinPlantPressure, int pinICUPressure, int pinWardPressure) {
    this->pinPlantPressure = pinPlantPressure;
    this->pinICUPressure = pinICUPressure;
    this->pinWardPressure = pinWardPressure;
    // set resolution to 12 bits (0-4095)
    analogReadResolution(12);
}

/**
 * Reads the pressure from the plant pressure chamber.
 * 
 * @return The pressure in the plant pressure chamber.
 */
float PressureMonitor::readPlantPressure() {
    // read the input on analog pin 0:
    float sensorValue = analogRead(this->pinPlantPressure);
    //values in milliVolts (analogue read in analogReadMilliVolts())
    float sensorValue2 = analogReadMilliVolts(this->pinPlantPressure);

    // map the sensor value from 0-4095 to 0-50kPa
    float pressure = map(sensorValue, 0, 4095, 0, 50);

    // print out the value you read:
    /*
    Serial.print("Plant Pressure: ");  
    Serial.print(sensorValue,2);
    Serial.println(" Pa");
    Serial.print("Plant Pressure(mv): ");
    Serial.println(sensorValue2,2);
    */
   
return pressure;
    //returns sensorValue
}

/**
 * Reads the pressure from the ICU pressure chamber.
 * 
 * @return The pressure in the ICU pressure chamber.
 */
float PressureMonitor::readICUPressure() {
    // read the input on analog pin 0:
    float sensorValue = analogRead(this->pinICUPressure);
    //values in milliVolts (analogue read in analogReadMilliVolts())
    float sensorValue2 = analogReadMilliVolts(this->pinICUPressure);

    // map the sensor value from 0-4095 to 0-50kPa
    float pressure = map(sensorValue, 0, 4095, 0, 50);
    // print out the value you read:
    /*
    Serial.print("ICU Pressure: ");  
    Serial.print(sensorValue,2);
    Serial.println(" Pa");
    Serial.print("ICU Pressure(mv): ");
    Serial.println(sensorValue2,2);
    */
return pressure;
    //returns sensorValue2
}

/**
 * Reads the pressure from the ward pressure chamber.
 * 
 * @return The pressure in the ward pressure chamber.
 */
float PressureMonitor::readWardPressure() {
    // read the input on analog pin 0:
    float sensorValue = analogRead(this->pinWardPressure);
    //values in milliVolts (analogue read in analogReadMilliVolts())
    float sensorValue2 = analogReadMilliVolts(this->pinWardPressure);

    // map the sensor value from 0-4095 to 0-50kPa
    float pressure = map(sensorValue, 0, 4095, 0, 50);
    // print out the value you read:
    /*
    Serial.print("Ward Pressure: ");  
    Serial.print(sensorValue,2);
    Serial.println(" Pa");
    Serial.print("Ward Pressure(mv): ");
    Serial.println(sensorValue2,2);
    */
return pressure;
    //returns sensorValue2
}

/**
 * @brief Destructor for the PressureMonitor class.
 * 
 * This destructor does not do anything.
 */
PressureMonitor::~PressureMonitor() {
        
    }




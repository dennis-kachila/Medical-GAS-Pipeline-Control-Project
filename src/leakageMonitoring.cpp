/*
    * leakageMonitoring.cpp
    * Implementing of the leakageMonitoring.h header file
    *
*/

#include <Arduino.h>
#include "leakageMonitoring.h"

/**
 * @brief Constructor for the LeakageMonitor class.
 * 
 * @param pinCornerA The pin number to which the microphone amplifier is connected at corner A.
 * @param pinCornerB The pin number to which the microphone amplifier is connected at corner B.
 */
LeakageMonitor::LeakageMonitor(int pinCornerA, int pinCornerB) {
    this->pinCornerA = pinCornerA;
    this->pinCornerB = pinCornerB;
    // set resolution to 12 bits (0-4095)
    analogReadResolution(12);
}

/**
 * Reads the sound from the microphone amplifier at corner A.
 * 
 * Performs a frequency analysis and compares it with the threshold value.
 * @return The sound from the microphone amplifier at corner A.
 */
float LeakageMonitor::readLeakageCornerA() {
    // read the input on analog pin 0:
    float sensorMicValue = analogRead(this->pinCornerA);
    //values in milliVolts (analogue read in analogReadMilliVolts())
    float sensorMicValue2 = analogReadMilliVolts(this->pinCornerA);
    // convert the milliVolts to dB
    float sensorMicValue3 = 20 * log10(sensorMicValue2);
    // print out the value you read:
    Serial.println(sensorMicValue);
    Serial.println(sensorMicValue2);
    Serial.println(sensorMicValue3);
    return sensorMicValue3;
}

/**
 * Reads the sound from the microphone amplifier at corner B.
 * 
 * Performs a frequency analysis and compares it with the threshold value.
 * @return The sound from the microphone amplifier at corner B.
 */
float LeakageMonitor::readLeakageCornerB() {
    // read the input on analog pin 0:
    float sensorMicValue = analogRead(this->pinCornerB);
    //values in milliVolts (analogue read in analogReadMilliVolts())
    float sensorMicValue2 = analogReadMilliVolts(this->pinCornerB);
    // convert the milliVolts to dB
    float sensorMicValue3 = 20 * log10(sensorMicValue2);
    // print out the value you read:
    Serial.println(sensorMicValue);
    Serial.println(sensorMicValue2);
    Serial.println(sensorMicValue3);
    return sensorMicValue3;
}

/**
 * @brief Destructor for the LeakageMonitor class.
 * 
 */
LeakageMonitor::~LeakageMonitor() {
    // nothing to destruct
}



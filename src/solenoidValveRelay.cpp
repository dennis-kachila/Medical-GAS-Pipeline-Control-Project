/*
    * solenoidValveRelay.cpp
    * implements solenoidValveRelay.h
    * 
    
*/

#include <Arduino.h>
#include "solenoidValveRelay.h"

/**
 * @brief Constructor for the SolenoidValveRelay class.
 * 
 * @param pin The pin number to which the solenoid valve is connected.
 */
SolenoidValveRelay::SolenoidValveRelay(int pin) {
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, HIGH); // turn off the relay by default
}

/**
 * Turns on the solenoid valve relay.
 */

void SolenoidValveRelay::turnOnSolenoidValveRelay() {
    digitalWrite(this->pin, LOW);
}

/**
 * Turns off the solenoid valve relay.
 */
void SolenoidValveRelay::turnOffSolenoidValveRelay() {
    digitalWrite(this->pin, HIGH);
}

/**
 * @brief Destructor for the SolenoidValveRelay class.
 * 
 * This destructor does not do anything.
 */
SolenoidValveRelay::~SolenoidValveRelay() {
        
    }

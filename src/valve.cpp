#include "valve.h"

/**
 * @brief Constructor for the Valve class.
 * 
 * @param pin The pin number to which the valve is connected.
 */
Valve::Valve(int pin) {
    this->pin = pin;
    this->servoValve.attach(this->pin, 500, 2400);
}

/**
 * Opens the valve by incrementally increasing the position of the servo motor.
 * Opening the valve is done by increasing the position of the servo motor from 0 to 90 degrees.
 */
void Valve::open() {
    // opening incrementally
    for (int pos = 0; pos <90; pos++) {
        this->servoValve.write(pos);
        delay(15);
    }
}

/**
 * Closes the valve by incrementally decreasing the position of the servo motor.
 * Closing the valve is done by decreasing the position of the servo motor from 90 to 0 degrees.
 */
void Valve::close() {
    // closing incrementally
    for (int pos = 90; pos >= 0; pos--) {
        this->servoValve.write(pos);
        delay(15);
    }
}

/**
 * @brief Destructor for the Valve class.
 * 
 * This destructor is responsible for detaching the servo valve.
 */
Valve::~Valve() {
//    this->servoValve.detach();
// it does nothing
}


// Path: src/valve.h
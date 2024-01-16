#ifndef VALVE_H
#define VALVE_H

#include<Arduino.h>
#include<ESP32Servo.h>

/*
*class definition for the valve
*it has two functions: open and close
*this will be used to control 3 valves
*the only difference between the valves is the pin number
*
*The PWM pin used for the 3 servoS are GPIO 26, 27, 14 on EPS32 NodeMCU

*/

class Valve {
    private:
        int pin;
        Servo servoValve;
    public:
        Valve(int pin); // constructor
        ~Valve(); // destructor
        void open(); // open the valve 
        void close();
};

#endif


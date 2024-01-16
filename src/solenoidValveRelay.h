/*
    * This will be used to control the solenoid valve relay
    * The relay will be connected to the GPIO pin 25
    * It will have two functions:
        * turnOnSolenoidValveRelay()
        * turnOffSolenoidValveRelay()
*/

#ifndef SOLENOIDVALVERELAY_H
#define SOLENOIDVALVERELAY_H

// create the class, which will have two functions, one to turn on the relay and one to turn it off/
// the constructor will initialize the pin mode to output

class SolenoidValveRelay {
    private:
        int pin;
    public:
        SolenoidValveRelay(int pin);
        
        void turnOnSolenoidValveRelay();
        void turnOffSolenoidValveRelay();
        ~SolenoidValveRelay();
};

#endif


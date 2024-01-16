/*
    * leakageMonitoring.h
    *
    *  Created on: 2021-04-10
    * 
    * 
    * Creating a class for the gas leakage monitoring system
    * It will be using Electret Microphone Amplifier - MAX4466 with Adjustable Gain
    * It will have two functions:
        * readLeakageCornerA()
        * readLeakageCornerB()
    *    
    
    * The constructor will initialize the 2 analogue pins for th microphone amplifier on the esp32 NodeMCU-32S board pins for corner A = 35 and corner B = 32
    * set resolution to 12 bits (0-4095)which will be used to detect the sound from the microphone and do a frequency analysis and compare it with the threshold value
    * Reading the sound from the microphone amplifier at corner A
    * Reading the sound from the microphone amplifier at corner B
    * 
*/

#ifndef LEAKAGEMONITORING_H
#define LEAKAGEMONITORING_H

#include <Arduino.h>
// include arduino fft library
#include <arduinoFFT.h>

class LeakageMonitor {
    private:
        int pinCornerA;
        int pinCornerB;

    public:
        LeakageMonitor(int pinCornerA, int pinCornerB);
        float readLeakageCornerA();
        float readLeakageCornerB();
        ~LeakageMonitor();
};


#endif



/* 
    * File:   I2C_LCDdisplay.h
    *Create a class for the I2C LCD display
    * This class will have the following functions:
    *   1. Prints the welcoming message (Welcome to VENERA Medical Gas System, KAHAWA GENERAL REFERRAL HOSPITAL) the message should automatically scroll
    *   2. display the current status of the system ( System is Working Normal)
    *   3. Prints the Pressure values for the three pressure sensors, i.e Plant Pressure, ICU Pressure and Ward Pressure and it should automatically scroll, the function should accept three values if not given it should print 0
    *   4. Prints the current status of the three valves, i.e Open or Closed for Valve A(Inlet), Valve B(ICU) and Valve C(Ward), it should accept three boolean values if not given it should print Closed for all valves.
    *  5. Prints the alarm message when there is a leak in the system, i.e Leak Detected, so it accepts  boolean value, if not given it should print No Leak Detected
    * Will have a constructor and destructor
    * Define the #define I2C_ADDR    0x27, #define LCD_COLUMNS 16, #define LCD_LINES   2 to be used in the constructor
    * constructor will initialize the I2C LCD display
    * destructor will clear the display
    * 
  */

#ifndef I2C_LCDdisplay_H
#define I2C_LCDdisplay_H

/*
  Testing the LCD display class
*/
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 16
#define LCD_LINES   2


LiquidCrystal_I2C lcd_i2c1(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
  



/*
* Prints the welcoming message (Welcome to VENERA Medical Gas System, KAHAWA GENERAL REFERRAL HOSPITAL) the message should automatically scroll
*/
void printWelcomeMessage() {
    lcd_i2c1.clear();
    lcd_i2c1.setCursor(0, 0);
    lcd_i2c1.print("Welcome to VENERA");
    lcd_i2c1.setCursor(0, 1);
    lcd_i2c1.print("Medical Gas System");
    delay(500);
    lcd_i2c1.scrollDisplayLeft();
    delay(500);
    lcd_i2c1.scrollDisplayLeft();
    delay(500);
    lcd_i2c1.scrollDisplayLeft();
    delay(500);
    lcd_i2c1.scrollDisplayLeft();
    delay(500);
    lcd_i2c1.scrollDisplayLeft();
    delay(500);

    lcd_i2c1.clear();
    lcd_i2c1.setCursor(0, 0);
    lcd_i2c1.print("KAHAWA GENERAL");
    lcd_i2c1.setCursor(0, 1);
    lcd_i2c1.print("HOSPITAL");
    delay(2000);
}


void printSystemStatus() {
    lcd_i2c1.clear();
    lcd_i2c1.setCursor(0, 0);
    lcd_i2c1.print("System is Working");
    lcd_i2c1.setCursor(0, 1);
    lcd_i2c1.print("Normal");
    delay(500);
    lcd_i2c1.scrollDisplayLeft();
}

/*
* Prints the Pressure values for the three pressure sensors, i.e Plant Pressure, ICU Pressure and Ward Pressure and it should automatically scroll, the function should accept three values if not given it should print 0
*/

void printPressureValues(float plantPressure, float icuPressure, float wardPressure) {
    lcd_i2c1.clear();
    lcd_i2c1.setCursor(0, 0);
    lcd_i2c1.print("Plant Pressure: ");
    lcd_i2c1.print(plantPressure);
    lcd_i2c1.setCursor(0, 1);
    lcd_i2c1.print("ICU Pressure: ");
    lcd_i2c1.print(icuPressure);
    delay(500);
    lcd_i2c1.scrollDisplayLeft();

    lcd_i2c1.setCursor(0, 0);
    lcd_i2c1.print("Ward Pressure: ");
    lcd_i2c1.print(wardPressure);
    delay(500);
    lcd_i2c1.scrollDisplayLeft();
}

/*
* Prints the current status of the three valves, i.e Open or Closed for Valve A(Inlet), Valve B(ICU) and Valve C(Ward), it should accept three boolean values if not given it should print Closed for all valves.
*/

void printValveStatus(bool valveA, bool valveB, bool valveC) {
    lcd_i2c1.clear();
    lcd_i2c1.setCursor(0, 0);
    lcd_i2c1.print("Valve A: ");
    if (valveA) {
        lcd_i2c1.print("Open");
    } else {
        lcd_i2c1.print("Closed");
    }
    lcd_i2c1.setCursor(0, 1);
    lcd_i2c1.print("Valve B: ");
    if (valveB) {
        lcd_i2c1.print("Open");
    } else {
        lcd_i2c1.print("Closed");
    }
    delay(2000);
    

    lcd_i2c1.clear();
    lcd_i2c1.setCursor(0, 0);
    lcd_i2c1.print("Valve C: ");
    if (valveC) {
        lcd_i2c1.print("Open");
    } else {
        lcd_i2c1.print("Closed");
    }
    delay(2000);
  
}

/*
* Prints the alarm message when there is a leak in the system, i.e Leak Detected, so it accepts  boolean value, if not given it should print No Leak Detected
*/

void printLeakStatus(bool leak) {
    lcd_i2c1.clear();
    lcd_i2c1.setCursor(0, 0);
    if (leak) {
        lcd_i2c1.print("Leak Detected");
    } else {
        lcd_i2c1.print("No Leak Detected");
    }
    delay(2000);
}



#endif
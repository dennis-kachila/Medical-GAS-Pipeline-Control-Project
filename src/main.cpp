/* 
  * File:   main.cpp
  * Integration with Blynk app and Web Dashboard
*/


#include "initConnection.h"
#include "I2C_LCDdisplay.h"
#include "PressureMonitoring.h"
#include "valve.h"
#include "solenoidValveRelay.h"
#include "leakageMonitoring.h"
#include <Arduino.h>

// define all the indicator LEDs
// iNDICATOR FOR SOLENOID VALVE
#define SOLENOID_RED_LED 23
#define SOLENOID_GREEN_LED 2


// Indicator for ICU Valve B
#define ICU_RED_LED 4
#define ICU_GREEN_LED 16

// Indicator for Ward Valve C
#define WARD_RED_LED 17
#define WARD_GREEN_LED 5

// Indicator for Junction Valve A
#define JUNCTION_RED_LED 18
#define JUNCTION_GREEN_LED 19

// leak indicator 
#define LEAK_CORNER_A_RED_LED 33
#define LEAK_CORNER_B_RED_LED 13

// defining pin for the valve A, B and C
#define VALVE_A_PIN 26
#define VALVE_B_PIN 27
#define VALVE_C_PIN 14

// Defining pin for the buzzer
#define BUZZER_PIN 12

/*  Defining corresponding Datastreams for control from Bylnk app
    V5 - alarm buzzer
    V6 - control valve A
    V7 - control valve B
    V8 - control valve C
    V9 - control solenoid valve (for relay)
  */
#define Bylnk_alarm_buzzer V5
#define Bylnk_control_valve_A V6
#define Bylnk_control_valve_B V7
#define Bylnk_control_valve_C V8
#define Bylnk_control_solenoid_valve V9

// Define the pin number for the solenoid valve relay
#define SOLENOID_VALVE_PIN 25

// Define the pin numbers for the pressure sensors
#define PLANT_PRESSURE_PIN 36
#define ICU_PRESSURE_PIN   39
#define WARD_PRESSURE_PIN 34

// Define the pin numbers for the microphone amplifier
#define LEAK_CORNER_A_PIN 35
#define LEAK_CORNER_B_PIN 32


// Creating an instance of the SolenoidValveRelay class
SolenoidValveRelay solenoidValve(SOLENOID_VALVE_PIN);
// Creating an instance of the PressureMonitor class
PressureMonitor pressureMonitor(PLANT_PRESSURE_PIN, ICU_PRESSURE_PIN, WARD_PRESSURE_PIN);
// Creating an instance of the Valve class
Valve valveA(VALVE_A_PIN);
Valve valveB(VALVE_B_PIN);
Valve valveC(VALVE_C_PIN);
// Creating an instance of the LeakageMonitor class
LeakageMonitor leakageMonitorObj(LEAK_CORNER_A_PIN, LEAK_CORNER_B_PIN);


BLYNK_WRITE(Bylnk_control_solenoid_valve)
{
  if(param.asInt()==1){
      // Turn on the solenoid valve relay
  solenoidValve.turnOnSolenoidValveRelay();
  Serial.println("Solenoid valve relay is turned on.");

  // Turn the Solenoid valve Green LED on
  digitalWrite( SOLENOID_GREEN_LED, HIGH);
  // Turn the Solenoid valve Red LED off
  digitalWrite( SOLENOID_RED_LED, LOW);


  }
  else{
    // Turn off the solenoid valve relay
  solenoidValve.turnOffSolenoidValveRelay();
  Serial.println("Solenoid valve relay is turned off.");

  // Turn the Solenoid valve Green LED off
  digitalWrite( SOLENOID_GREEN_LED, LOW);
  // Turn the Solenoid valve Red LED on
  digitalWrite( SOLENOID_RED_LED, HIGH);
  }
}

/*
  * Function for controlling the valve A
  * Bylnk_control_valve_A is the corresponding Datastream for control from Bylnk app
  
*/

BLYNK_WRITE(Bylnk_control_valve_A)
{
  if(param.asInt()==1){
    // Turn on the valve A
  valveA.open();
  Serial.println("Valve A is turned on.");

  // Turn the valve A Green LED on
  digitalWrite( JUNCTION_GREEN_LED, HIGH);
  // Turn the valve A Red LED off
  digitalWrite( JUNCTION_RED_LED, LOW);
  }
  else{
    // Turn off the valve A
  valveA.open();
  Serial.println("Valve A is turned off.");

  // Turn the valve A Green LED off
  digitalWrite( JUNCTION_GREEN_LED, LOW);
  // Turn the valve A Red LED on
  digitalWrite( JUNCTION_RED_LED, HIGH);
  }
}

/*
  * Function for controlling the valve B
  * Bylnk_control_valve_B is the corresponding Datastream for control from Bylnk app
  
*/

BLYNK_WRITE(Bylnk_control_valve_B)
{
  if(param.asInt()==1){
    // Turn on the valve B
  valveB.open();
  Serial.println("Valve B is turned on.");

  // Turn the valve B Green LED on
  digitalWrite( ICU_GREEN_LED, HIGH);
  // Turn the valve B Red LED off
  digitalWrite( ICU_RED_LED, LOW);
  }
  else{
    // Turn off the valve B
  valveB.open();
  Serial.println("Valve B is turned off.");

  // Turn the valve B Green LED off
  digitalWrite( ICU_GREEN_LED, LOW);
  // Turn the valve B Red LED on
  digitalWrite( ICU_RED_LED, HIGH);
  }
}

/*
  * Function for controlling the valve C
  * Bylnk_control_valve_C is the corresponding Datastream for control from Bylnk app
  
*/

BLYNK_WRITE(Bylnk_control_valve_C)
{
  if(param.asInt()==1){
    // Turn on the valve C
  valveC.open();
  Serial.println("Valve C is turned on.");

  // Turn the valve C Green LED on
  digitalWrite( WARD_GREEN_LED, HIGH);
  // Turn the valve C Red LED off
  digitalWrite( WARD_RED_LED, LOW);
  }
  else{
    // Turn off the valve C
  valveC.open();
  Serial.println("Valve C is turned off.");

  // Turn the valve C Green LED off
  digitalWrite( WARD_GREEN_LED, LOW);
  // Turn the valve C Red LED on
  digitalWrite( WARD_RED_LED, HIGH);
  }
}

/*
  * Function for controlling the alarm buzzer
  * Bylnk_alarm_buzzer is the corresponding Datastream for control from Bylnk app
  
*/

BLYNK_WRITE(Bylnk_alarm_buzzer)
{
  if(param.asInt()==1){
    // Turn on the alarm buzzer
  digitalWrite( BUZZER_PIN, HIGH);
  Serial.println("Alarm buzzer is turned on.");
  }
  else{
    // Turn off the alarm buzzer
  digitalWrite( BUZZER_PIN, LOW);
  Serial.println("Alarm buzzer is turned off.");
  }
}



BLYNK_CONNECTED()
{
  Blynk.syncVirtual(Bylnk_alarm_buzzer);
  Blynk.syncVirtual(Bylnk_control_valve_A);
  Blynk.syncVirtual(Bylnk_control_valve_B);
  Blynk.syncVirtual(Bylnk_control_valve_C);
  Blynk.syncVirtual(Bylnk_control_solenoid_valve);  
}

void setup()
{
  pinMode(SOLENOID_RED_LED, OUTPUT); // Initialise digital pin 23 as an output pin for the solenoid valve red LED
  pinMode(SOLENOID_GREEN_LED, OUTPUT); // Initialise digital pin 2 as an output pin for the solenoid valve green LED
  pinMode(ICU_RED_LED, OUTPUT); // Initialise digital pin 4 as an output pin for the ICU red LED
  pinMode(ICU_GREEN_LED, OUTPUT); // Initialise digital pin 16 as an output pin for the ICU green LED
  pinMode(WARD_RED_LED, OUTPUT); // Initialise digital pin 17 as an output pin for the ward red LED
  pinMode(WARD_GREEN_LED, OUTPUT); // Initialise digital pin 5 as an output pin for the ward green LED
  pinMode(JUNCTION_RED_LED, OUTPUT); // Initialise digital pin 18 as an output pin for the junction red LED
  pinMode(JUNCTION_GREEN_LED, OUTPUT); // Initialise digital pin 19 as an output pin for the junction green LED
  pinMode(LEAK_CORNER_A_RED_LED, OUTPUT); // Initialise digital pin 33 as an output pin for the leak corner A red LED
  pinMode(LEAK_CORNER_B_RED_LED, OUTPUT); // Initialise digital pin 13 as an output pin for the leak corner B red LED
  pinMode(BUZZER_PIN, OUTPUT); // Initialise digital pin 12 as an output pin for the alarm buzzer

  Serial.begin(115200);
  // Greeting message
  Serial.println("\n\n\nVenera: " + String(BLYNK_FIRMWARE_VERSION));
  delay(100);

  // Initialize the LCD display 
  lcd_i2c1.init();
  lcd_i2c1.backlight();
  printWelcomeMessage();


  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  delay(100);



    // 1. Read and print the pressure values
  float plantPressure = pressureMonitor.readPlantPressure();
  float icuPressure = pressureMonitor.readICUPressure();
  float wardPressure = pressureMonitor.readWardPressure();

  // 2. Read and print the leakage values
  float leakageCornerA = leakageMonitorObj.readLeakageCornerA();
  float leakageCornerB = leakageMonitorObj.readLeakageCornerB();


  // Print the pressure values to the serial monitor
  Serial.print("Plant Pressure: ");
  Serial.println(plantPressure);
  Serial.print("ICU Pressure: ");
  Serial.println(icuPressure);
  Serial.print("Ward Pressure: ");
  Serial.println(wardPressure);
  // print empty lines to separate the readings
  Serial.println();

  // Print the leakage values to the serial monitor
  Serial.print("Leakage Corner A: ");
  Serial.println(leakageCornerA);
  Serial.print("Leakage Corner B: ");
  Serial.println(leakageCornerB);
  // print empty lines to separate the readings
  Serial.println();


  // Send value to Blynk to plant pressure gauge
  Blynk.virtualWrite(V0, plantPressure);
  // Send value to Blynk to ICU pressure gauge
  Blynk.virtualWrite(V1, icuPressure);
  // Send value to Blynk to ward pressure gauge
  Blynk.virtualWrite(V2, wardPressure);

  // Send value to Blynk to leakage corner A gauge
  Blynk.virtualWrite(V3, leakageCornerA);
  // Send value to Blynk to leakage corner B gauge
  Blynk.virtualWrite(V4, leakageCornerB);

  // Display the system status on the LCD display
  printPressureValues(plantPressure, icuPressure, wardPressure);

  // Display the valve status on the LCD display
  void printSystemStatus();

}
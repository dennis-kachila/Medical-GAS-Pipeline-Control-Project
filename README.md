# Medical GAS Project
    
    [![GitHub license](https://img.shields.io/github/license/Naereen/StrapDown.js.svg)](

This project in-partial fulfillment of the requirements for the award of the degree of Bachelor of **Biomedical Engineering** of the **Kenyatta University**, Nairobi, Kenya.


This project contains the source code for the Medical GAS Project. It is a software application designed to monitor and control the gas levels in a medical facility.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Medical GAS Project is developed to ensure the safe and efficient management of gas levels in medical facilities. It provides real-time monitoring, alerts, and control mechanisms of gas ball valves to maintain optimal gas levels for various medical equipment.

## Installation

To install and run the Medical GAS Project, follow these steps:

1. Clone the repository: `git clone https://github.com/your-username/medical-gas-project.git`
2. Navigate to the project directory: `cd medical-gas-project`
3. Install the required dependencies: `npm install`

## Project Files

This project contains several files:

- `main.cpp`: This is the main file where the program starts. It initializes the necessary classes and starts the main loop.

- `PressureMonitoring.h` and `PressureMonitoring.cpp`: These files define the `PressureMonitor` class, which is responsible for reading the pressure values from the sensors.

- `LeakageMonitoring.h` and `LeakageMonitoring.cpp`: These files define the `LeakageMonitor` class, which is responsible for reading the sound values from the microphone amplifiers.

- `Valve.h` and `Valve.cpp`: These files define the `Valve` class, which is responsible for controlling the gas ball valves by opening and closing them.

- `initConnection.h` which is responsible for initializing the connection to the Blynk server.

- `I2C_LCDdisplay.h` which is responsible for initializing the LCD display and displaying the gas levels on the LCD screen and the sytem status.

Please refer to the comments in the individual files for more detailed information about how they work.

# Usage
To use the Medical GAS Project, follow these steps:
## Blynk Integration

This project uses Blynk for real-time monitoring of the gas levels on a smartphone. Blynk is a platform with iOS and Android apps to control Arduino, Raspberry Pi and the likes over the Internet. 

To use Blynk with this project:

1. Download the Blynk app on your smartphone.
2. Create a new Blynk project.
3. Scan the QR code in the Blynk directory in this repository to clone the project interface.
4. Replace the Blynk authentication token in the `initConnection.h` file with your own token, which can be found in the settings of your Blynk project.

Now, when you run the Medical GAS Project, the gas levels will be displayed in real-time on your smartphone and on the LCD screen and Web UI.

You need to have a Blynk account to use this project. You can create an account by downloading the Blynk app on your smartphone and signing up.

How the Blynk app looks like can be seen in the `UI` folder. Which contains the screenshots of the Blynk app UI and the Web Dashboard UI.

Set up the datastreams in the WEB Dashboard according to the file `main.p` which is in the `src` folder.


The circuit  and flowchart diagram for the project is in the `circuit` folder and the link to the wokwi simulation is [here](https://wokwi.com/projects/386356806730328065).

For the Simulation to work , you have to reconfigure the file `initConnection.h` accordingly, I will provide the steps steps later on , but as of Now, code in the file `main.cpp` is configured for the real hardware.

Please refer to the [Blynk Documentation](http://docs.blynk.cc/) for more detailed instructions and troubleshooting.

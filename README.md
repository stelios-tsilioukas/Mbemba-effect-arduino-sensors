# Mbemba-effect-arduino-sensors


This repository contains code and instructions for connecting three waterproof digital temperature sensors (DS18B20) to an Arduino Uno and plotting the measurements in real-time using Excel.

## Table of Contents
- [Introduction](#introduction)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction
This project demonstrates how to connect three DS18B20 waterproof digital temperature sensors to an Arduino Uno, read the temperature data, and plot the measurements in real-time using Excel.

## Requirements
- Arduino Uno
- Three DS18B20 waterproof digital temperature sensors
- 4.7kΩ resistor
- Breadboard and jumper wires
- `OneWire` and `DallasTemperature` libraries for Arduino
- Excel with `PLX-DAQ` add-in (for real-time data plotting)

## Installation
1. **Clone the repository:**
    ```bash
    git clone https://github.com/steios-tsilioukas/arduino-temperature-sensor.git
    cd arduino-temperature-sensor
    ```

2. **Install Arduino Libraries:**
    - Open the Arduino IDE.
    - Go to `Sketch` -> `Include Library` -> `Manage Libraries`.
    - Search for `OneWire` and `DallasTemperature` libraries and install them.

3. **Download and Install PLX-DAQ:**
    - Download PLX-DAQ from [here](https://www.parallax.com/package/plx-daq).
    - Follow the installation instructions provided on the website to add it to Excel.

## Usage
### Hardware Setup
1. **Wiring the Sensors:**
    - Connect the **GND** pin of each DS18B20 sensor to the **GND** pin on the Arduino.
    - Connect the **VDD** pin of each DS18B20 sensor to the **5V** pin on the Arduino.
    - Connect the **DATA** pin of each DS18B20 sensor to a digital pin on the Arduino (we'll use **pin 2** in this example).
    - Add a **4.7kΩ resistor** between the **DATA** and **VDD** pins (pull-up resistor).

    ```
    Arduino UNO      DS18B20 Sensors
    ----------      ----------------
       5V  --------->  VDD (red)
      GND  --------->  GND (black)
       D2  --------->  DATA (yellow) (with 4.7kΩ pull-up resistor to VDD)
    ```

### Arduino Code
2. **Upload the Arduino Code:**
    - Open the Arduino IDE.
    - Copy and paste the following code into the IDE:

    ```cpp
    #include <OneWire.h>
    #include <DallasTemperature.h>

    // Data wire is connected to Arduino digital pin 2
    #define ONE_WIRE_BUS 2

    // Setup a oneWire instance to communicate with any OneWire devices
    OneWire oneWire(ONE_WIRE_BUS);

    // Pass our oneWire reference to Dallas Temperature.
    DallasTemperature sensors(&oneWire);

    void setup() {
      // Start serial communication for debugging
      Serial.begin(9600);
      
      // Start the DS18B20 sensor
      sensors.begin();
      
      // Print the header for PLX-DAQ
      Serial.println("CLEARDATA");
      Serial.println("LABEL,Time,Sensor 1,Sensor 2,Sensor 3");
    }

    void loop() {
      // Request temperature readings from all sensors
      sensors.requestTemperatures();
      
      // Print temperature readings to the Serial Monitor
      Serial.print("DATA,TIME,");
      for (int i = 0; i < sensors.getDeviceCount(); i++) {
        Serial.print(sensors.getTempCByIndex(i));
        Serial.print(",");
      }
      Serial.println();
      
      // Wait for 1 second before taking another reading
      delay(1000);
    }
    ```

    - Upload the code to the Arduino Uno.

### Real-Time Plotting with Excel
3. **Set Up PLX-DAQ:**
    - Open Excel and go to the `Add-Ins` tab.
    - Click on `PLX-DAQ` to open the interface.
    - Select the correct COM port and set the baud rate to `9600`.
    - Click `Connect`.

4. **Plot the Data:**
    - Once connected, data from the Arduino will start streaming into Excel.
    - Use Excel's charting tools to create real-time plots of the temperature data.

## Project Structure
```
arduino-temperature-sensor/
│
├── arduino_code.ino   # Arduino code for reading sensors and sending data to Serial
├── README.md          # This file
```

## Example
1. **Hardware Setup:**
    - Follow the wiring diagram to connect the DS18B20 sensors to the Arduino.

2. **Upload Code to Arduino:**
    - Open the Arduino IDE and upload the provided code.

3. **Set Up and Use PLX-DAQ:**
    - Open Excel and connect to the Arduino using PLX-DAQ.
    - Real-time temperature data will be displayed and can be plotted in Excel.
4. ** Project implementation (2013)
   - https://youtu.be/_ZXs6W1JNhk?si=JojLBqAGCaauia4I

## Contributing
Contributions are welcome! Please feel free to submit a Pull Request or open an Issue if you have any suggestions or improvements.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.

---


# Temperature and Humidity Display with Arduino

## Overview
This project demonstrates a **temperature and humidity display** using a KS0108 graphical LCD 128*64 and a DHT11 sensor with an Arduino. The data is displayed in real-time on the screen, showing temperature in Celsius and humidity in percentage.

### Features
- **Real-time Environmental Data**: Displays temperature and humidity readings in real-time.
- **Error Handling**: Displays an error message if the sensor fails to provide data.

---

## Components
To replicate this project, you will need:

| Component            | Quantity |
|----------------------|----------|
| Arduino (Uno/Nano)   | 1        |
| KS0108 Graphical LCD | 1        |
| DHT11 Sensor         | 1        |
| Resistor (330Ω)      | 1        |
| Potentiometer (10kΩ) | 1        |
| Breadboard           | 1        |
| Jumper Wires         | As needed |

---

## Circuit Connections

### KS0108 Graphical LCD

| Pin Number | GLCD Pin    | Arduino Pin                 | Description                     |
|------------|-------------|-----------------------------|---------------------------------|
| 1          | VSS         | GND                         | Ground                          |
| 2          | VDD         | 5V                          | Power Supply                    |
| 3          | VO          | Potentiometer Center Pin    | Contrast Adjustment (Use a 10kΩ potentiometer) |
| 4          | RS          | A0                          | Register Select Control         |
| 5          | R/W         | A1                          | Read/Write Mode Control         |
| 6          | EN          | A2                          | Enable Data Transfer            |
| 7          | DB0         | 2                           | Data Byte 0                     |
| 8          | DB1         | 3                           | Data Byte 1                     |
| 9          | DB2         | 4                           | Data Byte 2                     |
| 10         | DB3         | 5                           | Data Byte 3                     |
| 11         | DB4         | 6                           | Data Byte 4                     |
| 12         | DB5         | 7                           | Data Byte 5                     |
| 13         | DB6         | 8                           | Data Byte 6                     |
| 14         | DB7         | 9                           | Data Byte 7                     |
| 15         | CS1         | 10                          | Chip Select 1                   |
| 16         | CS2         | 11                          | Chip Select 2                   |
| 17         | RST         | 12                          | Reset Display                   |
| 18         | VOUT        | N/A                         | Output Voltage (used for powering the potentiometer in this project) |
| 19         | A (LED+)    | 13 (via 330Ω resistor)       | Backlight Positive Power (connected via a resistor to control current) |
| 20         | K (LED-)    | GND                         | Backlight Ground                |

### DHT11 Sensor

| Pin Number | DHT11 Pin   | Arduino Pin                 | Description                     |
|------------|-------------|-----------------------------|---------------------------------|
| 1          | GND         | GND                         | Ground                          |
| 2          | VCC         | 5V                          | Power Supply                    |
| 3          | Data        | A3                          | Data Pin for Sensor Communication |

---

## Software Setup

### Libraries Required
Ensure you have the following libraries installed in your Arduino IDE:
1. `Adafruit GFX` - For graphics rendering.
2. `KS0108_GLCD` - For controlling the graphical LCD.
3. `DHT` - For interfacing with the DHT11 sensor.

To install these libraries:
1. Go to **Sketch > Include Library > Manage Libraries**.
2. Search for each library by name and click **Install**.

### Code
The full source code for this project is available in the `temp_humidity_display.ino` file. Upload the code to your Arduino using the Arduino IDE.

---

## How It Works
1. **Initialization**:
   - The DHT sensor and GLCD are initialized during the `setup()` phase.
   - The GLCD is cleared and prepared for display.
2. **Real-time Display**:
   - The temperature and humidity readings are fetched from the DHT11 sensor.
   - These values are displayed on the screen in a clean and readable format.
3. **Error Handling**:
   - If the sensor fails to provide data, an error message is displayed.

---

## Adjustments

### Customizing Fonts
- To use a different font for the display, change this line in the code:
  ```cpp
  display.setFont(&FreeSerif12pt7b);
  ```
- Replace `FreeSerif12pt7b` with another font available in the Adafruit GFX library.

### Refresh Rate
- Adjust the refresh rate by changing the `delay` value in the `loop` function:
  ```cpp
  delay(2000); // Adjust the delay for faster or slower updates.
  ```

---

## Troubleshooting

### Common Issues
1. **GLCD Not Displaying Properly**:
   - Check the wiring and ensure all connections match the table above.
   - Ensure the `KS0108_GLCD` library is correctly installed.
2. **Sensor Errors**:
   - Ensure the DHT11 sensor is properly connected to 5V, GND, and the data pin.
   - Replace the sensor if it continues to return `NaN` values.

---

## Preview
- **Temperature and Humidity**: Displays real-time environmental data.
- **Error Messages**: Notifies the user of sensor issues.

---

## License
Copyright 2025 Masoud Khanalizadeh Imani

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

---

## Contact
For any questions or issues, feel free to contact me at:
**masoud.khanalizadehimani@gmail.com**

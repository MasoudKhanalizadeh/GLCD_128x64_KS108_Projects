# GLCD\_128\*64 Test Project with Arduino

## Overview

This project is a basic test for the **KS0108 graphical LCD 128\*64 to demonstrate its functionality with an Arduino. It includes backlight control, text display, and simple blinking functionality to ensure proper setup and working of the GLCD.**

### Features

- **Hello World Display**: Displays a simple "Hello World!" message on the GLCD.
- **Backlight Control**: Toggles the backlight to test brightness and visibility.
- **Blinking Display**: Clears the screen briefly to simulate blinking text.

---

## Components

To replicate this project, you will need:

| Component            | Quantity  |
| -------------------- | --------- |
| Arduino (Uno/Nano)   | 1         |
| KS0108 Graphical LCD | 1         |
| Resistor (330Ω)      | 1         |
| Potentiometer (10kΩ) | 1         |
| Breadboard           | 1         |
| Jumper Wires         | As needed |

---

## Circuit Connections

### KS0108 Graphical LCD

| Pin Number | GLCD Pin | Arduino Pin              | Description                                                            |
| ---------- | -------- | ------------------------ | ---------------------------------------------------------------------- |
| 1          | VSS      | GND                      | Ground                                                                 |
| 2          | VDD      | 5V                       | Power Supply                                                           |
| 3          | VO       | Potentiometer Center Pin | Contrast Adjustment (Use a 10kΩ potentiometer)                         |
| 4          | RS       | A0                       | Register Select Control                                                |
| 5          | R/W      | A1                       | Read/Write Mode Control                                                |
| 6          | EN       | A2                       | Enable Data Transfer                                                   |
| 7          | DB0      | 2                        | Data Byte 0                                                            |
| 8          | DB1      | 3                        | Data Byte 1                                                            |
| 9          | DB2      | 4                        | Data Byte 2                                                            |
| 10         | DB3      | 5                        | Data Byte 3                                                            |
| 11         | DB4      | 6                        | Data Byte 4                                                            |
| 12         | DB5      | 7                        | Data Byte 5                                                            |
| 13         | DB6      | 8                        | Data Byte 6                                                            |
| 14         | DB7      | 9                        | Data Byte 7                                                            |
| 15         | CS1      | 10                       | Chip Select 1                                                          |
| 16         | CS2      | 11                       | Chip Select 2                                                          |
| 17         | RST      | 12                       | Reset Display                                                          |
| 18         | VOUT     | N/A                      | Output Voltage (used for powering the potentiometer in this project)   |
| 19         | A (LED+) | 13 (via 330Ω resistor)   | Backlight Positive Power (connected via a resistor to control current) |
| 20         | K (LED-) | GND                      | Backlight Ground                                                       |

### Detailed Explanation of Pins

1. **VSS (Pin 1):** Connect to **GND** to provide the ground reference for the GLCD.
2. **VDD (Pin 2):** Connect to **5V** to power the GLCD.
3. **VO (Pin 3):** This pin adjusts the contrast of the display. Use a 10kΩ potentiometer connected between **5V**, **GND**, and this pin to set the appropriate contrast.
4. **RS (Pin 4):** Register Select pin determines whether data or commands are sent. Connect to **A0** on the Arduino.
5. **R/W (Pin 5):** Read/Write pin controls the data flow direction. Connect to **A1** to toggle between read and write modes.
6. **EN (Pin 6):** Enable pin triggers the execution of commands. Connect to **A2** for control.
   7-14. **DB0-DB7 (Pins 7-14):** These are the data pins. Connect them to Arduino pins **2-9** for sending data to the GLCD.
7. **CS1 (Pin 15):** Chip Select 1 enables the left half of the display. Connect to **10**.
8. **CS2 (Pin 16):** Chip Select 2 enables the right half of the display. Connect to **11**.
9. **RST (Pin 17):** Reset pin initializes the GLCD. Connect to **12**.
10. **VOUT (Pin 18):** Provides a regulated output voltage. Typically used for powering external components like a potentiometer.
11. **A (LED+, Pin 19):** Backlight positive power pin. Connect to **13** via a **330Ω resistor** to limit current and protect the LED.
12. **K (LED-, Pin 20):** Backlight ground pin. Connect to **GND**.

---

## Software Setup

### Libraries Required

Ensure you have the following libraries installed in your Arduino IDE:

1. `Adafruit GFX` - For graphics rendering.
2. `KS0108_GLCD` - For controlling the graphical LCD.

To install these libraries:

1. Go to **Sketch > Include Library > Manage Libraries**.
2. Search for each library by name and click **Install**.

### Code

The full source code for this project is available in the `glcd_test.ino` file. Upload the code to your Arduino using the Arduino IDE.

---

## How It Works

1. **Initialization**:
   - The GLCD is initialized during the `setup()` phase.
   - The backlight is turned on by default for visibility.
2. **Text Display**:
   - The text "Hello World!" is displayed on the screen using the `setCursor` and `print` functions.
   - The font is set using the Adafruit GFX library (`FreeSerif12pt7b`).
3. **Backlight and Blinking**:
   - The backlight toggles on and off in the `loop()` function.
   - The display is cleared to simulate blinking, and the message is re-rendered.

---

## Adjustments

### Customizing Text

- To change the displayed text, modify this line in the code:
  ```cpp
  display.print(F("Hello World!"));
  ```
- Replace `"Hello World!"` with your desired text.

### Backlight Behavior

- To keep the backlight always on, remove or comment out the following lines in the code:
  ```cpp
  digitalWrite(BACKLIGHT_PIN, LOW); // Turn off backlight
  ```

### Font Options

- Change the font by replacing `FreeSerif12pt7b` with any other font available in the Adafruit GFX library.

---

## Troubleshooting

### Common Issues

1. **GLCD Not Displaying Properly**:
   - Check the wiring and ensure all connections match the table above.
   - Ensure the `KS0108_GLCD` library is correctly installed.
2. **Backlight Not Working**:
   - Verify the backlight pin (13) connection and the 330Ω resistor.
   - Ensure `digitalWrite(BACKLIGHT_PIN, HIGH);` is called in the `setup()` phase.

---

## Preview

- **Hello World Display**: Confirms the GLCD is functioning properly.
- **Blinking Text**: Demonstrates the ability to update the display dynamically.

---

## License

Copyright 2025 Masoud Khanalizadeh Imani

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

```
http://www.apache.org/licenses/LICENSE-2.0
```

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

---

## Contact

For any questions or issues, feel free to contact me at:
**[masoud.khanalizadehimani@gmail.com](mailto\:masoud.khanalizadehimani@gmail.com)**


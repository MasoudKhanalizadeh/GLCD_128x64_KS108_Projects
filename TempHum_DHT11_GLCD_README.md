# DHT11 and KS0108 GLCD Integration

This project demonstrates how to integrate the **DHT11 temperature and humidity sensor** with a **KS0108-based 128x64 graphical LCD (GLCD)** using an Arduino. The project utilizes the **Adafruit GFX library** for graphical rendering and displays real-time data on the GLCD.

---

## **Features**
- Real-time display of temperature and humidity.
- Graphical rendering using the KS0108 GLCD and Adafruit GFX library.
- Sensor error handling and notification.
- Easy-to-read text using scalable fonts.

---

## **Hardware Requirements**
1. **Arduino Uno (or compatible board)**
2. **KS0108-based 128x64 GLCD**
3. **DHT11 Temperature and Humidity Sensor**
4. **10kΩ Resistor** (Pull-up for DHT11)
5. Connecting wires and breadboard.

---

## **Connections**

### **GLCD Connections**
| **GLCD Pin** | **Arduino Pin** |
|--------------|-----------------|
| D0-D7        | 2-9            |
| RS           | 10             |
| RW           | 11             |
| E            | 12             |
| CS1          | A0             |
| CS2          | A1             |
| RST          | A2             |
| VEE          | Adjust with potentiometer |
| VCC          | 5V             |
| GND          | GND            |

### **DHT11 Connections**
| **DHT11 Pin** | **Arduino Pin** | **Description**         |
|---------------|-----------------|-------------------------|
| VCC           | 5V             | Power supply            |
| GND           | GND            | Ground                 |
| DATA          | A3             | Data signal to Arduino |

---

## **Code Overview**

The code reads temperature and humidity data from the DHT11 sensor and displays it on the KS0108 GLCD. It also includes error handling for sensor connectivity issues and provides a graphical output.

### **Libraries Used**
1. [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
2. [KS0108 GLCD Library](https://github.com/your-library-link)
3. [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)

---

## **How to Run**

1. **Hardware Setup:**
   - Connect the GLCD and DHT11 sensor to the Arduino as described in the connections table.
   - Ensure proper wiring for VCC, GND, and DATA.

2. **Install Required Libraries:**
   - Install the libraries mentioned above using Arduino Library Manager.

3. **Upload Code:**
   - Upload the provided code to your Arduino board using Arduino IDE.

4. **View Output:**
   - The GLCD will display real-time temperature and humidity data. In case of sensor errors, a "Sensor Error" message will be displayed.

---

## **Example Output**
### **Normal Operation**
Temp: 25.5 C Humi: 60.0 %

### **Error**
Sensor Error

---

## **License**
This project is licensed under the **Apache-2.0 License**. Feel free to use, modify, and distribute the code in compliance with the license terms.

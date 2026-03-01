# 🔌 IoT Smart Plug

## 📖 Project Overview
This project presents the development of an IoT Smart Plug system for remote control of electrical devices via the Internet.

The system is based on the ESP8266 Wi-Fi microcontroller, which communicates with an MQTT cloud server and controls a relay circuit to switch electrical loads ON and OFF.

The project was developed as part of coursework at the Faculty of Electronic Engineering, University of Niš.

---

## 🧠 System Concept
The Smart Plug enables users to:
- Remotely turn electrical devices ON or OFF
- Control devices through a mobile application
- Communicate using the MQTT protocol over Wi-Fi

The ESP8266 connects to a local Wi-Fi network and subscribes to a specific MQTT topic. Based on received messages, it activates or deactivates the relay.

---

## 🛠 Hardware Components

- ESP8266 Wi-Fi microcontroller
- Relay (LEG1A-5F)
- Transistor (BC547)
- Resistor (1 kΩ)
- Diode (1N4148)
- Filtering capacitor
- 5V power adapter
- Mechanical switch
- Electrical socket housing

---

## ⚙️ Hardware Implementation

All components were soldered onto a prototyping board to ensure mechanical stability and reliable electrical connections.

After initial testing, a filtering capacitor was added to reduce high-frequency noise and improve system stability.

The complete circuit was integrated into a socket housing and connected to:
- Main power cable
- Mechanical ON/OFF switch
- 5V power supply for stable relay operation

---

## 💻 Software Implementation

The software enables the ESP8266 to:

1. Connect to a local Wi-Fi network
2. Establish secure MQTT communication with a cloud server
3. Subscribe to a predefined MQTT topic
4. Receive ON/OFF commands in real time
5. Automatically reconnect to the MQTT broker if connection is lost

This ensures stable and reliable operation of the system.

---

## 📡 MQTT Communication

- Protocol: MQTT
- Communication type: Cloud-based
- Functionality: Publish/Subscribe model
- Purpose: Remote switching of electrical load

---

## 📱 Mobile Application

A user-friendly mobile application was developed using MIT App Inventor.

Instead of manually sending MQTT messages, the user can control the Smart Plug with a single button click.

For MQTT communication, a modified and stabilized version of the UrsAI2PahoMQTT extension was used. The original version had SSL connection issues, which were resolved to ensure reliable cloud communication.

---

## 📷 Project Documentation

The repository includes:
- Arduino source code
- Project report (PDF)
- Hardware schematics
- Images of the assembled device
- Application screenshots

---

## 🎯 Conclusion

The Smart Plug system was successfully implemented and tested under real operating conditions.

The project demonstrates a functional IoT solution that can be further expanded with:
- Energy consumption monitoring
- Integration with smart home systems
- Automation features

---

## 👨‍💻 Author

Mladen Milutinović  
Faculty of Electronic Engineering  
University of Niš

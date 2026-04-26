# 🚗 Car Black Box (CBB) System

## 📌 Overview
The Car Black Box (CBB) is an embedded system designed to monitor and record critical vehicle events such as gear changes, speed, and time.  
The system stores event logs in an external EEPROM and allows users to view, clear, and download logs using a menu-driven interface.

---

## 🎯 Features
- Real-time display of Time, Speed, and Gear
- Event logging on gear change or critical events
- Storage using External EEPROM (AT24C04)
- Menu-driven interface using CLCD and Keypad
- Log viewing and navigation
- Log download via UART (Tera Term)
- Log clearing functionality
- Time setting using RTC

---

## 🧠 System Architecture
- Microcontroller: PIC18F4580  
- RTC: DS1307 (I2C)  
- EEPROM: AT24C04 (I2C)  
- Input: Matrix Keypad  
- Display: 16x2 CLCD  
- Communication: UART (for log download)

---

## ⚙️ Working Principle
1. The system continuously displays time, speed, and gear in dashboard mode  
2. On detecting an event (gear change, etc.), data is logged into EEPROM  
3. User can access menu to:
   - View logs  
   - Download logs  
   - Clear logs  
   - Set time  
4. Logs are stored using a circular buffer to prevent overflow  

---

## 💾 Log Format
Each log stores:  
Time (HH:MM:SS) | Event | Speed  

Example:  
10:45:30 G2 45  

---

## 🔄 Circular Buffer Logic
- Maximum logs stored: 10  
- New logs overwrite oldest logs when memory is full  

---

## 🚀 How to Run
1. Open project in MPLAB X IDE  
2. Compile using XC8 Compiler  
3. Flash code to PIC18F4580  
4. Connect:
   - CLCD display  
   - Keypad  
   - RTC (DS1307 via I2C)  
   - EEPROM (AT24C04 via I2C)  
5. Use Tera Term for UART output  

---

## 📊 Applications
- Vehicle monitoring systems  
- Accident analysis  
- Driver behavior tracking  
- Automotive diagnostics  

---

## 📚 Learning Outcomes
- Embedded C programming  
- I2C communication (RTC + EEPROM)  
- UART communication  
- EEPROM data handling  
- Real-time system design  

---

## 🧑‍💻 Author
Manu H P  
Embedded Systems Enthusiast  

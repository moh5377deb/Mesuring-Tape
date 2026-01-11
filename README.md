# 📏 ESP32-C3 Ultrasonic Distance Meter — OLED

This project uses an **ESP32-C3 Super Mini**, an **HC-SR04 ultrasonic sensor**
and a **mini OLED screen (SSD1306)** to measure distances up to **4 meters**
and display the result in real time.

The project focuses on embedded programming, sensor handling,
and I2C display communication.

────────────────────────────────────────────────────────

📸 PREVIEW

(images/oled_distance.png)  
(images/setup.jpg)

────────────────────────────────────────────────────────

🧠 FEATURES

📡 Ultrasonic distance measurement (up to 4 meters)  
🖥️ Real-time display on mini OLED screen  
⚡ Fast refresh rate  
🔌 Simple wiring  
🧰 Clean and structured Arduino code  

────────────────────────────────────────────────────────

🧭 REQUIREMENTS

### Hardware
- ESP32-C3 Super Mini  
- HC-SR04 Ultrasonic Sensor  
- OLED SSD1306 (128x64, I2C)  
- Jumper wires  

### Software
- Arduino IDE  
- ESP32 board support  
- Adafruit SSD1306 library  
- Adafruit GFX library  


────────────────────────────────────────────────────────

🔌 WIRING

### Ultrasonic Sensor (HC-SR04)
- VCC  → 5V  
- GND  → GND  
- TRIG → GPIO 4  
- ECHO → GPIO 5  

### OLED (I2C)
- VCC → 3.3V  
- GND → GND  
- SDA → SDA  
- SCL → SCL  

────────────────────────────────────────────────────────

🧠 CODE STRUCTURE

- Ultrasonic measurement  
  Controls trigger/echo pins and computes distance.

- OLED display handler  
  Displays the measured distance in centimeters.

- Main loop  
  Updates measurement and display continuously.

────────────────────────────────────────────────────────

🛠️ POSSIBLE IMPROVEMENTS

- Display distance in meters  
- Add buzzer or LED warning  
- Add Bluetooth or Wi-Fi data transmission  
- Add min/max distance memory   

────────────────────────────────────────────────────────

📄 LICENSE

Educational project.

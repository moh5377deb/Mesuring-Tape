/******************************************************
 * ESP32-C3 SUPER MINI — ULTRASON + MINI OLED
 * Mesure de distance (max 4 m) et affichage sur écran OLED
 *
 * Capteur ultrason : HC-SR04
 * Écran : OLED SSD1306 (I2C)
 ******************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/* ───────────── CONFIGURATION OLED ───────────── */
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/* ───────────── CONFIGURATION ULTRASON ───────────── */
#define TRIG_PIN 6
#define ECHO_PIN 7
#define MAX_DISTANCE_CM 400  // Portée max : 4 mètres

long duration;
float distanceCm;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Wire.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    while (true); // OLED non détecté
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("ESP32-C3");
  display.println("Ultrason + OLED");
  display.display();
  delay(2000);
}

void loop() {
  // Déclenchement ultrason
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 25000); // timeout ≈ 4m

  if (duration == 0) {
    distanceCm = MAX_DISTANCE_CM;
  } else {
    distanceCm = duration * 0.034 / 2;
  }

  if (distanceCm > MAX_DISTANCE_CM) {
    distanceCm = MAX_DISTANCE_CM;
  }

  // Affichage OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Distance mesuree");

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(distanceCm, 1);
  display.println(" cm");

  display.display();
  delay(300);
}

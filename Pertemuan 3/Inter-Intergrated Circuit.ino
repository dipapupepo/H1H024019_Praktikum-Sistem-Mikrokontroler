#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinPot = A0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int adc = analogRead(pinPot);

  float volt = adc * (5.0 / 1023.0);
  int persen = map(adc, 0, 1023, 0, 100);
  int bar = map(adc, 0, 1023, 0, 16);

  // ===== SERIAL MONITOR (FORMAT SESUAI SOAL) =====
  Serial.print("ADC: ");
  Serial.print(adc);
  Serial.print(" | Volt: ");
  Serial.print(volt, 2);
  Serial.print(" V | Persen: ");
  Serial.print(persen);
  Serial.println("%");

  // ===== LCD =====
  // Baris 1 → ADC & Persen
  lcd.setCursor(0, 0);
  lcd.print("ADC:");
  lcd.print(adc);
  lcd.print(" ");
  lcd.print(persen);
  lcd.print("%   "); // clear sisa

  // Baris 2 → Bar (level)
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    if (i < bar) {
      lcd.print((char)255);
    } else {
      lcd.print(" ");
    }
  }

  delay(200);
}
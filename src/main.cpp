#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <BH1750.h>

int lcd_columns = 16;
int lcd_rows = 2;

LiquidCrystal_I2C lcd(0x27, lcd_columns, lcd_rows);
BH1750 luxMeter;

void setup() {
  Serial.begin(9600);
  Serial.println("\nInitialize LCD");
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LCD Ready!");
  delay(1000);
  Wire.begin(D2, D1);
  luxMeter.begin();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.clear();
  float lux = luxMeter.readLightLevel();
  lcd.print("Light:");
  lcd.print(lux);
  Serial.print("Light: ");
  Serial.println(lux);
  lcd.println(" lx");
  delay(1500);
}

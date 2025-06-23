#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <BH1750.h>
#include <Adafruit_AHTX0.h>

int lcd_columns = 16;
int lcd_rows = 2;

LiquidCrystal_I2C lcd(0x27, lcd_columns, lcd_rows);
BH1750 luxMeter;
Adafruit_AHTX0 aht;

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
  aht.begin();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.clear();
  float lux = luxMeter.readLightLevel();
  sensors_event_t temp, hum;
  aht.getEvent(&hum, &temp);
  lcd.print("Light:");
  lcd.print(lux);
  Serial.print("Light: ");
  Serial.println(lux);
  lcd.print(" lx");
  lcd.setCursor(0, 1);
  lcd.print("Temp:");
  lcd.print(temp.temperature);
  lcd.print("C");
  delay(1500);
}

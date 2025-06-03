#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int lcd_columns = 16;
int lcd_rows = 2;

LiquidCrystal_I2C lcd(0x27, lcd_columns, lcd_rows);

void setup() {
  Serial.begin(9600);
  Serial.println("\nInitialize LCD");
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello World!");
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.clear();
  for (int i = 0; i < 3; i++) {
    lcd.print(".");
    delay(1500);
  }
}

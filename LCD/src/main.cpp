#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int SDA_pin = D2;
int SCL_pin = D7;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(SDA_pin,SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Indonesia Emas");
  lcd.setCursor(0,1);
  lcd.print("Hidup Jokowi");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(300);
}

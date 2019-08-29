#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);//0x3F or 0x27 or check by TestI2C example
//D1 pin to SCL D2 pin to SDA

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.print("Hello!!!");
  lcd.setCursor(0, 1);
  lcd.print("CESmartCamp");
}

void loop()
{
  // Do nothing here...
}

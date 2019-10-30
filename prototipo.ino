#include <LiquidCrystal.h>

int ldrRawData;
float resistorVoltage, ldrVoltage;
float ldrResistance, ldrLux;
float temp;
LiquidCrystal lcd(12, 11, 5, 4, 3 ,2);

void setup(void) {
 lcd.begin(16, 2);
}

void loop(void) {
 //David Williams Formula
 ldrRawData = analogRead(A0);
 ldrRawData = analogRead(A0);
 resistorVoltage = (float)ldrRawData / 1023 * 5.0;
 ldrVoltage = 5.0 - resistorVoltage;
 ldrResistance = ldrVoltage/resistorVoltage * 2500;
 ldrLux = 12518931 * pow(ldrResistance, -1.405);
 
 temp = analogRead(A5);
 temp = analogRead(A5);
 temp = temp * 0.48827125;
 
 lcd.print("Temp: ");
 lcd.print(temp);
 lcd.setCursor(0, 0);
 lcd.print("Luz: ");
 lcd.print(ldrLux);
 lcd.setCursor(0, 1);

 delay(300);
}

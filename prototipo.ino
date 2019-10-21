int ldrRawData;
float resistorVoltage, ldrVoltage;
float ldrResistance, ldrLux;
float temp;

void setup(void) {
 pinMode(8, OUTPUT);
 Serial.begin(9600);  
}

void loop(void) {
 ldrRawData = analogRead(A0);
 ldrRawData = analogRead(A0);
 resistorVoltage = (float)ldrRawData / 1023 * 5.0;
 ldrVoltage = 5.0 - resistorVoltage;
 ldrResistance = ldrVoltage/resistorVoltage * 2500;
 ldrLux = 12518931 * pow(ldrResistance, -1.405);
 
 temp = analogRead(A5);
 temp = analogRead(A5);
 temp = temp * 0.48827125;
 
 
 Serial.print("Luminosidade: ");
 Serial.print(ldrLux);
 Serial.print(" Lux\t");
 Serial.print("Temperatura: ");
 Serial.print(temp);
 Serial.print(" °C\n");

 delay(1000);

 if (ldrLux >= 10000 and temp >= 21 and temp < 26){
  digitalWrite(8, HIGH);
 } else {
  digitalWrite(8, LOW);
 }
}

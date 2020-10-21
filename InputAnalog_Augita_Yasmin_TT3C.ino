#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //set kaki LCD
int sensor_Pin = A0; //pin analog untuk sensor LM35
int nilai_ADC_sensor = 0; //variabel untuk menyimpan hasil pembacaan sensor

void setup() {
  // put your setup code here, to run once:
lcd.begin(20, 4); //inisialisasi 20*4 LCD
lcd.setCursor(0, 0); //set LCD pada column0 dan row0
lcd.print("Monitoring Suhu");
lcd.setCursor(0, 1);
lcd.print("Telekomunikasi PNJ");
delay(1000);
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
nilai_ADC_sensor = analogRead(sensor_Pin);
//mengubah nilai ADC sensor ke tegangan kemudian ke Celcius
double Celcius = ((5.0/1024.0)*analogRead(sensor_Pin))*100;
lcd.setCursor(0, 2);
lcd.print("SUHU RUANGAN:");
lcd.setCursor(0, 3);
lcd.print(Celcius);
lcd.setCursor(6, 3);
lcd.print((char)223); //simbol derajat
lcd.setCursor(7, 3);
lcd.print("C");
}

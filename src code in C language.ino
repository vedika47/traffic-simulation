#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,7,8,9,10);
 int redLed = 2;
 int greenLed = 3;
 int Buzzer = 4;
 int sensor=A0;
int Threshold_of_sensor = 400;


void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
  
  int sensorValue = analogRead(sensor);
  Serial.println(sensorValue);
  if(sensorValue>Threshold_of_sensor){
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,LOW);
    tone(Buzzer,1000,10000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Alert!!");
    delay(400);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Alert!!! ");
    delay(400);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Alert!!!!! ");
    delay(400);
  }
  else{
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,HIGH);
    noTone(Buzzer);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Safe Enviornment");
    delay(1000);
    lcd.setCursor(0,1);
    noTone(Buzzer);
  //  lcd.scrollDisplayRight();
    lcd.print("No Smoke");
    delay(1000);
  }
       
}
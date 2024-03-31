#include <TEA5767Radio.h>
#include <Wire.h>
#include <LiquidCrystal.h>
TEA5767Radio radio = TEA5767Radio();
int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
void setup()
{ 
Wire.begin(); 
Serial.begin(9600); 
analogWrite(6,Contrast); 
lcd.begin(16, 2); 
//pinMode(9,INPUT); 
lcd.clear(); lcd.print("Welcome, Jayaram"); 
delay(1000);
}
int i=5;
float stations[7]={91.1, 92.7, 93.5, 94.3, 95, 98.3, 101.9};
int num_stat= sizeof(stations)/sizeof(float);
char c;
void loop()
{ 
if(Serial.available()) 
{ 
c=Serial.read(); 
if(c =='b' || c=='f') 
changeStation(); 
}
}

void changeStation()
{ 
radio.setFrequency(stations[i]); 
lcd.clear(); lcd.setCursor(0,0); 
lcd.print("FM Radio: "); 
lcd.setCursor(0,1); 
lcd.print(stations[i]); 
lcd.setCursor(6,1); 
lcd.print("MHz"); 
if(c=='f’) 
i=(i+1)%num_stat; 
if(c=='b') 
i=(num_stat+i-1)%num_stat;
}

#include<stdio.h>
int red=D0;
int green=D1;
int blue=D2;

void setup()
{
  // pinMode(SW,INPUT_PULLUP);
  // pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  Serial.begin(9600);
//   // put your setup code here, to run once:
}

void loop() 
{
//   // put your main code here, to run repeatedly:
  digitalWrite(red,0);
  Serial.println("red led on");
  // digitalWrite(green,1);
  // digitalWrite(blue,1);
  digitalWrite(red,1);
  Serial.println("red led off");
  // digitalWrite(green,0);
  // digitalWrite(blue,1);
  delay(1000);

  // digitalWrite(red,1);
  // digitalWrite(green,1);
  // digitalWrite(blue,0);
  // delay(1000);

  // digitalWrite(red,0);
  // digitalWrite(green,1);
  // digitalWrite(blue,0);
  // delay(1000);

  // digitalWrite(red,1);
  // digitalWrite(green,0);
  // digitalWrite(blue,0);
  // delay(1000);

  // digitalWrite(red,0);
  // digitalWrite(green,0);
  // digitalWrite(blue,1);
  // delay(1000);

  // digitalWrite(red,0);
  // digitalWrite(green,0);
  // digitalWrite(blue,0);
  // delay(1000);
}

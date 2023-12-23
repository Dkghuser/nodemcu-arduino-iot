#include<stdio.h>
  int red=D0;
  int green=D1;
  int blue=D2;
  int SW=D3;
  int val;
  int count=0;
void setup()
{
  pinMode(SW,INPUT_PULLUP);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  Serial.begin(9600);
  digitalWrite(red,1);
  digitalWrite(green,1);
  digitalWrite(blue,1);
//   // put your setup code here, to run once:
}
void loop() {
  val=digitalRead(SW);

  if(val==0)
  { 
    count=count+1;
    Serial.print(count);
    if(count==1)
    {

      digitalWrite(red,0);
      digitalWrite(blue,1);
      digitalWrite(green,1);
      Serial.print("red");
    }
    else if(count==2)
    {
      digitalWrite(red,1);
      digitalWrite(blue,1);
      digitalWrite(green,0);
      Serial.print("green");
    }
    else if(count==3)
    {
      digitalWrite(red,1);
      digitalWrite(blue,0);
      digitalWrite(green,1);
      Serial.print("blue");
    }
    else 
    {
      digitalWrite(red,1);
      digitalWrite(blue,1);
      digitalWrite(green,1);
      count=0;
      
    }
  }
  delay(250);
}
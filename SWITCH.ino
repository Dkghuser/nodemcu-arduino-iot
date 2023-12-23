#include<stdio.h>
  int SW=D3;
  int val;
void setup()
{
  pinMode(SW,INPUT_PULLUP);
  Serial.begin(9600);
//   // put your setup code here, to run once:
}

void loop() 
{
//   // put your main code here, to run repeatedly:
  val=digitalRead(SW);
  // Serial.println(val);
  if(val==0)
  {
    Serial.println("switch is pressed");
    delay(500);
  }
  else
  {
    Serial.println("switch is not pressed");
  }
}
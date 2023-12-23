#include<stdio.h>
int a=D0;
int b=D1;
int c=D2;
int d=D3;
int e=D4;
int f=D5;
int g=D6;
void setup()
{
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}
void loop() {
  Serial.println("led on a");
  digitalWrite(a,0);
  Serial.println("led on b");
  digitalWrite(b,0);
  Serial.println("led on c");
  digitalWrite(c,0);
  Serial.println("led on d");
  digitalWrite(d,0);
  Serial.println("led on e");
  digitalWrite(e,0);
  Serial.println("led on f");
  digitalWrite(f,0);
  Serial.println("led on g");
  digitalWrite(g,0);
  delay(250);
}
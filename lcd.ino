#include<stdio.h>
#include<LiquidCrystal.h>
int rs=D0,en=D1,d4=D4,d5=D5,d6=D6,d7=D7;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
 void setup()
{
  lcd.begin(16,2);
  pinMode(d4,OUTPUT);
  pinMode(d5,OUTPUT);
  pinMode(d6,OUTPUT);
  pinMode(d7,OUTPUT);
  pinMode(rs,OUTPUT);
  pinMode(en,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop()
{
  int b;
  int i;
  int j;
  while(Serial.available()==0){  }
  int a = Serial.parseInt();
  Serial.println(a);
  b=a%2;
  if(a==1)
  {
    lcd.clear();
  }
  else if(b==0)
  {
   lcd.setCursor(i,0);
   {
     lcd.print(a);
     i=i+2;
   }
  }
  else
  {     
   lcd.setCursor(j,1);  
   {
     lcd.print(a);
     j=j+2;
   }  
  }
}

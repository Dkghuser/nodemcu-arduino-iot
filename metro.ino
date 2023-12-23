#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN D3  // Configurable, see typical pin layout above
#define SS_PIN D4   // Configurable, see typical pin layout above
int totalamount = 200;
int amount=0;
int a,b,c,d;
int src,dest;
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

MFRC522::MIFARE_Key key;
String tag;
void setup() 
{
  Serial.begin(9600);  // Initialize serial communications with the PC
  while (!Serial);                     // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();                        // Init SPI bus
  mfrc522.PCD_Init();                 // Init MFRC522
  delay(4);                           // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
 Serial.println("     Source ------------------> Destination  ");
 //  Serial.println(" ----------------------------------------------------");
 Serial.println("1. Kengeri stn     -------------> 1. Majestic stn");
 Serial.println("2. Rajajinagar stn -------------> 2. Nagasandra stn");
  //  Serial.println("----------------------------------------------------");
 Serial.println("Swipe the Card");
  // delay(6000);
}
void loop()
{
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.

  // while(Serial.available()==0){  }
  // int val = Serial.parseInt();
  // Serial.println(val);
 if (!mfrc522.PICC_IsNewCardPresent())
  {
   return;
  }
  // Select one of the cards
 if (!mfrc522.PICC_ReadCardSerial()) 
 {
    for (byte i=0; i<4; i++)
    {
      tag += mfrc522.uid.uidByte[i];
    }
    Serial.println(tag);
    if(tag=="2271223746")
    {
      Serial.println("Successfully Card is verified");
      Serial.println("your card balance is(in Rs.): ");
      Serial.println(totalamount);
      // Serial.println("----------------------------------------------------");
      Serial.println("Enter the Source station: ");
      while(Serial.available()==0){ }
      src = Serial.parseInt();
      Serial.println(src);
      if(src==1)
      {
        Serial.println("Selected Source stn: 1. Kengeri stn");
      }
      else if(src==2)
      {
        Serial.println("Selected Source stn: 2. Rajajinagar stn");
      }
      Serial.println("Enter the Destination station: ");
      while(Serial.available()==0){ }
      dest = Serial.parseInt();
      Serial.println(dest);
      if(dest==1)
      {
        Serial.println("Selected Destination stn: 1. Majestic stn");
      }
      else if(dest==2)
      {
        Serial.println("Selected Destination stn: 2. Nagasandra stn");
      }
      Serial.println("Swipe the Card");
      // for (byte i=0; i<4; i++)
      // {
      //   tag += mfrc522.uid.uidByte[i];
      // }
      Serial.println(tag);
      if(tag=="2271223746")
      {
        Serial.println("Successfully Card is verified");
        if(src==1 && dest==1)
        {
          amount=20;
          c=totalamount-amount;
          Serial.println("balance amount:Rs. ");
          Serial.println(c);
          Serial.println("deducted amount:Rs. ");
          Serial.println(amount);
        }
        else if(src==1 && dest==2)
        {
          amount=40;
          c=totalamount-amount;
          Serial.println("balance amount:Rs. ");
          Serial.println(c);
          Serial.println("deducted amount:Rs. ");
          Serial.println(amount);
        }
        else if(src==2 && dest==1)
        {
          amount=25;
          c=totalamount-amount;
          Serial.println("balance amount:Rs. ");
          Serial.println(c);
          Serial.println("deducted amount:Rs. ");
          Serial.println(amount);
        }
        else if(src==2 && dest==2)
        {
          amount=30;
          c=totalamount-amount;
          Serial.println("balance amount:Rs. ");
          Serial.println(c);
          Serial.println("deducted amount:Rs. ");
          Serial.println(amount);
        }
        else
        {
          Serial.println("Wrong selection");
        }
        if(totalamount<=20)
        {
          Serial.println("Please Recharge your card!");
        }
        else
        {
          Serial.println("Happy journey!");
        }
      }
    }
    else
    {
      Serial.println("Access denied");
    }
  }
//  Serial.println(" ---------------------------------------------------- ");
 tag = "";
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
}

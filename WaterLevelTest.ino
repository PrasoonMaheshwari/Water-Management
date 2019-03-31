#include <LiquidCrystal.h>

#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(3,2);

int level1=A2;
int level2=A3;
//int level3=A3;
//int level4=A4;
//int level5=A5;
int motor=6;
int a;
int b;
//int c;
//int d;
//int e;
//int r; //Water Pump status flag
//int m=0; //water Pump flag
int z=111; // Adjust this value from 100 to 1023 if your circuit do not show correct value. 
//  
//
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
pinMode(level1,INPUT);
pinMode(level2,INPUT);
//pinMode(level3,INPUT);
//pinMode(level4,INPUT);
//pinMode(level5,INPUT);
pinMode(motor,OUTPUT);
//lcd.begin(20, 4); // if you are using 16x2 line LCD, then replace these values and also adjust all LCD text for 1st and 2nd line in the loop below. 
Serial.begin(9600);

ArduinoUno.begin(4800);
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);
}

void loop()
{
  //r=digitalRead(motor);
  a=analogRead(level1);
  b=analogRead(level2);
  delay(500);
  Serial.println(a);
  delay(500);
  Serial.println(b);
  delay(1000);
  int flag=0;
  if(a<50 && b<50)
  {
    while(b<50)
    {
        Serial.println("FLOW IN!");
        b=analogRead(level2);
        delay(500);
        digitalWrite(motor,HIGH);
        Serial.println(b);
    }
    flag=1;
           digitalWrite(motor,LOW);
                  Serial.println("STOP");

  }
  else
  {
        digitalWrite(motor,LOW);
  }
//
    if(flag==1)
  {
    ArduinoUno.print("1");
    ArduinoUno.println("\n");
  }
  else
  {
    ArduinoUno.print("0");
    ArduinoUno.println("\n");
  }  

//  
  //c=analogRead(level3);
  //d=analogRead(level4);
  //e=analogRead(level5);
  //lcd.clear();
  //lcd.setCursor(2,0);              
  //lcd.print("Easy HM Projects");   
  //lcd.setCursor(0,1);              
  //lcd.print("Water Level Monitor.");

  
}

#include<SoftwareSerial.h>

#define DIR1A 24    //Motor 1(Motor)
#define DIR1B 25 
#define PWM1  6    //Motor 1 (L298N) PWM

#define DIR2A 22    //Motor 2
#define DIR2B 23
#define PWM2  5    //Motor 2 PWM

#define DIR3A 26   //Motor 3
#define DIR3B 27
#define PWM3   7   //Motor 3 PWM

float Vx,Vy;
float V1,V2,V3;

const int ledPin=12;
char ch;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
//motor set
 pinMode(DIR1A,OUTPUT);
  pinMode(DIR1B,OUTPUT);
  pinMode(DIR2A,OUTPUT);
  pinMode(DIR2B,OUTPUT);
  pinMode(DIR3A,OUTPUT);
  pinMode(DIR3B,OUTPUT);
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(PWM3,OUTPUT);
  
  pinMode(PWM1,0);
  pinMode(PWM2,0);
  pinMode(PWM3,0);
}  

void Forward(float speed)      //前进，Y轴上下移动
{
  Vy = - speed;
  
  V1 = - sqrt(3)/2 * Vy;
  V2 = sqrt(3)/2 * Vy;
  
  digitalWrite(DIR1A,HIGH);
  digitalWrite(DIR1B,LOW);
  analogWrite(PWM1, V1);
  
  digitalWrite(DIR2A,LOW);
  digitalWrite(DIR2B,HIGH);
  analogWrite(PWM2,- V2); 
  
  analogWrite(PWM3,0); 
}

void Back(float speed)          //后退，Y轴上下移动
{
  Vy = - speed;
  V1 = - sqrt(3)/2 * Vy;
  V2 = sqrt(3)/2 * Vy;
  
  digitalWrite(DIR1A,LOW);
  digitalWrite(DIR1B,HIGH);
  analogWrite(PWM1, V1);
  
  digitalWrite(DIR2A,HIGH);
  digitalWrite(DIR2B,LOW);
  analogWrite(PWM2, - V2); 

  analogWrite(PWM3,0);
}

void Right(float speed)        //右平移，X轴移动
{
  Vx = speed;
  V1 = - 0.5 * Vx - 0.86 * Vy;
  V2 = - 0.5 * Vx + 0.86 * Vy;
  V3 = Vx;
  
  digitalWrite(DIR1A,HIGH);
  digitalWrite(DIR1B,LOW);
  analogWrite(PWM1, - V1);
  
  digitalWrite(DIR2A,HIGH);
  digitalWrite(DIR2B,LOW);
  analogWrite(PWM2, - V2); 
  
  digitalWrite(DIR3A,LOW);
  digitalWrite(DIR3B,HIGH);
  analogWrite(PWM3,V3);
}

void Left(float speed)         //左平移，X轴移动
{
  Vx = speed;
  V1 = - 0.5 * Vx - 0.86 * Vy;
  V2 = - 0.5 * Vx + 0.86 * Vy;
  V3 = Vx;
  
  digitalWrite(DIR1A,LOW);
  digitalWrite(DIR1B,HIGH);
  analogWrite(PWM1,- V1);
  
  digitalWrite(DIR2A,LOW);
  digitalWrite(DIR2B,HIGH);
  analogWrite(PWM2,- V2); 
  
  digitalWrite(DIR3A,HIGH);
  digitalWrite(DIR3B,LOW);
  analogWrite(PWM3,V3);
}

void Stop()            //停止
{
  analogWrite(PWM1,0);
  analogWrite(PWM2,0); 
  analogWrite(PWM3,0);
}

void loop() 
{
while (Serial.available()>0)
{
    ch=Serial.read();
    if (ch=='F')
      {
        Forward(100);delay(2000);
        Serial.print("Forward");
        delay(100);
      }
    if (ch=='B')
      {
        Back(100);   delay(2000);
        Serial.print("Back");
        delay(100);
      }
    if (ch=='L')
      {
        Left(100);   delay(2000);
        Serial.print("Left");
        delay(100);
      }
    if (ch=='R')
      {
        Right(100);  delay(2000);
        Serial.print("Right");
        delay(100);
      }
    if (ch=='S')
      {
        Stop();  delay(2000);
        Serial.print("Stop");
        delay(100);
      }
}
}

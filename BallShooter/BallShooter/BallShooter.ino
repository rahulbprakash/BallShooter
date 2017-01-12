#include <Servo.h>
#define echoPin 7
#define trigPin 8
long duration, distance;
Servo myservo;
Servo myservo2;
int motor_left[] = {2, 4};
int motor_right[] = {12, 10};
int enablePin = 6;
int enablePin2 = 11;

void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(3);
  myservo2.attach(5);
  int i;
  for(i = 0; i < 2; i++)
  {
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
  }
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.println(distance);
  myservo.write(155);
  myservo2.write(25);
  int s;
  //map speed
  s = map(distance,0,101,83,254);
  drive_forward(s);
  //map angle
  /*
  a = map(distance,0,101,0,180);
  myservo.write(a);
  myservo2.write(180-a);    
  */
  delay(1500);
}

void drive_forward(int s)
{
  analogWrite(enablePin, s);
  analogWrite(enablePin2,s);
  digitalWrite(motor_left[1], LOW);
  digitalWrite(motor_left[0], HIGH);
  digitalWrite(motor_right[1], LOW);
  digitalWrite(motor_right[0], HIGH);
}

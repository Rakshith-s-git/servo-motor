#include <Servo.h>
Servo servo1;
int trigPin = 8;
int echoPin = 9;
long distance;
long duration;
 
void setup() 
{
servo1.attach(10); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);// put your setup code here, to run once:
}
 
void loop() {
  ultra();
  servo1.write(0);
  if(distance <= 10){
  servo1.write(90);
  }
}
 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
  }

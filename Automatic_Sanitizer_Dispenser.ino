#include <Servo.h>
Servo myservo;

const int trigPin = 6;
const int echoPin = 5;
const int led = 13; 

long duration;
int distance;

void setup() {
myservo.attach(9);
myservo.write(45);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
Serial.begin(9600); 
}
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);

if (distance < 8){
  myservo.write(120);
  digitalWrite(led, HIGH);
}
else {
  myservo.write(45);
  digitalWrite(led,LOW);
}
}

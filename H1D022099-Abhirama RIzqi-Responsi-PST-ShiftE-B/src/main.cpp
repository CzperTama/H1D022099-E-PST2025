#include <Arduino.h>
#include <Servo.h>

//deklarasi variabel
int echoPin = D3;
int trigPin = D1;
int ledPin = D4;

//deklarasi variabel waktu dan jarak
long duration;
int distance;
Servo myservo;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  myservo.attach(D7);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //untuk menghitung waktu sinyal diterima
  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;
  //display serial number
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm");

  //set berdasarkan kondisi
  if (distance  >= 15) {
    myservo.write(90);
  } else{
    myservo.write(0);
  }
  delay(1000);
}
#include <Arduino.h>

//deklarasi variabel
int echoPin = D3;
int trigPin = D1;
int ledPin = D7;

//deklarasi variabel waktu dan jarak
long duration;
int distance;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

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
  if (distance  <= 10) {
    digitalWrite(ledPin, HIGH);
  } else{
    digitalWrite(ledPin, LOW);
  }
  delay(1000);
}
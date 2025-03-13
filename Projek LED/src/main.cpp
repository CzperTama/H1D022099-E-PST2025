#include <Arduino.h>

int LED1 = D0;
int LED2 = D2;
int LED3 = D7;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(50);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(50);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(50);
  digitalWrite(LED3, LOW);
}
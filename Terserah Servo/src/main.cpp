#include <Arduino.h>
#include <Servo.h>

// deklarasi objek servo
Servo myservo;

void setup() {
  // fungsi untuk menghubungkan servo pada pin arduino.
  myservo.attach(D7);
}

// perulangan yang digunakan untuk menggerakan servo
void loop() {
  // fungsi yang menggerakan servo dari posisi 0 derajat ke 180 derajat dan kembali ke 0 derajat secara bertahap.
  // for(int pos = 0; pos<=180; pos++){
  //   myservo.write(pos);
  //   delay(10);
  // }
  // for(int pos=180; pos>=0; pos--){
  //   myservo.write(pos);
  //   delay(10);
  // }

  // fungsi yang menggerakan servo dari posisi 180 derajat ke 0 derajat dan kembali ke 180 derajat, dengan jeda 2 detik pada setiap posisi.
  myservo.write(180);
  delay(2000);
  myservo.write(0);
  delay(2000);
  myservo.write(180);
  delay(2000);
}

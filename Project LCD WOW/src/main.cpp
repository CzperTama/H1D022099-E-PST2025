#include <Arduino.h>
#include <Wire.h>

int SDA_pin = D2;
int SCL_pin = D4;

void setup() {
  Wire.begin(SDA_pin,SCL_pin);
  Serial.begin(9600);
}

void loop() {
  byte error, addres;
  int nDevices;

  Serial.print("Scanning...");
  nDevices = 0;

  for(addres = 1; addres<127; addres++){
    Wire.beginTransmission(addres);
    error=Wire.endTransmission();

    if(error == 0){
      Serial.print("l2C terbaca pada alamat 0x");
      if(addres<16){
        Serial.print("0");
      }
      Serial.print(addres,HEX);
      Serial.println("...!");

      nDevices++;
    }else if(error == 4){
      Serial.print("Ada error yang tidak diketahui di alamat 0x");
      if(addres<16){
        Serial.print("0");
      }
      Serial.print(addres,HEX);
    }
  }

  if(nDevices == 0){
    Serial.println("Tidak ada alamat yang terdeteksi");
  } else{
    Serial.println("Selesai");
  }
  delay(5000);
}
/*
  I2C Pinouts
  SDA -> A4
  SCL -> A5
*/

#include <Wire.h> //Import the library required

#define SLAVE_ADDRESS 0x04 //Slave Address for the Communication
char number[50];
int Temperature1=0;
int Temp1val=0;
int Temp1Pin = A1;

void setup() {
  // initialize i2c as slave
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);
  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
}


void loop() {
  ReadTempInner();
  delay(100);
} // end loop


// callback for received data
void receiveData(int byteCount) {
  int i = 0;
  while (Wire.available()) {
    number[i] = Wire.read();
    i++;
  }
  number[i] = '\0';
  Serial.print(number);
}  // end while


// callback for sending data
void sendData() {
  Wire.write(Temperature1);
}
void ReadTempInner(){
  Temp1val = analogRead(Temp1Pin);
  float Calc1 = ( Temp1val/1024.0)*5000;
  Temperature1 = Calc1/10;
  /*Serial.println(Temperature1); //For Debugging
  delay(1000); //For Debugging*/
}

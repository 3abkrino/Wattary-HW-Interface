/*
  I2C Pinouts
  SDA -> A4
  SCL -> A5
*/

#include <Wire.h> //Import the library required
#include <Servo.h> // Include the Servo library 

#define SLAVE_ADDRESS 0x04 //Slave Address for the Communication

int ElevatorServoPin = 9, CurtainInnerRightServoPin = 11, CurtainInnerLeftServoPin = 10, x = 0, y = 2, Upstate = 1; // Declare the Servo pin and the State Variable
Servo ElevatorServo, CurtainInnerRightServo, CurtainInnerLeftServo; // Create a servo objects
char number[50];
int Temperature1 = 0;
int Temp1val = 0;
int Temp1Pin = A1;

void setup() {
  ElevatorServo.attach(ElevatorServoPin); //attach the servo to the used pin number
  attachInterrupt(0, Limit, FALLING); //attach the Interrupt  Function "Test" to (pin number 2 arduino uno) "Interrupt0" and calling State when "Falling"
  CurtainInnerRightServo.attach(CurtainInnerRightServoPin); //attach the servo to the used pin number
  CurtainInnerLeftServo.attach(CurtainInnerLeftServoPin); //attach the servo to the used pin number
  Serial.begin(9600); //Start the Serial For Debugging
  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);
  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
}


void loop() {
  ReadTempInner();

  ElevatorServo.write(90);
  //Serial.println("Elevator                         Stop");
  CurtainInnerRightServo.write(90);
  CurtainInnerLeftServo.write(90);
  //Serial.println(number);
  switch (number[0]) {
    case 102:
      up();
      break;
    case 68:
      down();
      break;
    case 66:
      Open();
      break;
    case 67:
      Close();
      break;
  }
  number[0] = 5;
  DownAbit();

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


void ReadTempInner() {
  Temp1val = analogRead(Temp1Pin);
  float Calc1 = ( Temp1val / 1024.0) * 5000;
  Temperature1 = Calc1 / 10;
  /*Serial.println(Temperature1); //For Debugging
    delay(1000); //For Debugging*/
}

void Limit() {
  if (Upstate == 1)
    ElevatorServo.write(90); // Make Servo Stop
  x = 1;
  y = 2;
  Upstate = 0;
  //DownAbit();
  Serial.println("Test End");
}

void DownAbit() {
  if (x == 1 & y == 2) {
    ElevatorServo.write(180);
    delay(1000);
    x = 0;
    y = 1;
    Serial.println("DownAbit");
  }
}
void up() {
  Serial.println("up");
  Upstate = 1;
  if (digitalRead(2) == HIGH) {
    ElevatorServo.write(0);  // Make servo go to UP
    delay(6500);      // For 6.5 Seconds
  }
  Serial.println("up END");
}

void down() {
  Serial.println("Down");
  ElevatorServo.write(180);// Make servo go to Down
  delay(5000);      // For 5 Seconds

}

void Stop() {
  ElevatorServo.write(90); // Make Servo Stop
  delay(1000);      // For 1 Second
}


void Open() {
  Serial.println("Open");
  CurtainInnerLeftServo.write(0);  // Make servo go to Left
  CurtainInnerRightServo.write(0);  // Make servo go to Left
  delay(3000);      // For 3 Seconds
  Stop2();
}

void Close() {
  Serial.println("Close");
  CurtainInnerLeftServo.write(180);// Make servo go to Right
  CurtainInnerRightServo.write(180);// Make servo go to Right
  delay(3000);      // For 3 Seconds
  Stop2();
}

void Stop2() {
  CurtainInnerLeftServo.write(90); // Make Servo Stop
  CurtainInnerRightServo.write(90); // Make Servo Stop
  delay(1000);      // For 1 Second
}

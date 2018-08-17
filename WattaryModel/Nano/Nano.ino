/*
  I2C Pinouts
  SDA -> A4
  SCL -> A5
*/
//Import the library required
#include <Wire.h>
//Slave Address for the Communication
#define SLAVE_ADDRESS 0x05
/////////////////////////////Air Conditioner Functions///////////////////////////////
void ACon();
void ACoff();
void temp27();
void temp26();
void temp25();
void temp24();
void temp23();
void temp22();
void temp21();
void temp20();
/////////////////////////////TV Functions///////////////////////////////
void TVOnOff();
void TVMute();
void TVChannelUp();
void TVChannelDown();
void TVVolumeUp();
void TVVolumeDown();
void Channel0();
void Channel1();
void Channel2();
void Channel3();
void Channel4();
void Channel5();
void Channel6();
void Channel7();
void Channel8();
void Channel9();
////////////////////////////////////////////////////////////////////////
int IRledPin =  13;    // LED connected to digital pin 13
char number[50];
int temperature = 10;
int val;
int tempPin = 1;


void setup()   {
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);
  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
}

void loop()
{
  ReadTempOuter();

  switch (Serial.parseInt()) {
    case 1:
      ACon();//////////on
      break;
    case 2:
      ACoff();//////////off
      break;
    case 3:
      temp27();//////////temp27
      break;
    case 4:
      temp26();
      break;
    case 5:
      temp25();
      break;
    case 6:
      //temp24();
      break;
    case 7:
      //temp23();
      break;
    case 8:
      temp22();
      break;
    case 9:
      temp21();
      break;
    case 10:
      temp20();
      break;
/////////////////////////////////////////////////////////////////////
    case 11:
      TVOnOff();
      break;
    case 12:////////////////////////mute
      TVMute();
      break;
    case 13:
      TVChannelUp();
      break;
    case 14:
      TVChannelDown();
      break;
    case 15:
      TVVolumeUp();
      break;
    case 16:
      TVVolumeDown();
      break;
    case 17:
      Channel0();
      break;
    case 18:
      Channel1();
      break;
    case 19:
      Channel2();
      break;
    case 20:
      Channel3();
      break;
    case 21:
      Channel4();
      break;
    case 22:
      Channel5();
      break;
    case 23:
      Channel6();
      break;
    case 24:
      Channel7();
      break;
    case 25:
      Channel8();
      break;
    case 26:
      Channel9();
      break;
  }
}

// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseiR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait

  cli();  // this turns off any background interrupts

  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
    digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
    delayMicroseconds(10);         // hang out for 10 microseconds
    digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
    delayMicroseconds(10);         // hang out for 10 microseconds

    // so 26 microseconds altogether
    microsecs -= 26;
  }

  sei();  // this turns them back on
}


void ACoff() {
  delayMicroseconds(2688); pulseiR(4040);
  delayMicroseconds(1880); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1380); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(1400); pulseiR(560);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(560);
  delayMicroseconds(1380); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(440); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(1380); pulseiR(580);
  delayMicroseconds(1360); pulseiR(600);
  delayMicroseconds(360); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(480); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1460); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1380); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
}


void ACon() {
  delayMicroseconds(42284); pulseiR(4040);
  delayMicroseconds(1880); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(480); pulseiR(480);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(1460); pulseiR(500);
  delayMicroseconds(440); pulseiR(580);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1380); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(560);
  delayMicroseconds(1400); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(480); pulseiR(520);
  delayMicroseconds(440); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(560);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(480); pulseiR(480);
  delayMicroseconds(480); pulseiR(520);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1380); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1460); pulseiR(480);
  delayMicroseconds(480); pulseiR(560);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);

}
void temp27() {
  delayMicroseconds(18700); pulseiR(4040);
  delayMicroseconds(1880); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(400); pulseiR(600);
  delayMicroseconds(1400); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1400); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(700);
  delayMicroseconds(1240); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(400); pulseiR(540);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(560);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(360); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(420); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1380); pulseiR(540);
  delayMicroseconds(1440); pulseiR(540);
  delayMicroseconds(400); pulseiR(540);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(580);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
}


void temp26() {
  delayMicroseconds(30992); pulseiR(4040);
  delayMicroseconds(1880); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(1440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1400); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(440); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(1400); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(400); pulseiR(600);
  delayMicroseconds(1360); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(1400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(400); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1380); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(400); pulseiR(540);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(560);
  delayMicroseconds(1380); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
}


void temp25() {
  delayMicroseconds(43860); pulseiR(4040);
  delayMicroseconds(1880); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(480); pulseiR(540);
  delayMicroseconds(1400); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(480); pulseiR(480);
  delayMicroseconds(480); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(460); pulseiR(580);
  delayMicroseconds(400); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(480); pulseiR(480);
  delayMicroseconds(480); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(480); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(440); pulseiR(560);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(500);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
}


void temp24() {
  delayMicroseconds(48852); pulseiR(4040);
  delayMicroseconds(1880); pulseiR(520);
  delayMicroseconds(460); pulseiR(560);
  delayMicroseconds(1380); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(1380); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(1380); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1380); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(420); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(560);
  delayMicroseconds(1380); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(400); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(560);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1360); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(380); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(400); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1380); pulseiR(580);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1400); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(580);
  delayMicroseconds(400); pulseiR(560);
}


void temp23() {
  delayMicroseconds(52880); pulseiR(4040);
  delayMicroseconds(1880); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(1440); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(480); pulseiR(480);
  delayMicroseconds(480); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(580);
  delayMicroseconds(380); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1460); pulseiR(500);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(480); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(480); pulseiR(500);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(480); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1460); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
}


void temp22() {
  delayMicroseconds(27788); pulseiR(4020);
  delayMicroseconds(1900); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(480); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1380); pulseiR(540);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(480); pulseiR(560);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(560);
  delayMicroseconds(400); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1460); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(480); pulseiR(480);
  delayMicroseconds(480); pulseiR(520);
  delayMicroseconds(460); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(1460); pulseiR(500);
  delayMicroseconds(440); pulseiR(580);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
}


void temp21() {
  delayMicroseconds(15024); pulseiR(4000);
  delayMicroseconds(1920); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(480); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(1400); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(480); pulseiR(480);
  delayMicroseconds(480); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(580);
  delayMicroseconds(380); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(1460); pulseiR(500);
  delayMicroseconds(480); pulseiR(480);
  delayMicroseconds(480); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(480); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(480); pulseiR(500);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
}


void temp20() {
  delayMicroseconds(59256); pulseiR(4000);
  delayMicroseconds(1920); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(480); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(1400); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(1400); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(460); pulseiR(560);
  delayMicroseconds(400); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(1460); pulseiR(500);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(480); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(1380); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(500);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(480); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(440); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(400); pulseiR(560);
  delayMicroseconds(1400); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(480); pulseiR(500);
  delayMicroseconds(1420); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(440); pulseiR(520);
  delayMicroseconds(460); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(1440); pulseiR(520);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(1440); pulseiR(540);
  delayMicroseconds(1400); pulseiR(540);
  delayMicroseconds(420); pulseiR(560);
  delayMicroseconds(420); pulseiR(540);
  delayMicroseconds(440); pulseiR(540);
  delayMicroseconds(420); pulseiR(520);
  delayMicroseconds(460); pulseiR(500);
  delayMicroseconds(1440); pulseiR(500);
  delayMicroseconds(1440); pulseiR(520);
}















/////////////////////////////////////////////////////////////////////////TV/////////////////////////////////////////////////////////////////////////////
void TVOnOff() {
  delayMicroseconds(13696); pulseiR(9360);
  delayMicroseconds(4540); pulseiR(660);
  delayMicroseconds(500); pulseiR(640);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(640);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(640);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(1680); pulseiR(620);
  delayMicroseconds(1680); pulseiR(640);
  delayMicroseconds(1660); pulseiR(660);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(1660); pulseiR(660);
  delayMicroseconds(1640); pulseiR(660);
  delayMicroseconds(1680); pulseiR(600);
  delayMicroseconds(1700); pulseiR(660);
  delayMicroseconds(500); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(660);
  delayMicroseconds(1640); pulseiR(640);
  delayMicroseconds(520); pulseiR(660);
  delayMicroseconds(520); pulseiR(600);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(660);
  delayMicroseconds(500); pulseiR(600);
  delayMicroseconds(540); pulseiR(640);
  delayMicroseconds(520); pulseiR(660);
  delayMicroseconds(1640); pulseiR(620);
  delayMicroseconds(1700); pulseiR(620);
  delayMicroseconds(1680); pulseiR(660);
  delayMicroseconds(40960); pulseiR(9360);
  delayMicroseconds(2240); pulseiR(600);
}


void TVMute() {
  delayMicroseconds(46408); pulseiR(9320);
delayMicroseconds(4580); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(600);
delayMicroseconds(1700); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1720); pulseiR(600);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(540); pulseiR(600);
delayMicroseconds(1700); pulseiR(620);
delayMicroseconds(540); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(500); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(1720); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(40980); pulseiR(9320);
delayMicroseconds(2260); pulseiR(640);

}



void TVChannelUp() {
  delayMicroseconds(39628); pulseiR(9340);
  delayMicroseconds(4540); pulseiR(660);
  delayMicroseconds(540); pulseiR(600);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(520); pulseiR(620);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(540); pulseiR(600);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(620);
  delayMicroseconds(1680); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(640);
  delayMicroseconds(1680); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(620);
  delayMicroseconds(1680); pulseiR(640);
  delayMicroseconds(1680); pulseiR(600);
  delayMicroseconds(540); pulseiR(640);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(540); pulseiR(600);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(520); pulseiR(620);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(620);
  delayMicroseconds(1680); pulseiR(640);
  delayMicroseconds(1680); pulseiR(620);
  delayMicroseconds(1680); pulseiR(640);
  delayMicroseconds(40980); pulseiR(9340);
  delayMicroseconds(2260); pulseiR(600);
}


void TVChannelDown() {
delayMicroseconds(39640); pulseiR(9340);
delayMicroseconds(4560); pulseiR(640);
delayMicroseconds(540); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(540); pulseiR(600);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1700); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1700); pulseiR(640);
delayMicroseconds(520); pulseiR(600);
delayMicroseconds(1700); pulseiR(640);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(520); pulseiR(600);
delayMicroseconds(540); pulseiR(640);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(40980); pulseiR(9340);
delayMicroseconds(2260); pulseiR(620);
delayMicroseconds(33284); pulseiR(9340);
delayMicroseconds(2260); pulseiR(640);
delayMicroseconds(33264); pulseiR(9340);
delayMicroseconds(2260); pulseiR(640);
delayMicroseconds(33264); pulseiR(9360);
delayMicroseconds(2240); pulseiR(600);

}


void TVVolumeUp() {
delayMicroseconds(37260); pulseiR(9300);
delayMicroseconds(4600); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(660);
delayMicroseconds(500); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(660);
delayMicroseconds(500); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(660);
delayMicroseconds(1640); pulseiR(620);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(1640); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(1640); pulseiR(620);
delayMicroseconds(1700); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(500); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(660);
delayMicroseconds(1640); pulseiR(620);
delayMicroseconds(540); pulseiR(660);
delayMicroseconds(1640); pulseiR(640);
delayMicroseconds(520); pulseiR(660);
delayMicroseconds(500); pulseiR(620);
delayMicroseconds(1680); pulseiR(660);
delayMicroseconds(1640); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);



}


void TVVolumeDown() {
delayMicroseconds(20572); pulseiR(9340);
delayMicroseconds(4540); pulseiR(660);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(500); pulseiR(640);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(660);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1660); pulseiR(660);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(660);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1660); pulseiR(640);

}


void Channel0() {

delayMicroseconds(32436); pulseiR(9320);
delayMicroseconds(4560); pulseiR(660);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(500); pulseiR(640);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(500); pulseiR(620);
delayMicroseconds(520); pulseiR(660);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(1640); pulseiR(660);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(1660); pulseiR(660);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(660);
delayMicroseconds(1640); pulseiR(660);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(1660); pulseiR(660);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(500); pulseiR(640);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(500); pulseiR(640);
delayMicroseconds(1660); pulseiR(660);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(40980); pulseiR(9340);
delayMicroseconds(2220); pulseiR(660);
delayMicroseconds(33284); pulseiR(9320);
delayMicroseconds(2240); pulseiR(660);


}


void Channel1() {
  delayMicroseconds(13428); pulseiR(9360);
  delayMicroseconds(4520); pulseiR(640);
  delayMicroseconds(540); pulseiR(660);
  delayMicroseconds(500); pulseiR(600);
  delayMicroseconds(540); pulseiR(640);
  delayMicroseconds(520); pulseiR(660);
  delayMicroseconds(500); pulseiR(640);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(600);
  delayMicroseconds(1700); pulseiR(660);
  delayMicroseconds(1640); pulseiR(640);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(660);
  delayMicroseconds(1640); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(660);
  delayMicroseconds(1640); pulseiR(640);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(540); pulseiR(660);
  delayMicroseconds(1640); pulseiR(620);
  delayMicroseconds(540); pulseiR(660);
  delayMicroseconds(500); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(540); pulseiR(660);
  delayMicroseconds(500); pulseiR(600);
  delayMicroseconds(1700); pulseiR(660);
  delayMicroseconds(1640); pulseiR(640);
  delayMicroseconds(520); pulseiR(660);
  delayMicroseconds(1640); pulseiR(640);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(660);
  delayMicroseconds(1640); pulseiR(660);
  delayMicroseconds(40960); pulseiR(9320);
  delayMicroseconds(2280); pulseiR(660);
}


void Channel2() {
  
delayMicroseconds(60624); pulseiR(9320);
delayMicroseconds(4580); pulseiR(620);
delayMicroseconds(540); pulseiR(660);
delayMicroseconds(500); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(660);
delayMicroseconds(500); pulseiR(600);
delayMicroseconds(540); pulseiR(640);
delayMicroseconds(520); pulseiR(660);
delayMicroseconds(500); pulseiR(600);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(1640); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(1640); pulseiR(620);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(1640); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(1640); pulseiR(640);
delayMicroseconds(520); pulseiR(660);
delayMicroseconds(500); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(520); pulseiR(660);
delayMicroseconds(1640); pulseiR(640);
delayMicroseconds(520); pulseiR(660);
delayMicroseconds(520); pulseiR(600);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(1640); pulseiR(620);
delayMicroseconds(41000); pulseiR(9360);
delayMicroseconds(2240); pulseiR(640);
}


void Channel3() {
  delayMicroseconds(18552); pulseiR(9340);
  delayMicroseconds(4540); pulseiR(660);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(620);
  delayMicroseconds(520); pulseiR(660);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(640);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(1640); pulseiR(660);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(1680); pulseiR(640);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(1680); pulseiR(640);
  delayMicroseconds(1660); pulseiR(660);
  delayMicroseconds(1640); pulseiR(660);
  delayMicroseconds(1680); pulseiR(620);
  delayMicroseconds(1680); pulseiR(640);
  delayMicroseconds(1660); pulseiR(660);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(1660); pulseiR(660);
  delayMicroseconds(1640); pulseiR(660);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(520); pulseiR(620);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(520); pulseiR(620);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(640);
  delayMicroseconds(1680); pulseiR(640);
  delayMicroseconds(1660); pulseiR(660);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(40980); pulseiR(9320);
  delayMicroseconds(2240); pulseiR(680);
}


void Channel4() {

delayMicroseconds(59928); pulseiR(9340);
delayMicroseconds(4540); pulseiR(660);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(500); pulseiR(640);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(500); pulseiR(640);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(660);
delayMicroseconds(1660); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(660);
delayMicroseconds(500); pulseiR(620);
delayMicroseconds(1680); pulseiR(660);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(500); pulseiR(640);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(500); pulseiR(640);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(660);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(1660); pulseiR(640);
delayMicroseconds(40980); pulseiR(9340);
delayMicroseconds(2260); pulseiR(620);


}


void Channel5() {
  delayMicroseconds(2228); pulseiR(9340);
  delayMicroseconds(4560); pulseiR(640);
  delayMicroseconds(520); pulseiR(600);
  delayMicroseconds(540); pulseiR(640);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(520); pulseiR(600);
  delayMicroseconds(540); pulseiR(640);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(520); pulseiR(620);
  delayMicroseconds(520); pulseiR(620);
  delayMicroseconds(1720); pulseiR(600);
  delayMicroseconds(1700); pulseiR(620);
  delayMicroseconds(1680); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(640);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(620);
  delayMicroseconds(1680); pulseiR(660);
  delayMicroseconds(500); pulseiR(620);
  delayMicroseconds(540); pulseiR(600);
  delayMicroseconds(1700); pulseiR(620);
  delayMicroseconds(1680); pulseiR(660);
  delayMicroseconds(500); pulseiR(640);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(500); pulseiR(660);
  delayMicroseconds(500); pulseiR(640);
  delayMicroseconds(1660); pulseiR(660);
  delayMicroseconds(1680); pulseiR(620);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(520); pulseiR(620);
  delayMicroseconds(1680); pulseiR(660);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(40980); pulseiR(9340);
  delayMicroseconds(2260); pulseiR(660);
}


void Channel6() {
delayMicroseconds(39768); pulseiR(9360);
delayMicroseconds(4540); pulseiR(660);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(500); pulseiR(620);
delayMicroseconds(520); pulseiR(660);
delayMicroseconds(500); pulseiR(660);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(500); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(1640); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(660);
delayMicroseconds(1660); pulseiR(620);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(1640); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(500); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(660);
delayMicroseconds(500); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(660);
delayMicroseconds(1640); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1700); pulseiR(660);
delayMicroseconds(40940); pulseiR(9360);
delayMicroseconds(2240); pulseiR(600);




}


void Channel7() {
  delayMicroseconds(43532); pulseiR(9320);
  delayMicroseconds(4560); pulseiR(640);
  delayMicroseconds(540); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(540); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(540); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(640);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(620);
  delayMicroseconds(1680); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(640);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(540); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(540); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(640);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(1660); pulseiR(640);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(620);
  delayMicroseconds(41000); pulseiR(9360);
  delayMicroseconds(2220); pulseiR(620);
}


void Channel8() {
  delayMicroseconds(47416); pulseiR(9320);
  delayMicroseconds(4560); pulseiR(640);
  delayMicroseconds(540); pulseiR(660);
  delayMicroseconds(500); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(540); pulseiR(660);
  delayMicroseconds(500); pulseiR(600);
  delayMicroseconds(540); pulseiR(640);
  delayMicroseconds(520); pulseiR(660);
  delayMicroseconds(500); pulseiR(600);
  delayMicroseconds(1700); pulseiR(660);
  delayMicroseconds(1660); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(660);
  delayMicroseconds(1640); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1720); pulseiR(640);
  delayMicroseconds(1640); pulseiR(640);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(540); pulseiR(640);
  delayMicroseconds(520); pulseiR(660);
  delayMicroseconds(500); pulseiR(620);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(1680); pulseiR(620);
  delayMicroseconds(520); pulseiR(640);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(540); pulseiR(620);
  delayMicroseconds(1700); pulseiR(600);
  delayMicroseconds(1700); pulseiR(660);
  delayMicroseconds(1640); pulseiR(620);
  delayMicroseconds(41000); pulseiR(9360);
  delayMicroseconds(2240); pulseiR(660);
}


void Channel9() {
  


delayMicroseconds(18308); pulseiR(9340);
delayMicroseconds(4540); pulseiR(660);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(520); pulseiR(640);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(1680); pulseiR(660);
delayMicroseconds(1660); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(600);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(620);
delayMicroseconds(540); pulseiR(600);
delayMicroseconds(1700); pulseiR(640);
delayMicroseconds(520); pulseiR(620);
delayMicroseconds(1680); pulseiR(640);
delayMicroseconds(1680); pulseiR(620);
delayMicroseconds(1700); pulseiR(600);
delayMicroseconds(41020); pulseiR(9300);
delayMicroseconds(2260); pulseiR(640);
delayMicroseconds(33304); pulseiR(9300);
delayMicroseconds(2260); pulseiR(640);


}


/////////////////////////////////////////////////////////////////////////TV/////////////////////////////////////////////////////////////////////////////
void receiveData(int byteCount) {
  int i = 0;
  while (Wire.available()) {
    number[i] = Wire.read();
    i++;
  }
  number[i] = '\0';
  Serial.print(number);
  //Serial.print("dffdfd");

}


void sendData() {
  Wire.write(temperature);
}


void ReadTempOuter() {
  val = analogRead(tempPin);
  float mv = ( val / 1024.0) * 5000;
  temperature = mv / 10;
  /*Serial.println(temperature); //For Debugging
    delay(1000); //For Debugging*/
}

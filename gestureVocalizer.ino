#include <SoftwareSerial.h>
// Constants:
int flexPin1 = A0; // to read analog input from the 1st flex sensor
int flexPin2 = A1; // to read analog input from the 2nd flex sensor
int flexPin3 = A2; // to read analog input from the 3rd flex sensor
int flexPin4 = A3; // to read analog input from the 4th flex sensor
int flexPin5 = A4; // to read analog input from the 5th flex sensor

// Variables:
int a; 
int b;
int c;
int d;
int e;

// Values from 3 contact sensors
int pinx = 12;
int piny = 8;
int pinz = 10;
int xpin = A0; // x-axis of the accelerometer
int ypin = A1; // y-axis
int zpin = A2; // z-axis (only on 3-axis models)

// Variables
int mappedX = 0;
int mappedY = 0;
int mappedZ = 0;
int pinxState = 0;
int pinyState = 0;
int pinzState = 0;

SoftwareSerial bluetooth(2, 3);  // RX, TX pins for Bluetooth module
void setup() {
  Serial.begin(9600);
  pinMode(pinx, INPUT);
  digitalWrite(pinx, HIGH);
  pinMode(piny, INPUT);
  digitalWrite(piny, HIGH);
  pinMode(pinz, INPUT);
  digitalWrite(pinz, HIGH);


  Serial.println("CLEARDATA");
  Serial.print("LABEL,F1,F2,F3,F4,F5,X,Y,Z,C1,C2");
  Serial.println();
}

void loop() {
  a = analogRead(flexPin1);
  b = analogRead(flexPin2);
  c = analogRead(flexPin3);
  d = analogRead(flexPin4);
  e = analogRead(flexPin5);

  mappedX = map(analogRead(xpin), 0, 1023, 0, 255);
  mappedY = map(analogRead(ypin), 0, 1023, 0, 255);
  mappedZ = map(analogRead(zpin), 0, 1023, 0, 255);

  pinxState = digitalRead(pinx);
  pinyState = digitalRead(piny);
  pinzState = digitalRead(pinz);
 if (a < 900 && b > 900 && c > 900 && d > 900 && e > 900 && a > 800) {
    bluetooth.println("a");
  }
  
  if (a > 900 && b < 900 && c < 900 && e < 900) {
    bluetooth.println("b");
  }
  
  if (a > 900 && b < 900 && c > 900 && d > 800 && e > 900) {
    bluetooth.println("d");
  }
  
  if (a > 900 && b > 900 && c > 900 && d > 900 && e > 900) {
    bluetooth.println("e");
  }
  
  if (a > 900 && b > 900 && c < 890 && e < 890) {
    bluetooth.println("f");
  }
  
  if (a < 900 && b < 900 && c > 890 && d > 890 && e > 890 && a > 800) {
    bluetooth.println("g");
  }
  
  if (a < 900 && b < 900 && c < 900 && d > 870 && e > 900) {
    bluetooth.println("h");
  }
  
  if (a > 900 && b > 900 && c > 900 && d > 900 && e < 900) {
    bluetooth.println("i");
  }
  
  if (a < 900 && b > 900 && c > 900 && d > 900 && e < 900 && a > 800) {
    bluetooth.println("j");
  }
  
  if (a > 900 && b < 900 && c < 900 && d > 900 && e > 900) {
    bluetooth.println("k");
  }
  
  if (a < 800 && b < 900 && c > 900 && d > 900 && e > 900) {
    bluetooth.println("l");
  }
  
  if (a < 800 && b > 900 && c > 900 && d > 900 && e < 900) {
    bluetooth.println("m");
  }
  
  if (a < 820 && b > 900 && c > 900 && d < 900 && e < 900) {
    bluetooth.println("n");
  }
  
  if (a > 820 && b < 900 && c < 900 && d < 900 && e > 900) {
    bluetooth.println("o");
  }
  
  if (a < 880 && b < 910 && c > 900 && d > 900 && e < 890) {
    bluetooth.println("p");
  }
  
  if (a < 850 && b < 900 && c > 900 && d < 920 && e < 890) {
    bluetooth.println("q");
  }
  
  if (a < 790 && b < 900 && c < 900 && d > 920 && e > 890) {
    bluetooth.println("r");
  }
  
  if (a < 960 && b > 900 && c > 900 && d > 920 && e > 890 && a > 940) {
    bluetooth.println("s");
  }
  
  if (a < 800 && b > 900 && d < 920 && e < 890) {
    bluetooth.println("t");
  }
  
  if (a > 900 && b < 900 && d > 900 && e < 900) {
    bluetooth.println("u");
  }
  
  if (a > 900 && b < 900 && d < 900 && e < 900 && c > 900) {
    bluetooth.println("v");
  }
  
  if (a < 900 && b < 900 && d < 900 && e < 900 && c > 900) {
    bluetooth.println("w");
  }
  
  if (a > 900 && b > 900 && d < 900 && e < 900 && c > 900) {
    bluetooth.println("x");
  }
  
  if (a > 800 && b > 900 && d < 900 && e > 900 && c > 900) {
    bluetooth.println("y");
  }
  
  if (a > 900 && b > 900 && d < 900 && e < 900 && c > 900) {
    bluetooth.println("z");
  }

  Serial.print("DATA,TIME,");
  Serial.print(a);
  Serial.print(",");
  Serial.print(b);
  Serial.print(",");
  Serial.print(c);
  Serial.print(",");
  Serial.print(d);
  Serial.print(",");
  Serial.print(e);
  Serial.print(",");
  Serial.print(mappedX);
  Serial.print(",");
  Serial.print(mappedY);
  Serial.print(",");
  Serial.print(mappedZ);
  Serial.print(",");
  Serial.print(pinxState);
  Serial.print(",");
  Serial.print(pinyState);
  Serial.print(",");
  Serial.print(pinzState);
  Serial.println();

  // Delay before next reading:
  delay(500);
}
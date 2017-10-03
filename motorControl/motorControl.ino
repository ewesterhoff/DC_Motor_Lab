#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

int x = 0;
int sensorPin1 = A0;
int sensorValue1 = 0;
int sensorPin2 = A1;
int sensorValue2 = 0;
int limitVal = 900;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(3);


void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //allows use to change the sensitivity of the sensor on the fly
  if (Serial.available() > 0)
    limitVal = Serial.read(); 
                
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);

  //move forward
  if (sensorValue1 < limitVal) and (sensorValue2 < limitVal){
    x = 30;
    y = 30;
    myMotor1 -> setSpeed(x);
    myMotor1 -> run(FORWARD);
    myMotor2 -> setSpeed(y);
    myMotor2 -> run(FORWARD); }

  //turn right
  if (sensorValue1 < limitVal) and (sensorValue2 > limitVal){
    x = 5;
    y = 15;
    myMotor1 -> setSpeed(x);
    myMotor1 -> run(FORWARD);
    myMotor2 -> setSpeed(y);
    myMotor2 -> run(FORWARD); }

  //turn left
  if (sensorValue1 > limitVal) and (sensorValue2 < limitVal){
    x = 15;
    y = 5;
    myMotor1 -> setSpeed(x);
    myMotor1 -> run(FORWARD);
    myMotor2 -> setSpeed(y);
    myMotor2 -> run(FORWARD); }

  //stop
  if (sensorValue1 > limitVal) and (sensorValue2 > limitVal){
    x = 0;
    y = 0;
    Serial.print("no value read, please enter value");
    myMotor1 -> setSpeed(x);
    myMotor1 -> run(FORWARD);
    myMotor2 -> setSpeed(y);
    myMotor2 -> run(FORWARD); } 

}

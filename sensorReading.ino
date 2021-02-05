#include "SevSeg.h"
SevSeg sevseg;

//establishing I/O pins
int trigPin = 8;
int echoPin = 7;
int buzzer = 6;

long duration,cm,inches,standard_dis, cal_result;

void setup() {
  Serial.begin(9600);

  //ultrasonic sensor setup
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  //sevseg display setup
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {11,10,4,5,9,12,13,3}; //setting pins for sevseg display
  bool resistorSegment = true;
  byte hardwareConfig = COMMON_CATHODE;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorSegment);
  sevseg.setBrightness(100);

  //buzzer pin setup
  pinMode(buzzer,OUTPUT);

  //calibrating sensor (performs 500 tests to get average control distance)
  Serial.println("Starting Calibration");
  for (int i = 0; i < 500; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin,LOW);

    duration = pulseIn(echoPin,HIGH);
    cm = (duration/2) / 29.1;
    inches = (duration/2) /74;
    
    cal_result = cal_result + inches;
  }
  cal_result = cal_result / 500;
  digitalWrite(buzzer,HIGH);
  delay(1);
  digitalWrite(buzzer,LOW);
  delay(500);
  digitalWrite(buzzer,HIGH);
  delay(1);
  digitalWrite(buzzer,LOW);
}

void loop() {
  digitalWrite(trigPin,LOW); //write LOW
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH); //write HIGH (clean)
  delayMicroseconds(5);
  digitalWrite(trigPin,LOW); //write LOW

  duration = pulseIn(echoPin,HIGH); //get sensor input
  cm = (duration/2) / 29.1; //calculate cm using speed of sound
  inches = (duration/2) / 74; //calculate inches using speed of sound

  //if the sensor detects object closer than average distance, anamoly has been found and system alerted
  if (inches < cal_result) {
    Serial.println("Sensor has detected anamoly");
    for(int i = 10; i >= 0; i--) {
      sevseg.setNumber(i);
      sevseg.refreshDisplay();
      digitalWrite(buzzer,HIGH);
      delay(1);
      digitalWrite(buzzer,LOW);
      delay(1000);
      
    }
    while(1){
      digitalWrite(buzzer,HIGH);
      delay(2);
      digitalWrite(buzzer,LOW);
      delay(2);
    }
  }
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(250);
}

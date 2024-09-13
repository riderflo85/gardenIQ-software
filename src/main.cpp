#include <Arduino.h>
#include "api_communications.h"
#include "sensors.h"

const int tempSensorPin = A1;
float temp;
String dataReceived;


void setup() {
  pinMode(tempSensorPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  temp = readTemperature(tempSensorPin);
  Serial.println(temp);


  if (Serial.available() > 0) {
    dataReceived = readData();
    Serial.print("Donnée reçu du script python : ");
    Serial.println(dataReceived);
  }

  delay(1000); // 1 sec
}

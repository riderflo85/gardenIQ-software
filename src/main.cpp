#include <Arduino.h>
#include "api_communications.h"
#include "sensors.h"

const int tempSensorPin = A1;
float temp;
String dataReceived;


void setup() {
  pinMode(tempSensorPin, INPUT); // Set the arduino board pin A1 to INPUT mode
  Serial.begin(9600); // Init the Serial communication and set the BAUDRATES transmission to 9600
}


void loop() {
  temp = readTemperature(tempSensorPin); // readTemperature is define in include/sensors.cpp
  Serial.println(temp);


  if (Serial.available() > 0) {
    dataReceived = readData(); // readData is define in include/api_communication.cpp
    Serial.print("Donnée reçu du script python : ");
    Serial.println(dataReceived);
  }

  delay(1000); // Wait 1 sec
  Serial.flush();
}

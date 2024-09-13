#include <Arduino.h>

const int tempSensorPin = A1;
int brutTempValue;
float temp;

String dataReceived;

// String readData();

void setup() {
  pinMode(tempSensorPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  brutTempValue = analogRead(tempSensorPin);
  temp = (brutTempValue / 1023.0) * 5.0 * 1000 / 10; // Convert to °C
  Serial.println(temp);


  if (Serial.available() > 0) {
    dataReceived = readData();
    Serial.print("Donnée reçu du script python : ");
    Serial.println(dataReceived);
  }

  delay(1000); // 1 sec
}

String readData() {
  return Serial.readString();
}

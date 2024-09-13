#include "sensors.h"


float readTemperature(int pin) {
    int brutTempValue = analogRead(pin);
    float temp = (brutTempValue / 1023.0) * 5.0 * 1000 / 10; // Convert to °C
    return temp;
};

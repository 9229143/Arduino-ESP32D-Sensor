#include <Wire.h>
#include "Adafruit_SHTC3.h"

Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();
const int soilPin = 34;  // 土壤溼度接在 GPIO34
int soilValue = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);  //  SHTC3的SDA(21)和SCL(22)腳位

  if (!shtc3.begin()) {
    Serial.println("Couldn't find SHTC3");
    while (1) delay(1);
  } else {
    Serial.println("SHTC3 Found");
  }
}

void loop() {
  soilValue = analogRead(soilPin);
  Serial.print("Soil moisture raw value: ");
  Serial.println(soilValue); //土壤濕度

  sensors_event_t humidity, temp;
  if (shtc3.getEvent(&humidity, &temp)) {
    Serial.print("T:");
    Serial.print(temp.temperature);
    Serial.print(",H:");
    Serial.println(humidity.relative_humidity);
  } else {
    Serial.println("Sensor error"); //SHTC3
  }
  delay(2000);
}

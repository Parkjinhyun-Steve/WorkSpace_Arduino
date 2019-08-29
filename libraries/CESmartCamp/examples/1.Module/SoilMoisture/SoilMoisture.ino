#include<CESmartCamp.h>
#define ANALOG_PIN A0
#define DIGITAL_PIN D1
SoilMoisture soil(ANALOG_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(DIGITAL_PIN, INPUT);
}

void loop() {
  String output = "";
  output += "Digital pin => ";
  output += digitalRead(DIGITAL_PIN);
  output += " Percentage => ";
  output += soil.read();
  Serial.println(output);
}

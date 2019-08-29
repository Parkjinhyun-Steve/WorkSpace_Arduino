#include "SHCSR04.h"

SHCSR04 hcsr04;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("-------------------");
  Serial.print("measure = ");
  Serial.print(hcsr04.measure(4, 5));
  Serial.println("cm");
  Serial.println("");
  delay(200);
}

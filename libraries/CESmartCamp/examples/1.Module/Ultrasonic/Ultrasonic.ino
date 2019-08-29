#include<CESmartCamp.h>
#define TRIGGER_PIN D7
#define ECHO_PIN D8
UltraSonic sonar(TRIGGER_PIN, ECHO_PIN);
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(sonar.length_cm());
  Serial.print(" ");
  Serial.println(sonar.length_inch());
}

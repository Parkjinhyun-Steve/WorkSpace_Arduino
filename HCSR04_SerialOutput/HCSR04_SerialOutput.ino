#include <hcsr04.h>

#define TRIG_PIN 4
#define ECHO_PIN 5

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);

void setup(){
    Serial.begin(9600);
}

void loop() {
    Serial.println(hcsr04.ToString());

    delay(250);
}

#define VIBRATE_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(VIBRATE_PIN));
}

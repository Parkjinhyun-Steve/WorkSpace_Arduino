#define BUZZER_PIN D2

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  tone(BUZZER_PIN, 20);
  delay(1000);
  tone(BUZZER_PIN, 20000, 1000);
}

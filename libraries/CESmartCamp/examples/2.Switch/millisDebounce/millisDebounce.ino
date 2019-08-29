#define SWITCH_PIN D1
long debounceTime = 100, lastDebounce = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
  if (millis() - lastDebounce > debounceTime && (digitalRead(SWITCH_PIN) == LOW))
  {
    lastDebounce = millis();
    count++;
    Serial.println(count);
  }
}

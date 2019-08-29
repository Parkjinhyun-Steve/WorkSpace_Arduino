#define SWITCH_PIN D1
long debounceTime = 100;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(SWITCH_PIN) == LOW)
  {
    delay(debounceTime);
    count++;
    Serial.println(count);
  }
}

#define LDR_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int LDRValue = analogRead(LDR_PIN);
  Serial.println(LDRValue);
}

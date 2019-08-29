#define IR_PIN D1

void setup() {
  Serial.begin(9600);
  pinMode(IR_PIN, INPUT);
}

void loop() {
  Serial.println(digitalRead(IR_PIN));
}

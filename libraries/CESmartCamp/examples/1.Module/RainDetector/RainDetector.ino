#define DIGITAL_PIN D1
#define ANALOG_PIN A0

void setup() {
  Serial.begin(9600);
  pinMode(DIGITAL_PIN, INPUT);
}

void loop() {
  String output = "";
  output += "Digital pin => ";
  output += digitalRead(DIGITAL_PIN);
  output += " Analog pin => ";
  output += analogRead(ANALOG_PIN);
  Serial.println(output);
}

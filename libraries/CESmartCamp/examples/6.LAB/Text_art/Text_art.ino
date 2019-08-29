#define DRAW D1
#define CLEAR D2

void setup() {
  Serial.begin(9600);
  pinMode(DRAW, INPUT_PULLUP);
  pinMode(CLEAR, INPUT_PULLUP);
}

void loop() {
  delay(200);
  if (digitalRead(DRAW) == LOW) {
    Serial.println("   _____ ______  _____  _____ __ ___  ");
    Serial.println("  / ____|  ____|/ ____|/ ____/_ |__ \\");
    Serial.println("| |    | |__  | (___ | |     | |  ) |");
    Serial.println("| |    |  __|  \\___ \\| |     | | / /");
    Serial.println("| |____| |____ ____) | |____ | |/ /_ ");
    Serial.println("  \\_____|______|_____/ \\_____||_|____|");
  }
  if (digitalRead(CLEAR) == LOW)
    for (int i = 0; i < 50 ; i++)
      Serial.println("");
}

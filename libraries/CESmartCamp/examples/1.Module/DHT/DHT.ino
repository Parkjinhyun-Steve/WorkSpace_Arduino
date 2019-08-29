#include "DHT.h"

#define DHT_PIN D2
#define DHT_TYPE DHT11 // DHT 11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht.begin();
}

void loop() {
  delay(1000);
  float h = dht.readHumidity();
  float t;
  t = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(dht.readTemperature(true));
  Serial.print(" *F\t\n");
}

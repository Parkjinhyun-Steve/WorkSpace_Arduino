#include <ESP8266WiFi.h>
#include <CESmartCamp.h>

const String TOKEN = "Your Token";

void setup() {
  Serial.begin(9600);
  WiFi.begin("Your WIFI name", "Your WIFI password");
  Serial.println("connecting...");
  WiFi.mode(WIFI_STA);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("connected ip:");
  Serial.print( WiFi.localIP());
  Serial.println();
}

void loop() {
  sendMessage(TOKEN, "Hello CESC");
  delay(5000);
}

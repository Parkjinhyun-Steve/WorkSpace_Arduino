#include<AntoIO.h>
#include "DHT.h"
#include <SimpleTimer.h>

#define DHT_PIN D1
#define DHT_TYPE DHT11

const char *ssid = "Name's wifi";
const char *pass = "Password's wifi";
const char *user = "username in Anto";
const char *token = "key in Anto";
const char *thing = "thing name in Anto";
/*
   ตัวอย่าง :
   const char *thing= "HumidAndTemp";
*/

DHT dht(DHT_PIN, DHT_TYPE);
SimpleTimer timer;
AntoIO anto(user, token, thing);


void setup() {
  Serial.begin(9600);
  dht.begin();
  anto.begin(ssid, pass, messageReceived);
  timer.setInterval(1000, publishData);
}

void loop() {
  anto.mqtt.loop();
  timer.run();
}

/* ส่วนของฟังก์ชันที่จะทำงานทุก ๆ 1 วินาที เพื่อส่งค่าไปยัง anto */
void publishData() {
  String humid = String( dht.readHumidity() );
  String temp = String( dht.readTemperature() );
  anto.mqtt.pub("HUMID", humid.c_str() );
  anto.mqtt.pub("TEMP", temp.c_str() );
  /*
    คำสั่ง publish ข้อมูลไปยัง channel
    มีพารามิเตอร์ 2 ตัวคือ ชื่อ channel และ ข้อความที่ส่ง
  */
}

void messageReceived(String thing, String channel, String payload) {

}

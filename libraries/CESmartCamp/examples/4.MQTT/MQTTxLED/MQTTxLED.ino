#define LED_PIN D5

#include <AntoIO.h>

const char *ssid = "Name's wifi";
const char *pass = "Password's wifi";
const char *user = "username in Anto";
const char *token = "key in Anto";
const char *thing = "thing name in Anto";
/*
   ตัวอย่าง :
   const char *ssid = "AndroidAP";
   const char *pass = "123456789";
   const char *user = "cesmartcamp";
   const char *token = "f8txKwDF7t4ArFwONht9T4D1D0wVZbW5XvONUK0O";
   const char *thing= "LedControl";
*/

AntoIO anto(user, token, thing);
/*
    ประกาศตัวแปร anto เพื่อใช้งาน anto.io
    มีพารามิเตอร์ 3 ตัวคือ username , token ,thing
*/

void setup() {
  Serial.begin(115200);
  anto.begin(ssid, pass, messageReceived);
  /*
     เชื่อมต่อ wifi และ anto
     มีพารามิเตอร์3ตัวคือ ชื่อ wifi , พาสเวิร์ด wifi
     และ ฟังก์ชันที่จะให้ทำงานเมื่อมีข้อมูลมาที่ nodemcu
  */

  anto.sub("LED1");
  /*
     คำสั่ง subscribe channel
  */

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  anto.mqtt.loop();
  /*
     รัน anto.mqtt ให้ทำงานตลอด
  */

}

/* ส่วนของฟังก์ชันที่จะทำงานเมื่อมีข้อมูลเข้ามาที่ nodemcu */
void messageReceived(String thing, String channel, String payload) {

  Serial.print("Recieved: ");
  Serial.print(thing);
  Serial.print("/");
  Serial.print(channel);
  Serial.print("-> ");
  Serial.println(payload);

  if (channel.equals("LED1")) {
    int value = payload.toInt();
    if (value == 1) {
      digitalWrite(LED_PIN, HIGH);
    }
    else {
      digitalWrite(LED_PIN, LOW);
    }

  }
  /*
     ส่วนเช็คค่าที่ส่งมาเพื่อใช่ในการเปิดปิด LED
  */
}

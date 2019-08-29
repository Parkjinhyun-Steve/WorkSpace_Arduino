#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// ============= WiFi credentials =============== //
char ssid[] = "xxxxxxxxxxxx"; // 2.4G only
char pass[] = "xxxxxxxxxxxx";
/* [EX] char ssid[] = "AndriodAP"; */
/* [EX] char pass[] = "123456789"; */
// ============================================== //

// ================= Server ===================== //
IPAddress serverIP (xxx, xxx, xxx, xxx); // Your IP of Server
char auth[] = "xxxxxxx";
int port = xxxx; // int Value
/* [EX] IPAddress serverIP (192, 168, 1, 1);        */
/* [EX] char auth[] = "2dgykj59sfyY5asdJH58jsdfg4"; */
/* [EX] int port = 8080;                            */
// ============================================== //

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass, serverIP, port);
}

void loop()
{
  Blynk.run();
}

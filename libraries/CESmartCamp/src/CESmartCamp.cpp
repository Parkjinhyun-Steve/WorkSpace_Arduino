/*CESmartCamp.c - For CESmartCamp only*/

#include "CESmartCamp.h"

UltraSonic::UltraSonic(int t,int e){
	trig = t;
	echo = e;
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	
}

long UltraSonic::length_cm(){
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(5);
	digitalWrite(trig, LOW);
	return pulseIn(echo, HIGH) / 29 / 2;
}

long UltraSonic::length_inch(){
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(5);
	digitalWrite(trig, LOW);
	return pulseIn(echo, HIGH) / 74 / 2;
}

SoilMoisture::SoilMoisture(int p){
	pin = p;
}

double SoilMoisture::read(){
	return 100 - ((analogRead(pin) / 1024.00) * 100);
}

void sendMessage(String token,String message)
{
    String msg = String("message=") + message;

    axTLS::WiFiClientSecure client;
    if (!client.connect("notify-api.line.me", 443))
    {
        Serial.println("connection failed");
        return;
    }

    String req = "";
    req += "POST /api/notify HTTP/1.1\r\n";
    req += "Host: notify-api.line.me\r\n";
    req += "Content-Type: application/x-www-form-urlencoded\r\n";
    req += "Authorization: Bearer " + String(token) + "\r\n";
    req += "Content-Length: " + String(msg.length()) + "\r\n";
    req += "\r\n";
    req += msg;

    client.print(req);

    unsigned long timeout = millis();
    while (client.available() == 0)
    {
        if (millis() - timeout > 5000)
        {
            Serial.println(">>> Client Timeout !");
            client.stop();
            return;
        }
    }

    // Read all the lines of the reply from server and print them to Serial
    while (client.available())
    {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }

    Serial.println();
    Serial.println("closing connection");
}

/*CESmartCamp.h - For CESmartCamp only*/

#ifndef CESmartCamp_h
#define CESmartCamp_h

#include "Arduino.h"
#include <WiFiClientSecureAxTLS.h>

class UltraSonic{
private:
	int trig;
	int echo;
	
public:
	UltraSonic(int t,int e);
	long length_cm();
	long length_inch();
};

class SoilMoisture{
private:
	int pin;
public:
	SoilMoisture(int p);
	double read();
};

void sendMessage(String token, String message);

#endif

/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <HCSR04.h>

// 초음파 센서
HCSR04 hc(5,6);//initialisation class HCSR04 (trig pin , echo pin)

// 서보 모터
Servo myservo;  // create servo object to control a servo
                // twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);  
}

void loop() { 

// 초음파 센서 출력 /  서보모터 초기화 0도
  
  Serial.println( hc.dist() );
  myservo.write(0);
  

// 서보 모터

  if(hc.dist() >= 30){ // 30 보다 크면 닫혀 있음
    myservo.write(0);
    delay(200);
    
  } else {  
      for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(20);
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        }        
      while (hc.dist() <= 30 ){  // 30보다 작으면 열려있음
        Serial.println( hc.dist() );
        delay(100); 
        }
      for (pos = 120; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);                 // tell servo to go to position in variable 'pos'
        delay(20);                          // waits 15ms for the servo to reach the position
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      }      
  }
}

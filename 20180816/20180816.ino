#include <SimpleDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// 1. 온습도계
// for DHT11
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2

int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

//2. LCD
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//3. Servo 모터
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position




void setup() {
  
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  // initialize digital pin BEEP as an output.
  pinMode(4, OUTPUT);

  // attaches the servo on pin 9 to the servo object
  myservo.attach(9);  
  
}


void loop() {

// 1. 온습도계
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  // DHT11 sampling rate is 1HZ.
  

//2. 조도계
  // read the input on analog pin 0:  
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1000);        // delay in between reads for stability

// 3.LCD
  if(sensorValue>=400){
    lcd.noBacklight();
  }
  else{
    // Print a message to the LCD.
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("temperature: ");
    lcd.print(temperature);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("humidity: ");
    lcd.print(humidity);
    lcd.print("%");
    delay(1500);
  }   

// 4. 27도 이상시 비프음
  if(temperature>=27){
    digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
    delay(500);                       // wait for a second
  }

//5. Servo 모터
  
  myservo.write(180-(temperature*3));              // tell servo to go to position in variable 'pos'
  delay(500);
   
  
}

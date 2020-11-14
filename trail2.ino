//////////////////////////////////////////////////////////////////////////////
#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(3 , 4, 5, 6, 7, 8); 
//LiquidCrystal lcd(3 , 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int buzzer1 = 2;
const int ledPin1 = 13;
const int ledPin2 = 12;
long duration;
int distanceCm, distanceM, time, time1, safetyDistance;
//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
void setup() {
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(buzzer1, OUTPUT);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
}
////////////////////////////////////////////////////////////////////////////////////////
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
//duration1= distanceCm/0.034/2;
//timeM = duration/60; 
distanceM = distanceCm/100; 
time = distanceCm/0.034;
time1 = time/0.000001;
//speed = (duration*0.034/2)/(distanceCm/0.034);
//speed1 = speed/10;
safetyDistance = distanceCm;

if (safetyDistance >= 35 && safetyDistance <= 50)   // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin1, HIGH);  
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin1, LOW);

}
if (safetyDistance <= 30)   // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
  digitalWrite(buzzer1, HIGH);
  digitalWrite(ledPin2, HIGH);
  
}
else{
  digitalWrite(buzzer1, LOW);
  digitalWrite(ledPin2, LOW);
}
  
 

/////////////////////collision time ////////////////////////
lcd.setCursor(0,1);
lcd.print("ColTime:");
lcd.setCursor(8,1);
lcd.print(time);
lcd.setCursor(12,1);
lcd.print("McS");
delay(100);
//////////////////////////////////////////////////////////

////// distance ////////////////////////////////////////////
lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.setCursor(10,0);
lcd.print(distanceCm);
delay(100);// Prints the distance value from the sensor
lcd.setCursor(12,0);
lcd.print("cm");
delay(10);
////////////////////////distance ////////////////////////


}

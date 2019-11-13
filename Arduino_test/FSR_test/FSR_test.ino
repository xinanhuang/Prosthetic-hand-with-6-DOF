/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int analogpin = 3;
int val = 0;

void setup() {
  Serial.begin(19200);
  myservo.attach(5);  // attaches the servo on pin 5to the servo object
}

// read analog pin and print to serial
void read_adc(){
  val = analogRead(analogpin);  // read the input pin
  Serial.println(val);          // debug value
}

void loop() {

  while (pos <= 180)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    read_adc();
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position

    // stall if a certain threshold is met
    if (val < 200){
       pos += 5;
    }
    else if (val <=1000){
      pos += (1000-val)/160;
    }
    
       
  }

  
 
  
  for (pos = 180; pos >= 0; pos -= 5) { // goes from 180 degrees to 0 degrees
    read_adc();
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);          // waits 15ms for the servo to reach the position
    
    if (400 <= val <=900){
      pos += (val-400)/100;
    }
  }

  
}

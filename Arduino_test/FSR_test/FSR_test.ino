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
int analogpin1 = 3;
int analogpin2 = 2;
int analogpin3 = 1;
int analogpin4 = 0;
int analogpin5 = 10;
int analogpin6 = 9;
int analogpinx = 8;
int analogpiny = 7;
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;
int val6 = 0;
int valx = 0;
int valy = 0;

void setup() {
  Serial.begin(19200);
  myservo.attach(5);  // attaches the servo on pin 5to the servo object
}

// read analog pin and print to serial
void read_adc(){
  val1 = analogRead(analogpin1);  // read the input pin
  val2 = analogRead(analogpin2);  // read the input pin
  val3 = analogRead(analogpin3);  // read the input pin
  val4 = analogRead(analogpin4);  // read the input pin
  val5 = analogRead(analogpin5);  // read the input pin
  val6 = analogRead(analogpin6);  // read the input pin
  valx = analogRead(analogpinx);  // read the input pin
  valy = analogRead(analogpiny);  // read the input pin
  Serial.println(val1);          // debug value
}

// clear screen
void clearAndHome()
{
for(int x = 0; x < 50; x++) Serial.println();
}

void loop() {

  while (pos <= 180)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    read_adc();

    Serial.print(val5);
    Serial.print(" ");
    Serial.print(val1);
    Serial.print(" ");
    Serial.print(val2);
    Serial.print(" ");
    Serial.print(val6);
    Serial.print(" ");
    Serial.print(val4);
    Serial.print(" ");
    Serial.print(val3);
    Serial.print(" ");
    Serial.print(valx);
    Serial.print(" ");
    Serial.println(valy);

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    
    // stall if a certain threshold is met
    if (val1 < 200){
       pos += 5;
    }
    else if (val1 <=1000){
      pos += (1000-val1)/160;
    }
    
       
  }

  
 
  
  for (pos = 180; pos >= 0; pos -= 5) { // goes from 180 degrees to 0 degrees
    read_adc();
    Serial.print(val5);
    Serial.print("\t");
    Serial.print(val1);
    Serial.print("\t");
    Serial.print(val2);
    Serial.print("\t");
    Serial.print(val6);
    Serial.print("\t");
    Serial.print(val4);
    Serial.print("\t");
    Serial.print(val3);
    Serial.print("\t");
    Serial.print("\t");
    Serial.print(valx);
    Serial.print("\t");
    Serial.println(valy);

    
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);          // waits 15ms for the servo to reach the position
    
    if (400 <= val1 <=900){
      pos += (val1-400)/100;
    }
  }

  
}

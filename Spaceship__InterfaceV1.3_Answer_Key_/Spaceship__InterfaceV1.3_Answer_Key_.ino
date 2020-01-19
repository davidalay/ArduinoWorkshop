#include <Servo.h>
int switchState = 0;
int switchStateTwo = 0;
int instructions = 1; // Instructions will print while this variable set to 1.
int laserPower = 0; // variable to store the laser power data.
int buttonCounter = 0; // Sets a counter for button 2 presses to zero.
int enginePosition = 0;    // variable to store the servo position.
Servo galacticEngine;  // create servo object to control our space engine.

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9,OUTPUT);
  //DEFINE PINS 2, 8 AND A0 AS INPUT
  pinMode(2, INPUT);
  pinMode(8, INPUT);
  pinMode(A0, INPUT);
  galacticEngine.attach(10);  // attaches the servo on pin 10 to the servo object
}


void loop() {
  switchState = digitalRead(2); // Assigning the variable switchState with the values read from button 1
  switchStateTwo = digitalRead(8); // Assigning the variable switchState with the values read from button 2
  laserPower = analogRead(A0);

  Serial.begin(9600); // This command allows us to print to the serial terminal

  //*********************************************************************
  // WRITE START UP MESSAGE HERE (REMEMBER THAT WE ONLY WANT THIS TO PRINT ONCE)
  //*********************************************************************
  if (instructions == 1)
  {
    Serial.print("Starting command board \n");
    delay(1000);
    Serial.print("Startup complete\n");
    instructions = 0;
  }

  //****************************************************************************
  // This section of code uses an if-else statement to read button 1. When the button is pressed, it turns on the lights.
  //****************************************************************************

  if (switchState == LOW) { // the button is not pressed
    //***************************************************************
    //TURN THE GREEN LED ON, AND BOTH RED LEDS OFF
    //***************************************************************
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
  }

  else { // the button is pressed
    Serial.print("Performing Console Lighting Test\n");
    digitalWrite(5,LOW);
    digitalWrite(4, HIGH);
    delay(500);

    digitalWrite(4,LOW);
    digitalWrite(3,HIGH);
    delay(500);

  } // This brace the if-else statement


  //****************************************************************************
  // This section of code uses an if-else statement to read button 2. When the button is pressed, it resets to 0. (later it increments a counter, see below)
  // The counter is used to cycle through various functions of the spaceship interface. When done, it returns to the start.
  //****************************************************************************

  if (switchStateTwo == LOW) { // the button is not pressed
    digitalWrite(3, HIGH); // green LED
    digitalWrite(4, LOW); // red LED
    digitalWrite(5, LOW); // red LED
  }

  else { // the button is pressed. We then increment the counter
    buttonCounter ++;
    Serial.print("Button pushed\n");
  }

  //****************************************************************************
  // This section of code uses a if-else statement to output a spaceship interface funtion based on the value of the counter.
  // (later) When the counter reaches three, it is reset to zero in order to return to the beginning of the cycle.
  //****************************************************************************

  // If the counter is equal to 1, fire the laser.
  if (buttonCounter == 1) {
    Serial.print("LASER BURST FIRED : Laser Power = ");

    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    //****************************************************************
    //CYCLE THROUGH PWM VALUES 0-255 FOR 'laserPower' AND PRINT TO SERIAL MONITOR
    //****************************************************************
    for(int i=0; i<=255; i=i+5)
    {
        analogWrite(9, (255-i));
        Serial.print(i);
        Serial.print("\n");
        delay(100);
    }
    
    delay(1000);
    analogWrite(9, LOW);
    buttonCounter++; // Reset the counter to 0. In the next step we change this to "buttonCounter++;" This will add 1 to the counter.

  } // This brace closes the if statement

  // If the button is pressed again, it will equal 3 and sound the alarm.
  else if (buttonCounter == 3) {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    Serial.print("Sounding Annoying RED ALERT Alarm\n");

    // This for loop will run 5 times. If you want the alarm and light to run longer you can increase the number from 15, or decrease it to shorten the alarm.

    for (int i = 0; i < 5; i++) 
    {
      delay(100);
      digitalWrite(4, HIGH);
      delay(100);
      digitalWrite(4, LOW);
      delay(100);
      digitalWrite(4, HIGH);
      i++;
    }

    digitalWrite(6, LOW);
    buttonCounter=0; // Reset the counter to 0. In the next step we change this to "buttonCounter++;" This will add 1 to the counter.

  } // This brace closes the if-else statement


  // If the counter is equal to 5, the button has been pressed 3 times. Engage the engines.

//  else if (buttonCounter == 5) {
  //  Serial.print("Warming Up Warp Engines - ");

//    for (//CYCLE FROM 0 TO 180 FOR ENGINEPOSITION) { // goes from 0 degrees to 180 degrees in steps of 5 degrees
//      galacticEngine.write(enginePosition); // tell servo to go to position stored in variable
//
//      // Blink Lights during Engine Test
//      digitalWrite(3, LOW);
//      digitalWrite(4, LOW);
//      digitalWrite(5, HIGH);
//      delay(35);
//      digitalWrite(3, LOW);
//      digitalWrite(4, HIGH);
//      digitalWrite(5, HIGH);
//      delay(35);
//      digitalWrite(3, HIGH);
//      digitalWrite(4, HIGH);
//      digitalWrite(5, HIGH);
//      delay(35);
//      digitalWrite(3, LOW);
//      digitalWrite(4, LOW);
//      digitalWrite(5, LOW);
//
//  }
// Return the servo to the start position.

//Serial.print("TEST FIRE WARP ENGINES\n");
//  galacticEngine.write(0);  // tell servo to go back to degree 0.
//  delay(15);  // waits 15ms for the servo to reach the position
//  buttonCounter = 0;  // Reset buttonCounter to 0
//}


} // This brace closes the loop

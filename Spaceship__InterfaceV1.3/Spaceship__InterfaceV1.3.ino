//Include Libraries Here

//Declare Variables here



void setup() {
  //Define pins 3, 4, 5, 6 ,7 9 as output

  //DEFINE PINS 2, 8 AND A0 AS INPUT

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
  if (????)
  {
   //Start up message goes here
    instructions = ??;
  }

  //****************************************************************************
  // This section of code uses an if-else statement to read button 1. When the button is pressed, it turns on the lights.
  //****************************************************************************

  if (switchState == ??) { // the button is not pressed
    //***************************************************************
    //TURN THE GREEN LED ON, AND BOTH RED LEDS OFF
    //***************************************************************
    
  }

  else { // the button is pressed
    Serial.print("Performing Console Lighting Test\n");
    digitalWrite(5,??);
    digitalWrite(4, ??);
    delay(500);

    digitalWrite(4,??);
    digitalWrite(3,??);
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
    //incriment counter here
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
       //cycle through PWM values and write to serial
        delay(100);
    }
    
    delay(1000);
    analogWrite(9, LOW);
    buttonCounter=0; // Reset the counter to 0. In the next step we change this to "buttonCounter++;" This will add 1 to the counter.

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

  else if (buttonCounter == 5) {
    Serial.print("Warming Up Warp Engines - ");

    for (//CYCLE FROM 0 TO 180 FOR ENGINEPOSITION) // goes from 0 degrees to 180 degrees in steps of 5 degrees
      { 
      galacticEngine.write(enginePosition); // tell servo to go to position stored in variable

      // Blink Lights during Engine Test
      digitalWrite(3, ??);
      digitalWrite(4, ??);
      digitalWrite(5, ??);
      delay(35);
      digitalWrite(3, ??);
      digitalWrite(4, ??);
      digitalWrite(5, ??);
      delay(35);
      digitalWrite(3, ??);
      digitalWrite(4, ??);
      digitalWrite(5, ??);
      delay(35);
      digitalWrite(3, ??);
      digitalWrite(4, ??);
      digitalWrite(5, ??);
  }
  // Return the servo to the start position.
  }



} // This brace closes the loop

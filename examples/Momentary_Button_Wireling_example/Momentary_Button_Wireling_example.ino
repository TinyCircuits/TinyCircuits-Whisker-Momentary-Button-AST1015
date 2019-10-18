//************************************************************************
// Momentary Button Wireling Example
//
// Uses digitalRead to detect when the momentary button is pressed
// and reports it to the serial monitor.
//
// Written by Jason Marcum 7/30/19
//************************************************************************

#define buttonPin A0 // corresponds to Port 0. Similarly, Port 1 = A1, Port 2 = A2, Port 3 = A3.

// Used to track the state of the button
int buttonState = 0;


void setup() {
  SerialUSB.begin(9600);         //Begin Serial Communication and set Baud Rate

  // Use this pin as an input to read the button state
  pinMode(buttonPin, INPUT);
}


void loop() {

  // Used for alerting user/printing to serial monitor if the button state changes
  int prevButtonState = buttonState;

  // Get the button state
  buttonState = digitalRead(buttonPin);

  if (prevButtonState != buttonState) // No need to alert the user if button state remains unchanged
  {
    if (buttonState == LOW)
    {
      SerialUSB.println("Button pressed!");
    }
    else
    {
      // Button not currently being pressed
    }
  }
}

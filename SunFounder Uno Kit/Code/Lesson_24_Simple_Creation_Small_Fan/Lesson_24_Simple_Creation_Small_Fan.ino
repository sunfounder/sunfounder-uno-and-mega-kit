//Small Fan
/****************************************************************
 * As explained above, the amount of times you press the button should change the rotation speed of the fan. 
 * Pressing it once will cause it to rotate slowly,
 * while pressing it three times will cause it to rotate quickly, and pressing it four times will cause it to stop.
 ****************************************************************/
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin
const int motorIn1 = 9;
const int motorIn2 = 10;
int stat = 0; 
#define rank1 150
#define rank2 200
#define rank3 250
// Variables will change:
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers
/******************************************************************************/
void setup() 
{
  //set theled,motors as OUTPUT,button as INPUT
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState)// If the button state is different from last time 
  {   
    lastDebounceTime = millis();// reset the debouncing timer
  } 
  if ((millis() - lastDebounceTime) > debounceDelay) 
  { 
    if (reading != buttonState) 
    {
      buttonState = reading; // Store the state of button in buttonState 
      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH)
      {
        digitalWrite(ledPin, HIGH); //turn on the LED
        stat = stat + 1;
        if(stat >= 4)// When stat>=4, set it as 0. 
        {
          stat = 0;
        }
      }
      else
        digitalWrite(ledPin, LOW);
    }
  } 
  switch(stat)
  {
  case 1:
    clockwise(rank1);// When stat=1, set the rotate speed of the motor as rank1=150
    break;
  case 2:
    clockwise(rank2);// When stat=2, set the rotate speed of the motor as rank1=200
    break;
  case 3:
    clockwise(rank3);// When stat=3, set the rotate speed of the motor as rank1=250
    break;
  default:
    clockwise(0);
  }
  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}
/***********************************************************/
void clockwise(int Speed)//
{
  analogWrite(motorIn1,0);
  analogWrite(motorIn2,Speed);
}
/***********************************************************/

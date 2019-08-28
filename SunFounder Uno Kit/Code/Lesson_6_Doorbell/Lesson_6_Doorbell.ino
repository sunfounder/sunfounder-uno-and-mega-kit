//Doorbell
//Turns on and off a buzzer use the button.
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2018.12.20
/**********************************/
const int buttonPin = 2; //the button connect to pin2
const int buzzerPin = 8;//the led connect to pin8
/**********************************/
int buttonState = 0;         // variable for reading the pushbutton status

void setup()
{
  pinMode(buttonPin, INPUT); //initialize the buttonPin as input
  pinMode(buzzerPin, OUTPUT); //initialize the buzzerpin as output
}
/**********************************/
void loop()
{
  unsigned char i; //define a variable
  //read the state of the button value
  buttonState = digitalRead(buttonPin);

  //and check if the button is pressed
  //if it is,the state is HIGH
  if (buttonState == HIGH )
  {
    for (i = 0; i < 50; i++)
    {
      digitalWrite(buzzerPin, HIGH);
      delay(3);//wait for 1ms
      digitalWrite(buzzerPin, LOW);
      delay(3);//wait for 1ms
    }
     for (i = 0; i < 80; i++)
    {
      digitalWrite(buzzerPin, HIGH);
      delay(5);//wait for 1ms
      digitalWrite(buzzerPin, LOW);
      delay(5);//wait for 1ms
    }
  }
}
/************************************/

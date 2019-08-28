//Flowing LED Lights
/* Eight LEDs will light up one by one from left to right, and then go out one by one from right to left.
  After that, the LEDs will light up one by one from right to left, and then go out one by one from left to right.
  This process will repeat indefinitely.*/
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
/**************************************/
void setup()
{
  //set pins 2 through 9 as output
  for (int i = 2; i <= 9; i++)
  {
    pinMode(i, OUTPUT); //initialize a as an output
  }
}
/****************************************/
void loop()
{
  //iterate over the pins
  //turn the led on from lowest to the highest
  for (int a = 2; a <= 9; a++)
  {
    digitalWrite(a, HIGH); //turn this led on
    delay(100);//wait for 100 ms
  }
  //turn the led off from pin9 to pin2
  for (int a = 9; a >= 2; a--)
  {
    digitalWrite(a, LOW); //turn this led off
    delay(100);//wait for 100 ms
  }
  //turn the led off from pin2 to pin9
  for (int a = 9; a >= 2; a--)
  {
    digitalWrite(a, HIGH); //turn this led on
    delay(100);//wait for 100 ms
  }
  for (int a = 2; a <= 9; a++)
  {
    digitalWrite(a, LOW); //turn this led off
    delay(100);//wait for 100 ms
  }
}

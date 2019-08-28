/***************************************************
//StepperTest
//Description: You should see the rocker arm of the stepper motor spin clockwise and counterclockwise alternately. 
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2018/12/28
**********************************************/

#include <Stepper.h>   //include a head file

//the steps of a circle
#define STEPS 100
 
//set steps and the connection with MCU
Stepper stepper(STEPS, 2, 3, 4, 5);
 
//available to store previous value
int previous = 0;
 
void setup()
{
  //speed of 180 per minute
  stepper.setSpeed(180);
}
 
void loop()
{
  //get analog value
  int val = analogRead(0);
  //current reading minus the reading of history
  stepper.step(val - previous);  //Turn the motor in val-previous steps
  //store as prevous value
  previous = val;
}

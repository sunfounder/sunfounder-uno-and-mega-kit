/**********************************
 * name:Building a Quiz Buzzer System
 * function: first press button 4 to start. If you press button 1 first, you will see the corresponding LED light up and the buzzer will beep. Then press button 4 again to reset before you press other buttons.
 **********************************/
//Email:support@sunfounder.com
//Website:www.sunfounder.com

#define button1 2  //the number of the button 1
#define button2 3  //button2 attach to
#define button3 4  //button3 attach to 
#define button4 9  //button4 attach to
#define buzzerPin 5  //the buzzer attach to    
#define LED1 6  //LED 1attach to      
#define LED2 7  //LED2attach to     
#define LED3 8  //LED3 attach to 
#define LED4 10  //LED4 attach to
#define uint8 unsigned char
uint8 flag = 0;  //used to indicate the state of button4 key
uint8 b1State,b2State,b3State,b4State = 0;

void setup()
{
  //initialize buzzer,LED1, LED2, LED3 and LED4 as output
  pinMode(buzzerPin, OUTPUT);     
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);     
  pinMode(LED3, OUTPUT); 
  pinMode(LED4, OUTPUT);
  //initialize button1,button2 andbutton3 as input,combined with pullup
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);    
  pinMode(button4, INPUT_PULLUP);
  //turn all the led off
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);  
  digitalWrite(LED3, LOW); 
  digitalWrite(LED4, LOW);
}
void loop()
{
  //turn all the led off
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);  
  digitalWrite(LED3, LOW);  
  digitalWrite(LED4, LOW);
  //read the state of the button4
  b4State = digitalRead(button4);
  //when button4 pressed
  if(b4State == 0)
  {
    if(b4State == 0)  //confirm that the button4 is pressed
    {
      flag = 1;  //if so,flag is 1
      digitalWrite(LED4, HIGH);  //turn the host LED on
      delay(200);  
    }
  }
  if(1 == flag)
  {
    //read the state of the button of buttons
    b1State = digitalRead(button1);  
    b2State = digitalRead(button2);
    b3State = digitalRead(button3);
    //If the button1 press the first
    if(b1State == 0)
    {
      flag = 0;
      digitalWrite(LED4, LOW);
      Alarm();  //buzzer sound
      digitalWrite(LED1,HIGH);  //turn the LED1 on only
      digitalWrite(LED2,LOW); 
      digitalWrite(LED3,LOW); 
      while(digitalRead(button4));  //detect the button4,if pressed,out of the while loop
    }
    //If the button2 press the first
    if(b2State == 0)
    {
      flag = 0;
      digitalWrite(LED4, LOW);
      Alarm();
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,HIGH); 
      digitalWrite(LED3,LOW); 
      while(digitalRead(button4));
    }
    //If the button3 press the first
    if(b3State == 0)
    {
      flag = 0;
      digitalWrite(LED4, LOW);
      Alarm();
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW); 
      digitalWrite(LED3,HIGH); 
      while(digitalRead(button4));
    }
  }
}
//buzzer sound
void Alarm()         
{
  for(int i=0;i<100;i++){
    digitalWrite(buzzerPin,HIGH); //the buzzer sound
    delay(2);
    digitalWrite(buzzerPin,LOW);  //without sound
    delay(2);                     //when delay time changed,the frequency changed
  }
}

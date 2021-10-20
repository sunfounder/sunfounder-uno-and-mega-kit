/*************************************************************************************
//Infrared-Receiver
// press Power on the remote control and the LED attached to pin 13 on the Mega 2560 board will light up. 
//If you press other keys, the LED will go out.
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2018.12.27 
**********************************************************************/

#include <IRremote.h>  
 
const int irReceiverPin = 2;  //the infrared-receiver attact to pin2
const int ledPin = 13; //built-in LED
 
IRrecv irrecv(irReceiverPin); //Initialize the infrared-receiver
decode_results results;  //The decoding result is placed in the result of the decode results structure.
 
void setup()
{
  pinMode(ledPin,OUTPUT); //set the ledPin to OUTPUT
  Serial.begin(9600);   //set the baud bit of serial monnitor
  irrecv.enableIRIn();  //Restart the receiver  
}
 
void loop() 
{
  if (irrecv.decode(&results)) {   //If receive a data
    Serial.print("irCode: ");   //print "irCode: " on the serial monitor         
    Serial.print(results.value, HEX); //print the signal on serial monitor in hexadecimal 
    Serial.print(",  bits: ");           
    Serial.println(results.bits); // Print the data bits
    irrecv.resume();  //Receive next data  
  }  
  delay(600); 
  if(results.value == 0xFFA25D)  // if the results.value is equals to 0xFFA25D(The coding of the power button on the remote control)
  {
    digitalWrite(ledPin,HIGH);  //Turn on the LED
  }
  else
  {
    digitalWrite(ledPin,LOW);  //else turn of the LED
  }
}

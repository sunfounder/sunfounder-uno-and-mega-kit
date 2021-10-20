/**********************************************************************
//Infrared-Receiver
// press Power on the remote control and the LED attached to pin 13 on the Mega 2560 board will light up. 
//If you press other keys, the LED will go out.
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2018.12.27 
******************************************************************************/
#include <dht.h>   //Include the head file dht.h
#include <LiquidCrystal.h>  //
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);  // initialize the LCD1602

dht DHT;  //Define a variable DHT of dht type. Here use DHT to represent dht in the following code. 

#define DHT11_PIN 3  //the humiture sensor attact to pin3

void setup()
{
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows: 
  Serial.begin(9600); //set the baud bit to 9600bps
}

void loop()
{
  // READ DATA
  Serial.print("DHT11, \t"); //Print DHT11,
  //read the value returned from sensor
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
		Serial.println("OK,\t"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.println("Checksum error,\t"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.println("Time out error,\t"); 
		break;
    default: 
		Serial.println("Unknown error,\t"); 
		break;
  }
 // DISPLAY DATA
 lcd.setCursor(0, 0);
 lcd.print("Tem:");
 lcd.print(DHT.temperature,1); //print the temperature on lcd
 lcd.print(" C");
 lcd.setCursor(0, 1);
 lcd.print("Hum:");
 lcd.print(DHT.humidity,1); //print the humidity on lcd
 lcd.print(" %"); 
 delay(200); //wait a while 
}

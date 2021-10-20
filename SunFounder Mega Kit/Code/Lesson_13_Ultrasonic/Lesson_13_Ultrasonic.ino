/************************************************
 * name:Ultrasonic
 * function: if you use a piece of paper to approach or keep it far away from the sensor.
 * You will see the value displayed on the LCD changes, 
 * which indicates the distance between the paper and the ultrasonic sensor.
 *****************************************/
//Email: support@sunfounder.com
//Website: www.sunfounder.com

/**********************************/
#include <LiquidCrystal.h>
#include <NewPing.h>

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);//lcd(RS,E,D4,D5,D6,D7)

#define TRIGGER_PIN  2  //  trig pin on the ultrasonic sensor attach to pin2 .
#define ECHO_PIN     3  //  echo pin on the ultrasonic sensor attach to pin3.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() 
{
  lcd.begin(16, 2); //// set the position of the characters on the LCD as Line 2, Column 16
}

void loop() 
{
  delay(100);                      // Wait 100ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  int distance = uS / US_ROUNDTRIP_CM;
  lcd.setCursor(0, 0);//Place the cursor at Line 1, Column 1. From here the characters are to be displayed
  lcd.print("Distance:");////Print Distance: on the LCD
  lcd.setCursor(0, 1);//Set the cursor at Line 1, Column 0
  lcd.print("             ");//Here is to leave some spaces after the characters so as to clear the previous characters that may still remain.
  lcd.setCursor(9, 1);//Set the cursor at Line 1, Column 9.
  lcd.print(distance);// print on the LCD the value of the distance converted from the time between ping sending and receiving. 
  lcd.setCursor(12, 1);//Set the cursor at Line 1, Column 12.
  lcd.print("cm");//print the unit "cm"
}

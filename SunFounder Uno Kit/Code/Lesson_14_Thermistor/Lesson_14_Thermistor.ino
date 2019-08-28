// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

#define analogPin  A0 //the thermistor attach to 
#define beta 3950 //the beta of the thermistor
#define resistance 10 //the value of the pull-up resistor

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  //read thermistor value
  long a = analogRead(analogPin);
  //the calculating formula of temperature
  float tempC = beta / (log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
  float tempF = 1.8 * tempC + 32.0;
  lcd.setCursor(0, 0); // set the cursor to column 0, line 0
  lcd.print("Temp: ");// Print a message of "Temp: "to the LCD.
  // Print a centigrade temperature to the LCD.
  lcd.print(tempC);
  // Print the unit of the centigrade temperature to the LCD.
  lcd.print(char(223));//print the unit" ℃ "
  lcd.print("C");
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1); // set the cursor to column 0, line 1
  lcd.print("Fahr: ");
  lcd.print(tempF);// Print a Fahrenheit temperature to the LCD.
  lcd.print(" F"); // Print the unit of the Fahrenheit temperature to the LCD.
  delay(200); //wait for 100 milliseconds
}

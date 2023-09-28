/**********************************************************************
//Infrared-Receiver
// press Power on the remote control and the LED attached to pin 13 on the Mega 2560 board will light up. 
//If you press other keys, the LED will go out.
//Email:service@sunfounder.com
//Website:www.sunfounder.com
******************************************************************************/
#include "DHT.h"
#include <LiquidCrystal.h>                //
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);  // initialize the LCD1602

#define DHTPIN 3       // Set the pin connected to the DHT11 data pin
#define DHTTYPE DHT11  // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);    // set up the LCD's number of columns and rows:
  Serial.begin(9600);  //set the baud bit to 9600bps
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
  float humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // DISPLAY DATA
  lcd.setCursor(0, 0);
  lcd.print("Tem:");
  lcd.print(temperature, 1);  //print the temperature on lcd
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(humidity, 1);  //print the humidity on lcd
  lcd.print(" %");
  delay(200);  //wait a while
}

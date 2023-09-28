/************************************************
 * name:Ultrasonic
 * function: if you use a piece of paper to approach or keep it far away from the sensor.
 * You will see the value displayed on the LCD changes, 
 * which indicates the distance between the paper and the ultrasonic sensor.
 *****************************************/
//Email: service@sunfounder.com
//Website: www.sunfounder.com

/**********************************/
#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);  //lcd(RS,E,D4,D5,D6,D7)

const int trigPin = 2;  //  trig pin on the ultrasonic sensor attach to pin2 .
const int echoPin = 3;  //  echo pin on the ultrasonic sensor attach to pin3.

void setup() {
  lcd.begin(16, 2);  //// set the position of the characters on the LCD as Line 2, Column 16
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  float distance = readSensorData();
  //Serial.println(distance); //Print the distance on the serial monitor
  lcd.setCursor(0, 0);         //Place the cursor at Line 1, Column 1. From here the characters are to be displayed
  lcd.print("Distance:");      ////Print Distance: on the LCD
  lcd.setCursor(0, 1);         //Set the cursor at Line 1, Column 0
  lcd.print("             ");  //Here is to leave some spaces after the characters so as to clear the previous characters that may still remain.
  lcd.setCursor(9, 1);         //Set the cursor at Line 1, Column 9.
  lcd.print(distance);         // print on the LCD the value of the distance converted from the time between ping sending and receiving.
  lcd.setCursor(12, 1);        //Set the cursor at Line 1, Column 12.
  lcd.print("cm");             //print the unit "cm"
}


// Function to read data from the ultrasonic sensor
float readSensorData() {
  // Trigger a low signal before sending a high signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Send a 10-microsecond high signal to the trigPin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  // Return to low signal
  digitalWrite(trigPin, LOW);

  // Measure the duration of the high signal on the echoPin
  unsigned long microsecond = pulseIn(echoPin, HIGH);

  // Calculate the distance using the speed of sound (29.00µs per centimeter)
  float distance = microsecond / 29.00 / 2;

  // Return the calculated distance
  return distance;
}

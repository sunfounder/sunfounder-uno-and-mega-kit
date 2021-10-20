//relay
//Email:support@sunfounder.com
//Website:www.sunfounder.com

/******************************************************/
const int relayPin = 8; //the base of the transistor attach to
/******************************************************/
void setup()
{
  pinMode(relayPin, OUTPUT); //initialize the relayPin as an output
}
/******************************************************/
void loop()
{
  digitalWrite(relayPin, HIGH); //drive relay closure conduction
  delay(1000); //wait for a second
  digitalWrite(relayPin, LOW); //drive the relay is closed off
  delay(1000); //wait for a second
}
/******************************************************/


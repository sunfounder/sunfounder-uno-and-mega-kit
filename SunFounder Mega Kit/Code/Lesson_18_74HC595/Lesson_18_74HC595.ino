//74HC595
//You should now be able to see the 7-segment display cycle from 0 to F
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
const int STcp = 12;//Pin connected to ST_CP of 74HC595
const int SHcp = 8;//Pin connected to SH_CP of 74HC595 
const int DS = 11; //Pin connected to DS of 74HC595 
//display 0,1,2,3,4,5,6,7,8,9,A,b,C,d,E,F
int datArray[16] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142};

void setup ()
{
  //set pins to output
  pinMode(STcp,OUTPUT);
  pinMode(SHcp,OUTPUT);
  pinMode(DS,OUTPUT);
}
void loop()
{
  //loop from 0 to 256
  for(int num = 0; num < 16; num++)
  {
    digitalWrite(STcp,LOW); //ground ST_CP and hold low for as long as you are transmitting
    shiftOut(DS,SHcp,MSBFIRST,datArray[num]);
    //return the latch pin high to signal chip that it 
    //no longer needs to listen for information
    digitalWrite(STcp,HIGH); //pull the ST_CPST_CP to save the data
    delay(1000); //wait for a second
  }
}

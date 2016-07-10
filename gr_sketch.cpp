/*GR-KURUMI Sketch Template Version: V1.12*/
#include <Arduino.h>

// Pin 22,23,24 are assigned to RGB LEDs.
int led_red   = 22; // LOW active
int led_green = 23; // LOW active
int led_blue  = 24; // LOW active

unsigned int cntTime = 0;

void myCycle(unsigned long ms)
{
  if ( cntTime == 300 ) {
    digitalWrite(led_red, HIGH);   // turn the RED LED off, glow sky blue.
  }
  if ( cntTime == 600 ) {
    digitalWrite(led_red, LOW);    // turn the RED LED on
    digitalWrite(led_green, HIGH); // turn the GREEN LED off, glow pink.
  }
  if ( cntTime == 900 ) {

    digitalWrite(led_green, LOW);  // turn the GREEN LED on
    digitalWrite(led_blue, HIGH);  // turn the BLUE LED off, glow yellow.
  }
  if ( cntTime == 1200 ) {
    digitalWrite(led_blue, LOW);   // turn the BLUE LED on
    cntTime = 0;
  }
  cntTime++;
}

// the setup routine runs once when you press reset:
void setup() {
  //setPowerManagementMode(PM_STOP_MODE, 0, 1023); //Set CPU STOP_MODE in delay()
  //setOperationClockMode(CLK_LOW_SPEED_MODE); //Set CPU clock from 32MHz to 32.768kHz

  // initialize the digital pin as an output.
  Serial.begin(9600);
//  Serial.print("Temperature: ");
//  Serial.println(getTemperature(TEMP_MODE_CELSIUS)); //temperature from the sensor in MCU
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode( 9, OUTPUT);
  pinMode( 8, OUTPUT);
  pinMode( 7, OUTPUT);
  pinMode( 6, OUTPUT);
  pinMode( 5, OUTPUT);
  
  pinMode( 4, OUTPUT);
  pinMode( 3, OUTPUT);
  pinMode( 2, OUTPUT);
  pinMode( 10, OUTPUT);
  pinMode( 11, OUTPUT);
  pinMode( 12, OUTPUT);

//  analogWriteFrequency(40000);
//  analogWriteFrequency(62000);
  analogWriteFrequency(700);

  // turn the LEDs on, glow white.
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, LOW);
  digitalWrite(led_blue, LOW);
  //analogWrite( 9, 32);
//  analogWrite( 9, 128);
  analogWrite( 9, (256 - 10) );
  
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);  
  digitalWrite(4, LOW); 
  
  randomSeed( 11369 );
  
// attachMicroIntervalTimerHandler( myCycle, 97 );
  attachIntervalTimerHandler( myCycle );
}


void bcd2ten(int val)
{
#if 0
#else
	switch( (val % 10) ) {

	case 0:
		digitalWrite(2, HIGH);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(10, LOW);
		digitalWrite(11, LOW);
		digitalWrite(12, LOW);
		break;
	case 1:
		digitalWrite(2, LOW);
		digitalWrite(3, HIGH);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(10, LOW);
		digitalWrite(11, LOW);
		digitalWrite(12, LOW);
		break;
	case 2:
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, HIGH);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(10, LOW);
		digitalWrite(11, LOW);
		digitalWrite(12, LOW);
		break;
	case 3:
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, HIGH);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(10, LOW);
		digitalWrite(11, LOW);
		digitalWrite(12, LOW);
		break;
	case 4:
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, HIGH);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(10, LOW);
		digitalWrite(11, LOW);
		digitalWrite(12, LOW);
		break;
	case 5:
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, HIGH);
		digitalWrite(8, LOW);
		digitalWrite(10, LOW);
		digitalWrite(11, LOW);
		digitalWrite(12, LOW);
		break;
	case 6:
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, HIGH);
		digitalWrite(10, LOW);
		digitalWrite(11, LOW);
		digitalWrite(12, LOW);
		break;
	case 7:
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(10, HIGH);
		digitalWrite(11, LOW);
		digitalWrite(12, LOW);
		break;
	case 8:
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(10, LOW);
		digitalWrite(11, HIGH);
		digitalWrite(12, LOW);
		break;
	case 9:
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(10, LOW);
		digitalWrite(11, LOW);
		digitalWrite(12, HIGH);
		break;
	default:
		digitalWrite(2, HIGH);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(10, LOW);
		digitalWrite(11, LOW);
		digitalWrite(12, LOW);
	}
#endif	
}

unsigned int cnt = 0;
unsigned int cntLoop = 0;

// the loop routine runs over and over again forever:
void loop() {
//  Serial.println("Hello");
  bcd2ten( cnt );
  if ( cntLoop < 20 ) {
    delay(100);  
  }
  if (cntLoop >= 20 ) {
     delay(2000);  
     cntLoop = 0;
  }
  cnt += random( 1, 9 );
  cnt = (cnt % 10);
  cntLoop++;
}

//Karnasinh Gohil
//Student ID : 200478377
//1st April 2021
/*Description: Shows how many customer are in the store and 
			   based on that display total value and a message 
			   weather customer should wait outside or go inside.*/
//Purpose : To use different electronic part togather and write codes for them to work properly.

//Declared library.
#include <LiquidCrystal.h>

//Declared variables.
LiquidCrystal lcd( 12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack board.
int entryPRI = 6; //Entry PRI sensor to pin 6 on arduino board.
int exitPRI = 8; //Exit PRI sensor to pin 8 on arduino board.
int customer = 0; //Variable to count number of customer inside the stoor.
int RedPin = 10; //Assignment pin 10 for Red anode power source.
int GreenPin = 13; //Assignment pin 13 for Green anode power source.

/*Declaration of setup() function,
  this will run only ones as the Arduino unit powers up*/ 
void setup()
	{
		Serial.begin(9600); //To print value on serial port.
		
		pinMode(entryPRI, INPUT); //Setup entry door PRI senson, signals flow from bread board to pin 6 as an input.
		pinMode(exitPRI, INPUT); //Setup exit door PRI sensor, signals flow from bread board to pin 8 as an input.
		
		pinMode(RedPin, OUTPUT); //Setup RGBRedPin, Power flows from Pin 10 as an output.
		pinMode(GreenPin, OUTPUT); //Setup RGBRedPin, Power flows from Pin 13 as an output.			
		lcd.begin (16,2); //Initialize display of the LCD.
	}

/*Declaration of loop() function,
  this will run repeatedly as the Arduino unit powers up,
  but after setup() function called.*/
void loop()
	{	
	
		Serial.print("Entry Sensor ="); //Printing message on the serial port.
		Serial.println(digitalRead(entryPRI)); //Printing vlaue of entryPRI on the serial port.
		delay(1000);
		Serial.print("Exit Sensor ="); //Printing message on the serial port.
		Serial.println(digitalRead(exitPRI)); //Printing vlaue of exitPRI on the serial port.
		
		//if condition to check weather any motion has detected at the Entry door or not.  		
		if(digitalRead(6) == HIGH)
		{	
			//Increment in customer variable as the motion detects at the entrance.
			customer++;
			//Delay next line of code by 300 milliseconds.
			delay(300);
		}
		
		//Delay next line of code by 300 milliseconds.
  		delay(500);
		
		 //if condition to check weather any motion has detected at the Exit door or not.  		
		if(digitalRead(9) == HIGH)
		{	
			//Decrement in customer variable as the motion detects at the entrance.
			customer--;
			delay(300);
		}
		
		//Turn on Green light and display message on the LCD screen as the customer inside is less than 6.
		if(customer <=5)
		{
          lcd.clear(); //Clearing the LCD screen.
          lcd.setCursor(0,0); //Set cursor to 0th position on 1st row.
          lcd.print("Customer : "); //Printing message
          lcd.print(customer); //Printing number of customer inside the store.
          lcd.setCursor(0,1); //Set cursor to 0th position on 1st row.
          lcd.print("Please Enter"); 
          delay(500);

          digitalWrite(RedPin, LOW); //Turn off Red light in RGBLED.
          digitalWrite(GreenPin, HIGH); //Turn on Green light in RGBLED.
		}
  
		//Turn on red light and display message on the LCD screen as the customer inside is more than 5.
		if(customer >5)
		{
			
          lcd.clear(); //Clearing the LCD screen.
          lcd.setCursor(0,0); //Set cursor to 0th position on 1st row.
          lcd.print("Customer : ");
          lcd.print(customer); //Printing number of customer inside the store.
          lcd.setCursor(0,1); //Set cursor to 0th position on 1st row.
          lcd.print("Do not enter");
          delay(500);

          digitalWrite(RedPin, HIGH); //Turn on Red light in RGBLED.
          digitalWrite(GreenPin, LOW); //Turn off Green light in RGBLED.          	
		}		
	}

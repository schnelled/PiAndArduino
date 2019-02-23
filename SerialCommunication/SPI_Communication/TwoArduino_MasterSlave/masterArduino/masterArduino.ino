// SPI Maser (Arduino)
// Author: schnelled (Dustin Schnelle)
// Date: 2/22/19
// Definition: SPI communication between two Arduino

// Import the SPI library
#include<SPI.h>

// Define constant variables
#define LED 7
#define BUTTON 2

// Define and initialize variables
int buttonValue;
int x;

// Setup section for the project
void setup(void)
{
  // Setup serial communication (Baud Rate 115200)
  Serial.begin(115200);
  
  // Setup the inputs & outputs
  pinMode(buttonValue, INPUT);
  pinMode(LED, OUTPUT);
  
  // Begin the SPI communication
  SPI.begin();
  // Set clock for SPI communication at 8 (16/8=2Mhz)
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  // Setting SlaveSelect as HIGH
  digitalWrite(SS, HIGH);
}
  
// Loop section for the project
void loop(void)
{
  // Setup byte variables
  byte masterSend;
  byte masterReceive;
  
  // Reads the status of the pin 2
  buttonValue = digitalRead(BUTTON);
  
  // Check if the button value is HIGH (pushed)
  if(buttonValue == HIGH)
  {
   x = 1; 
  }
  // Other the button value is LOW (not pushed)
  else
  {
   x = 0; 
  }
  
  // Starts communication with Slave
  digitalWrite(SS, LOW);
  
  // Set the master send byte to 1
  masterSend = x;
  // Send the masterSend value
  // Also receive value from slave (masterReceive)
  masterReceive = SPI.transfer(masterSend);
  
  // Check received byte (from slave) to set LED output
  if(masterReceive == 1)
  {
    // Turn on the master LED
    digitalWrite(LED, HIGH);
    Serial.println("Master LED ON");
  }
  else
  {
   // Turn off the master LED
   digitalWrite(LED, LOW);
   Serial.println("Master LED OFF"); 
  }

  //Delay of 0.1 seconds
  delay(100);
}

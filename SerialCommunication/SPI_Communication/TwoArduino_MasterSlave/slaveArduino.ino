// SPI Slave (Arduino)
// Author: schnelled (Dustin Schnelle)
// Date: 2/22/19
// Definition: SPI communication between two Arduino

// Import the SPI library
#include<SPI.h>

// Define constant variables
#define LED 7
#define BUTTON 2

// Define and initialize variables
volatile boolean received;
volatile byte slaveReceived, slaveSend;
int buttonValue;
int x;

// Setup section for the project
void setup(void)
{
 // Setup serial communication (Baud Rate 115200)
 Serial.begin(115200);

 // Setup the inputs & outputs
 pinMode(BUTTON, INPUT);
 pinMode(LED, OUTPUT);
 pinMode(MISO, OUTPUT);
 
 // Turn on the SPI slave mode
 SPCR |= _BV(SPE);
  
 // Set received to false
 received = false;
  
 // Interrupt ON is set for SPI communication
 SPI.attachInterrupt();
}

// Function: ISR (Interrupt Function)
// Input: SPI_STC_vect
// Output: None
// Decription: Handle interrupts
ISR(SPI_STC_vect)
{
 // Set the slave received
 slaveReceived = SPDR;
 // Set received to True
 received = true; 
}

// Loop section for the project
void loop(void)
{
 // Check if received is set to true
 if(received)
 {
  // Check if slaveReceived is 1
  if(slaveReceived == 1)
  {
   // Turn on the slave LED
   digitalWrite(LED, HIGH);
   Serial.println("Slave LED ON");
  }
  // Otherwise turn off the slave LED
  else
  {
   // Turn off the slave LED
   digitalWrite(LED, LOW);
   Serial.println("Slave LED OFF");
  }
 
  // Read the button value
  buttonValue = digitalRead(BUTTON);
 
  // Check if the button value is HIGH (pushed)
  if(buttonValue == HIGH)
  {
   x = 1;
  }
  // Otherwise the button value is LOW (not pushed)
  else
  {
   x = 0; 
  }
  
  // Set the value of slaveSend
  slaveSend = x;
  // Send the x value to the master via SPDR
  SPDR = slaveSend;
  // Delay of one second
  delay(1000);
 }
}

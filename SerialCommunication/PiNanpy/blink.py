#-------------------------------------------------------------------------------
# Program: blink.py
# Author: schnelled (Dustin Schnelle)
# Date: 2/22/19
# Description: Turns on an LED for one second, then off for one second, repeat
#-------------------------------------------------------------------------------
from nanpy import (ArduinoApi, SerialManager)
from time import sleep

# Setup the variable (LED)
LED = 13

# Attempt to connect the Arduino
try:
    # Connect and create the Arduino
    connection = SerialManager()
    a = ArduinoApi(connection = connection)
# Otherwise it failed to connect
except:
    # Print error message
    print("Error: Failed to connect to Arduino!")

# Setup the pinMode as if we were in the Arduino IDE
a.pinMode(LED, a.OUTPUT)

try:
    # Continuous loop
    while True:
        # Turn on the LED
        a.digitalWrite(LED, a.HIGH)
        # Wait one second
        sleep(1)
        # Turn off the LED
        a.digitalWrite(LED, a.LOW)
        # Wait one second
        sleep(1)
except:
    # Turn off the LED
    a.digitalWrite(LED, a.LOW)

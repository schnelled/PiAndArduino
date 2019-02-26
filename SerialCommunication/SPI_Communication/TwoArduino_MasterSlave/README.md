<h1>Two Arduino: Master slave</h1>
<p>This folder shows how to communicate between two Arduinos. SPI protocol is used for communication between two Arduino. One Arduino is the master and the other is the slave.</p>

<h3>Method of showing SPI Connection</h3>
<p>Two LEDs and two push buttons will be connected to the Arduinos. To demonstrate SPI communication, we will control the master side LED by push button at slave side(MISO). We will control the slave side LED by push button at master side(MOSI).</p>

<h3>Needed Devices</h3>
<p>Below is a list of required hardware & equipment</p>
<ul>
  <li>Arduino x2</li>
  <p>I chose the <a href="https://store.arduino.cc/usa/arduino-nano">Arduino Nano</a> for this project</p>
  <li>USB cable to connect Arduino to PC</li>
  <li>Jumper Wires</li>
</ul>

<h3>Needed Software</h3>
<p>Below is a list of required software</p>
<ul>
  <li><a href="https://www.arduino.cc/en/main/software">Arduino IDE</a></li>
  <ul>
    <li><a href="https://www.arduino.cc/en/Reference/SPI">Arduino SPI library</a></li>
  </ul>
</ul>

<h3>Arduino SPI Information</h3>
<p><strong>Connections/Pins</strong></p>
<p>Arduino pins 11-13 are used by the SPI library</p>
<ul>
  <li><strong>SKC (Serial Clock)</strong> -> Clock pulses to synchronize data transmission (Pin13)</li>
  <li><strong>MISO (Master In/ Slave Out)</strong> -> The Slave line for sending data to the master (Pin12)</li>
  <li><strong>MOSI (Master Out/ Slave In)</strong> -> The Master line for sending data to the peripherals (Pin11)</li>
  <li><strong>SS (Slave Select)</strong> -> Enable & disable specific devices (Pin10)</li>
</ul>

<h3>Steps:</h3>
<ol>
  <li>Wire the circuit as shown below</li>
  <img src="https://github.com/schnelled/PiAndArduino/blob/master/SerialCommunication/SPI_Communication/TwoArduino_MasterSlave/Documents/CircuitLayout.png">
  <li>Upload the masterArduino sketch to the master Arduino device</li>
  <li>Upload the slaveArduino sketch to the slave Arduino device</li>
</ol>

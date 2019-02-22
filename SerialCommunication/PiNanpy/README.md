<h1>Pi master & Adrunio slave using Nanpy module</h1>
<p>This folder contains the steps needed to setup the serial connection using the Python Nanpy module. It also
contains a test program in order to confirm that the connection is setup correctly (Blink Program).</p>

<h3>Needed Devices</h3>
<p>Below is a list of required hardware & equipment</p>
<ul>
  <li>Arduino Device</li>
  <p>I chose to use an <a href="https://store.arduino.cc/usa/arduino-nano">Arduino Nano</a></p>
  <li>Raspberry Pi</li>
  <p>I chose to use the <a href="https://www.raspberrypi.org/products/raspberry-pi-3-model-b/">Raspberry Pi 3 Model B</a> for the project because of its WIFI capability</p>
  <li>USB Cabel</li>
  <p>Used to connect the Pi to the Arduino</p>
  <li>Power Supply for the Raspberry Pi</li>
  <li>Mouse & Keyboard for the Raspberry Pi</li>
</ul>

<h3>Steps:</h3>
<ol>
  <li>Connect the USB cabel to the Pi & Arduino</li>
  <li>Update the Pi software</li>
  
  ```
  sudo apt-get install update
  ```
  
  <li>Install Arduino IDE on the Arduino</li>
  
  ```
  sudo apt-get install arduino -y
  ```
  
  <li>Download the needed Nanpy libraries on the Pi</li>
  
  ```
  git clone https://github.com/nanpy/nanpy
  git clone https://github.com/nanpy/nanpy-firmware
  ```
  
  <li>Configure firmware that will be updated to the Arduino</li>
  
  ```
  cd nanpy-firmware
  ./configure.sh
  ```
  
  <li>Copy the nanpy-firmware directory to the directory that stored the Arduino libraries</li>
  
  ```
  cd ..
  sudo cp -avr nanpy-firmware/ /usr/share/arduino/libraries
  mv nanpy-firmware/ Nanpy_Firmware
  ```
  
  <p><em>Note:</em> If you need to locate the directory that stores the Arduino libraries use the following command</p>
  
  ```
  sudo dpkg -L arduino
  ```
  
  <li>Start the Arduino IDE & open the nanpy sketch</li>
  <p>File->Examples->Nanpy_Firmware->Nanpy</p>
  
  <li>Upload the sketch to the Arduino</li>
  
  <li>Install Nanpy on the Raspberry Pi</li>
  
  ```
  cd nanpy
  sudo python3 setup.py install
  cd ..
  ```
  
  <li>Run the blink.py program</li>
  
  ```
  python3 blink.py
  ```
  
</ol>

# Lora-sensor-monitoring-using-Arduino
A small cool and very informative project, to show "how Long range radio system can work with sensors". Let's build one with own.
Get more info directly from instructables:

There are various sensor monitoring methods are available some of them using IoT and others using offline protocols like Bluetooth and BLE. But the offline method doesn’t offer a good range and online methods are expensive and very compilated. Today, we are going to make a simple sensor monitoring system using LoRa (long range radio). LoRa supports a very long range of 7-10 miles and data can be transferred without internet. It is quite similar to walkie talkie.
This article is brought to you by JLCPCB- PCB manufacturer from CHINA offers 5pcs of 2layer PCB boards just in $2.
https://jlcpcb.com/SSR
https://jlcpcb.com/SSR
https://jlcpcb.com/SSR

Components used:
LoRa RA01 module
Arduino Nano
Jumper wires
DHT11 sensor
5v power supply
USB and programmer
Custom PCB from JLCPCB

Circuit diagram:
Because my Lora module RA01 works on SPI interface so an external library is used for the communication. Here MOSI, MISO and SCK pins are connected to D11, 12 and 13 respectively. For reset we are using D9 and D10 NSS(Enable). No need to define these pins in code because these are default with the Lora library. D0 of the Lora is connected to D2 of the Arduino. LoRa works on 3.3volts, 5v can damage the entire setup.
DHT11 sensor is connected to the transmitter which reads the data. Any blank digital pin can be assigned for DHT. Then Arduino process that and make a string of that data to send to the receiver. the connections for the lora are same on both receiver and transmitter end. I am using Arduino nano for the receiver and UNO for the transmitter only for demonstration purpose.
The receiver connections are also same and instead of any external screen we are using Arduino IDE serial monitor to display the values. We can use one receiver for many devices just change the to change the address, but this is the topic for another article.

Libraries used:
Here I am using LoRa library by Sandeep Mistry, it is very well optimized library for SPI protocol LoRa modules. You can also see more examples and go through each of them in order to make some new projects.

Project working:
In this way you can read any data from sensor, the data is just a value that can be send over air to long distances using string functions in LoRa. Now sometimes the received data is just mistitled because of voltage fluctuations and noise. But you can add an external capacitor between power lines and reset the microcontroller which can solve this problem.

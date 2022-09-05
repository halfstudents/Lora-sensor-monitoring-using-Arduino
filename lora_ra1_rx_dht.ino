#include <SPI.h>
#include <LoRa.h>



void setup() {
  //initialize Serial Monitor
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Receiver");

  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe/Africa
  //915E6 for North America
  if(!LoRa.begin(433E6)) {
    Serial.println(".");
    while (1);
  }
   // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

void loop() 
{

  String LoRaData; 
  int packetSize = LoRa.parsePacket();
  if (packetSize) 
  {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available())
    {
      LoRaData = LoRa.readString();
      Serial.println(LoRaData); 
    }

    // print RSSI of packet
 //   Serial.print("' with RSSI ");
//    Serial.println(LoRa.packetRssi());
    
   }
}

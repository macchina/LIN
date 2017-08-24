/*  LIN Sniffer - Monitor traffic on LIN Bus
 *
 *  Written in September 2016 by Blaž Pongrac B.S., RoboSap, Institute of Technology, Ptuj (www.robosap-institut.eu) for Macchina LLC
 *
 *  To the extent possible under law, the author(s) have dedicated all copyright and related and neighboring rights to this software to the public domain worldwide. This software is distributed without any warranty.
 *
 *  You should have received a copy of the CC0 Public Domain Dedication along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 
 *  
 *  Using LIN Stack v2.0 Library (https://github.com/macchina/LIN)
 *  
 *  Developed against Arduino IDE 1.6.9
 */

// Including LIN Stack library
#include <lin_stack.h>

// Variables
const byte ident = 0; // Identification Byte
byte data_size=8; // length of byte array
byte data[8]; // byte array for received data

// Creating LIN Object
lin_stack LIN1(1,ident); // 1 - channel, ident - Identification Byte

void setup() {
  SerialUSB.begin(9600); // Configure Serial for Serial Monitor
  LIN1.setSerial(); // Configure Serial for receiving
}

void loop() {
  // Checking LIN Bus periodicly
  byte a = LIN1.readStream(data, data_size);
  if(a == 1){ // If there was an event on LIN Bus, Traffic was detected. Print data to serial monitor
     SerialUSB.println("Traffic detected!");
     SerialUSB.print("Synch Byte: ");
     SerialUSB.println(data[0]);
     SerialUSB.print("Ident Byte: ");
     SerialUSB.println(data[1]);
     SerialUSB.print("Data Byte1: ");
     SerialUSB.println(data[2]);
     SerialUSB.print("Data Byte2: ");
     SerialUSB.println(data[3]);
     SerialUSB.print("Data Byte3: ");
     SerialUSB.println(data[4]);
     SerialUSB.print("Data Byte4: ");
     SerialUSB.println(data[5]);
     SerialUSB.print("Data Byte5: ");
     SerialUSB.println(data[6]);
     SerialUSB.print("Check Byte: ");
     SerialUSB.println(data[7]);
     SerialUSB.print("\n");
  } 
}

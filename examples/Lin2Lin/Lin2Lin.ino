/*  Copyright (c) 2016 Macchina
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 *  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 *  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
 *
 *  LIN to LIN Gateway
 *  
 *  Using LIN Stack v2.0 Library.
 *  
 *  Author: Blaž Pongrac B.S., RoboSap, Institute of Technology, Ptuj (www.robosap-institut.eu)
 *  
 *  Arduino IDE 1.6.9
 *  RoboSap, Institute of Technology, September 2016
 */
 // include LIN Stack Library
#include <lin_stack.h>

// Variables
const byte ident = 0; // Identification Byte
byte data_size=8; // length of byte array
byte data[8]; // byte array for received data

// LIN Objects
lin_stack LIN1(1,ident); // Sniffer - reads Traffic on LIN Bus
lin_stack LIN2(2); // Master - write data to LIN Bus

void setup() {
  SerialUSB.begin(9600); // Configure Serial for Serial Monitor
  LIN1.setSerial(); // Configure Serial for receiving
}

void loop() {
  // Checking LIN Bus periodicly
  byte a = LIN1.readStream(data, data_size);
  if(a==1){ // If there was an event on LIN Bus, Traffic was detected. Print data to serial monitor
    LIN2.writeStream(data, data_size); // write data to LIN Bus
    // Print received data, needed for monitoring, non-mandatory
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

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
 *  LIN Master: Microchip Ambient Light Module
 *  
 *  Using LIN Stack v2.0 Library.
 *  
 *  Author: Blaž Pongrac B.S., RoboSap, Institute of Technology, Ptuj (www.robosap-institut.eu)
 *  
 *  Arduino IDE 1.6.9
 *  RoboSap, Institute of Technology, July 2016
 */
// Include LIN Stack library
#include <lin_stack.h>

lin_stack LIN2(2); // Creating LIN Stack objects, 2 - second channel
//lin_stack LIN1(1); // Creating LIN Stack objects, 1 - first channel

void setup() {
  // Nothing to do here.
}

void loop() {
  // Create Data Package
  byte package[5] = {31, 255, 0, 0, 3}; // 31 - control byte, 255 - red, 0 - green, 0 - blue, 3 - zone
  LIN2.write(0xA3, package, 5); // Write data to LIN
//  byte package2[5] = {31, 0, 255, 0, 3}; // 31 - control byte, 0 - red, 255 - green, 0 - blue, 3 - zone
//  LIN1.write(0xA3, package2, 5); // Write data to LIN
  delay(10000); // 10 s delay is used for testing Sniffer and LIN2LIN Gateway examples, lower value can be used
}

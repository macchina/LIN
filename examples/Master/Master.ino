/*  LIN Master - Microchip Ambient Light Module
 *
 *  Written in July 2016 by Blaž Pongrac B.S., RoboSap, Institute of Technology, Ptuj (www.robosap-institut.eu) for Macchina LLC
 *
 *  To the extent possible under law, the author(s) have dedicated all copyright and related and neighboring rights to this software to the public domain worldwide. This software is distributed without any warranty.
 *
 *  You should have received a copy of the CC0 Public Domain Dedication along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 
 *  
 *  Using LIN Stack v2.0 Library (https://github.com/macchina/LIN)
 *  
 *  Developed against Arduino IDE 1.6.9
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

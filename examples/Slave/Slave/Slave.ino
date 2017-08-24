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
// Including NonDuePin library for controlling LEDs
#include <SamNonDuePin.h>

// Variables
const byte ident = 0x11; // Identification Byte
byte data_size=2; // length of byte array
byte data[2]; // byte array for received data

const int LED_1 = X0; // LED pin number
const int LED_2 = 32; // LED pin number

// Creating LIN Object
lin_stack LIN1(1,ident); // 1 - channel, ident - Identification Byte

void setup() {
  // Configure LED 1
  pinModeNonDue(LED_1, OUTPUT);
  digitalWriteNonDue(LED_1, HIGH);
  // Configure LED 2
  pinMode(LED_2, OUTPUT);
  digitalWrite(LED_2, HIGH);
  // Configure Serial communication
  SerialUSB.begin(9600); // Configure Serial for Serial Monitor
  LIN1.setSerial(); // Configure Serial for receiving
}

void loop() {
  // Checking LIN Bus periodicly
  byte a = LIN1.read(data, data_size);
  if(a == 1){ // If there was an event on LIN Bus, Traffic was detected. Print data to serial monitor
    SerialUSB.println("Request Received!");
    SerialUSB.print("Data Byte 1: ");
    SerialUSB.println(data[0]);
    SerialUSB.print("Data Byte 2: ");
    SerialUSB.println(data[1]);
    if(data[0] == 255){ // LED ON
      digitalWriteNonDue(LED_1, LOW);
    }else if(data[0] == 0){ // LED OFF
      digitalWriteNonDue(LED_1, HIGH);
    }
    if(data[1] == 255){ // LED ON
      digitalWrite(LED_2, LOW);
    }else if(data[0] == 0){ // LED OFF
      digitalWrite(LED_2, HIGH);
    }
  }else if(a == -1){ // Ident and Checksum validation Failed
    SerialUSB.println("Corrupt Request Received!");
  }
}

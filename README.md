## LIN Library

Library and examples for LIN [(Local Interconnect Network)](https://en.wikipedia.org/wiki/Local_Interconnect_Network) on Arduino. Developed for the Macchina M2.  Can be modified for any Arduino board with UART available and any LIN slave.

#### Install

1. Download the files
2. Move the folder `LIN` to your Arduino Libraries

#### EXAMPLES

Several example sketches are included in the LIN Library to demonstrate typical usage:

* `Lin2Lin` M2 acts as the Sniffer – when traffic on one LIN channel is detected, incoming data is saved and then sent to another LIN channel with no modification. Arduino Due with simple 1-bit ADC is used as Master Node on first LIN bus and Ambient Light Module is used as a slave on another LIN bus.

* `Master` works with Microchip’s Ambient Light Module. User builds an array of bytes, which is the length of the message and contains packages to be send to the module. Package is built out of Control Byte (control intensity, dim and ramp functions for the RGB LED), Red, Green and Blue Color Bytes and Zone Byte.
Checksum calculation is supported in v2.0 library. There is no need to calculate checksum and include in it package.

* `Slave` M2 acts like sniffer: when traffic is detected on LIN bus, incoming data is saved and processed. Arduino Due with simple 1-bit ADC is used as master. Master Node needs to be programmed with Master example `Slave_Master`

 Data processing: If Identification Byte is correct, Checksum Byte is compared with Checksum calculated from received data. If Checksum Byte is correct, data is printed on Serial Monitor via SerialUSB. Otherwise error is printed on Serial Monitor and data cleared.

* `Sniffer` M2 monitors traffic on LIN bus periodically. When traffic is detected, Sniffer reads incoming data and prints it on Serial Monitor via SerialUSB.

#### NOTES

LIN Stack was developed using the following:

* Microchip PC to LIN Communications LIN Serial Analyzer
http://ww1.microchip.com/downloads/en/DeviceDoc/LINSerialAnalyzerRev2.pdf

* Microchip’s LIN Application Note (AN729) http://ww1.microchip.com/downloads/en/AppNotes/00729a.pdf

* Microchip’s Interior Ambient Lighting Module with LIN Interface User Guide
http://ww1.microchip.com/downloads/en/DeviceDoc/51714a.pdf

* TJA1021 Datasheet and NXP’s LIN protocol description.
http://cache.nxp.com/documents/data_sheet/TJA1021.pdf?pspll=1

More information about LIN can be found in those documents.


#### Changes duronflo

- correct checksum calculation, removed +1
- inserted parity calculation in writeRequest method
- implemented parity calculation
- implemented bus wake up for proper lin bus waking up
- Changed default baudrate to 19200 which is more common in automotive applications
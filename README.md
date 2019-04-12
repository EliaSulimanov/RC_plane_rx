# RC Plane RX
[![Elia Sulimanov](https://image.ibb.co/mBx97A/powerd-by-Elia-Sulimanov.jpg)](https://www.linkedin.com/in/elia-sulimanov/)

2.4 GHZ, 5 channel RC RX. Made for plane but can be used for any craft.
### This project made with and for ATtiny84 platform.

## Contents
 - [How it works](#how-it-works)
 - [Quick start](#quick-start)
    - [Installing](#installing)
    - [Using](#using)
 - [Related Projects](#related-projects)
 - [License](#license)
 
 ## How It Works
 - The receiver is reading radio 2.4 GHZ signals.
 - When the receiver reads a message sent by the TX he is translating it to operation.
 - Please view the [transmitter](https://github.com/EliaSulimanov/6-Channel-RC-TX) code for further understanding about how the message is looks like.
 
## Quick start
### Installing
First make sure arduino enviorment is installed on your pc and ATtiny84 board is available.  
In order to compile and use this code you must include nRF24L01 lib. more info here: [maniacbug/RF24](https://github.com/maniacbug/RF24/blob/master/README.md)
Next upload this code to your ATtiny84 using arduino as ISP.

### Using
All you need to do is just wire a breadboard/pcb using the following guidelines:
 - Pin 0 - RF24 CE
 - Pin 1 - RF24 CS
 - Pin 2 - RF24 MOSI
 - Pin 3 - RF24 MISO
 - Pin 4 - RF24 SCK
 - Pin 5 - Wing leds
 - Pin 6 - Tail led
 - Pin 7 - Rudder servo
 - Pin 8 - Elevators servo
 - Pin 9 - Alierons servo
 - Pin 10 - Motor  
 
 You are good to go!

## Related Projects
* [Cessna 182 Lights](https://github.com/EliaSulimanov/Cessna-182-Lights)
* [6 Channel RC TX](https://github.com/EliaSulimanov/6-Channel-RC-TX)

## License
GNU General Public License v3.0

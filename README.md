# Conveyor

To read the value of encoder, The Teensy 3.2 Micro-controller is used and following software are installed:
 1.  [Arduino Software](https://www.arduino.cc/en/Main/Software): The open-source Arduino Software (IDE) makes it easy to write code and upload it to the board
 2. [Teensyduino Installer](https://www.pjrc.com/teensy/td_download.html): Teensyduino is a software add-on for the Arduino software.

To program Teensy 3.2, a code called encoder.ino  is written in C++ and stored in the repository. It is a simple code that makes encoder objects, setup serial communications, and read the value of encoder if it is available.

<strong>Encoder encoder(pin1, pin2)</strong>
Create an Encoder object, using 2 pins. You may create multiple Encoder objects, where each uses its own 2 pins. The first pin should be capable of interrupts. If both pins have interrupt capability, both will be used for best performance. The encoder will also work in low-performance polling mode if neither pin has interrupts.<br>

<strong>encoder.read()</strong>
Returns the accumulated position. This number can be positive or negative. That is why the absolute value is used  to always get the positive value.<br>

<strong>enccoder.write(newPosition)</strong>
Set the accumulated position to a new number. For more information see [Teensy Encoder Library](https://www.pjrc.com/teensy/td_libs_Encoder.html)

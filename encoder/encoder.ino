/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder encoder(5, 6);
//   avoid using pins with LEDs attached

void setup()
{
  Serial.begin(9600);
}

long const limit = 0x000001000; // 4096
// long const limit = 0x00100000; // 2^20

void loop()
{
  long newPosition = encoder.read();

  if (newPosition > limit)
  {
    newPosition -= limit;
    encoder.write(newPosition);
  }

  if (Serial.available())
  {
    while (Serial.read() > 0)
      ;

    Serial.println(newPosition, DEC);
  }
}

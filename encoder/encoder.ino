

#include <Encoder.h>
#include <cmath>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability

// Const Limit of encoder to take care of overflow
long const limit = 0x00100000; // 2^20

/*
 * Create encoder object
 */
Encoder encoder(8, 9);

/*
 * Set Up Serial communication with byte rate 9600
 */
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13,HIGH);
}

void loop()
{
  long newPosition = abs(encoder.read());

  if (newPosition > limit)
  {
    newPosition -= limit;
    encoder.write(newPosition);
  }

  if (Serial.available())
  {
    while (Serial.read() > 0);

    Serial.println(newPosition, DEC);
  }
}

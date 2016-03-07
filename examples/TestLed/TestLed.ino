/**
 * @file "TestLed.ino"
 * Example sketch for a Quick and dirty 24bit RGB LED class/library for digital PWM pins
 *
 * @authot     Jaime Martínez-Figueroa <jmf@charliefoxtrot.cl>
 * @date       Feb 2016
 * @copyright  2016 Charlie Foxtrot Electronics, LGPL
 */

#include <AnalogColorLed.h>

int i = 0;

AnalogColorLed testLed(9, 10, 11); // normal, for common cathode LEDs
// AnalogColorLed testLed(9, 10, 11, NEGATIVE); // negative logic, for common anode LEDs

// the setup function runs once when you press reset or power the board
void setup() {
  // first we turn on the LED all white
  testLed.setColor(WHITE);
  delay(1000);


  for(i = 0; i <= 255; i++) {
    testLed.setColor(255-i, 255-i, 255-i);
    delay(10);
  }

  // then we test the BLUE channel
  for(i = 0; i <= 255; i++) {
    testLed.setColor(0, 0, i);
    delay(10);
  }

  for(i = 0; i <= 255; i++) {
    testLed.setColor(0, 0, 255-i);
    delay(10);
  }

  // then we test the GREEN channel
  for(i = 0; i <= 255; i++) {
    testLed.setColor(0, i, 0);
    delay(10);
  }

  for(i = 0; i <= 255; i++) {
    testLed.setColor(0, 255-i, 0);
    delay(10);
  }

  // finally we test the RED channel
  for(i = 0; i <= 255; i++) {
    testLed.setColor(i, 0, 0);
    delay(10);
  }
}

// the loop function runs over and over again forever
void loop() {
  for(i = 0; i <= 255; i++) {
    testLed.setColor(255-i, i, 0);
    delay(50);
  }

  for(i = 0; i <= 255; i++) {
    testLed.setColor(0, 255-i, i);
    delay(50);
  }

  for(i = 0; i <= 255; i++) {
    testLed.setColor(i, 0, 255-i);
    delay(50);
  }
}

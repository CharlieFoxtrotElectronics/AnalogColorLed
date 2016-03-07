/**
 * @file "AnalogColorLed.cpp"
 * Quick and dirty 24bit RGB LED class/library for digital PWM pins
 *
 * @authot     Jaime Martínez-Figueroa <jmf@charliefoxtrot.cl>
 * @date       Feb 2016
 * @copyright  2016 Charlie Foxtrot Electronics, LGPL
 */

#include "AnalogColorLed.h"

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/**
 * Constructor method
 * 
 * @param r    Red pin
 * @param g    Green pin
 * @param b    Blue pin
 * @param mode Mode of the LED: POSITIVE for common cathode, NEGATIVE for common anode
 */
AnalogColorLed::AnalogColorLed(uint8_t r, uint8_t g, uint8_t b, AnalogColorLedMode_e mode) {
  _pin[0] = r;
  _pin[1] = g;
  _pin[2] = b;

  _mode = mode;

  pinMode(_pin[0], OUTPUT);
  pinMode(_pin[1], OUTPUT);
  pinMode(_pin[2], OUTPUT);

  _update();
}

/**
 * Destructor method (does nothing)
 */
AnalogColorLed::~AnalogColorLed() {
  // does nothing
}

/**
 * Sets the color to be displayed and updates the output
 * 
 * @param r Red status (0 to 255) 
 * @param g Geen status (0 to 255) 
 * @param b Blue status (0 to 255) 
 */
void AnalogColorLed::setColor(uint8_t r, uint8_t g, uint8_t b) {
  _set_color(r, g, b);

  _update();
}

/**
 * Sets the color to be displayed and updates the output
 * 
 * @param color  24bit color code (0x000000 to 0xFFFFFF)
 */
void AnalogColorLed::setColor(uint32_t color) {
  _set_color(
    (uint8_t)((color & 0xFF0000) >> 16), 
    (uint8_t)((color & 0x00FF00) >> 8), 
    (uint8_t)(color & 0x0000FF)
  );

  _update();
}

/**
 * Turns off all the colors of the LED
 */
void AnalogColorLed::off() {
  _set_color(0, 0, 0);

  _update();
}

/**
 * Updates the status of the outputs to match _current_color[]
 */
void AnalogColorLed::_update() {
  uint8_t i;

  for(i = 0; i < 3; i++) {
    analogWrite(_pin[i], _current_color[i]);
  }
}

/**
 * Sets the color to be displayed
 * 
 * @param r Red status (0 to 255) 
 * @param g Geen status (0 to 255) 
 * @param b Blue status (0 to 255) 
 */
void AnalogColorLed::_set_color(uint8_t r, uint8_t g, uint8_t b) {
  if(_mode == POSITIVE) {
    _current_color[0] = r;
    _current_color[1] = g;
    _current_color[2] = b;
  } else {
    _current_color[0] = 0xFF - r;
    _current_color[1] = 0xFF - g;
    _current_color[2] = 0xFF - b;
  }
}


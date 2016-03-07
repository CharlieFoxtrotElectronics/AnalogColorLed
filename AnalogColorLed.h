/**
 * @file "AnalogColorLed.h"
 * Quick and dirty 24bit RGB LED class/library for digital PWM pins
 *
 * @authot     Jaime Martínez-Figueroa <jmf@charliefoxtrot.cl>
 * @date       Feb 2016
 * @copyright  2016 Charlie Foxtrot Electronics, LGPL
 */

#ifndef AnalogColorLed_h
#define AnalogColorLed_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/**
 * The modes availables for the driver 
 */
enum AnalogColorLedMode_e {
  POSITIVE, ///< Positive mode for common cathode 
  NEGATIVE  ///< Negative mode for common anode
};

/**
 * Basic colors
 */
enum AnalogColorLedColor_e {
  BLACK   = 0x000000,
  RED     = 0xFF0000,
  GREEN   = 0x00FF00,
  YELLOW  = 0xFFFF00,
  BLUE    = 0x0000FF,
  MAGENTA = 0xFF00FF,
  CYAN    = 0x00FFFF,
  WHITE   = 0xFFFFFF
};

/**
 * Quick and dirty 24bit RGB LED class
 */
class AnalogColorLed {
  public:
    /**
     * Constructor method
     * 
     * @param r    Red pin
     * @param g    Green pin
     * @param b    Blue pin
     * @param mode Mode of the LED: POSITIVE for common cathode, NEGATIVE for common anode
     */
    AnalogColorLed(uint8_t r, uint8_t g, uint8_t b, AnalogColorLedMode_e mode=POSITIVE);

    /**
     * Destructor method (does nothing)
     */
    ~AnalogColorLed();

    /**
     * Sets the color to be displayed and updates the output
     * 
     * @param r Red status (0 to 255) 
     * @param g Geen status (0 to 255) 
     * @param b Blue status (0 to 255) 
     */
    void setColor(uint8_t r, uint8_t g, uint8_t b);

    /**
     * Sets the color to be displayed and updates the output
     * 
     * @param color  24bit color code (0x000000 to 0xFFFFFF): 0xFF0000 for red, 0x00FF00 for green and 0x0000FF for blue
     */
    void setColor(uint32_t color);

    /**
     * Turns off all the colors of the LED
     */
    void off();

  private:
    AnalogColorLedMode_e _mode;
    uint8_t _pin[3];
    uint8_t _current_color[3] = {0, 0, 0};

    /**
     * Updates the status of the outputs to match _current_color[]
     */
    void _update();

    /**
     * Sets the color to be displayed
     * 
     * @param r Red status (0 to 255) 
     * @param g Geen status (0 to 255) 
     * @param b Blue status (0 to 255) 
     */
    void _set_color(uint8_t r, uint8_t g, uint8_t b);
};

#endif

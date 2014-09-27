/*--------------------------------------------------------------------
  This file is part of the Adafruit NeoPixel library.

  NeoPixel is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation, either version 3 of
  the License, or (at your option) any later version.

  NeoPixel is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with NeoPixel.  If not, see
  <http://www.gnu.org/licenses/>.
  --------------------------------------------------------------------*/

#ifndef PROC_BASE_CLASS
#define PROC_BASE_CLASS

#include <Adafruit_NeoPixel.h>

#define FLOW_DIR_NORMAL		0
#define FLOW_DIR_REVERSE	1

#define RAINBOW_MAX_STEP	256

class NeoPixel_Pattern {

 public:

  // Constructor: number of LEDs, pin number, LED type
  NeoPixel_Pattern(Adafruit_NeoPixel* strip);
  ~NeoPixel_Pattern();
  virtual uint8_t process(void)=0;
  
  void reset();
  void setPixelColor(uint32_t c);
  void setWait(uint8_t wait);
  //void setCycle(uint8_t cycle);
  void setDir(uint8_t dir);
  void setCycle(uint8_t cycle);
  void setRainbowSpeed(uint16_t rainbowSpeed);
  protected:
   uint32_t Wheel(byte WheelPos);

 protected:
  Adafruit_NeoPixel* strip;
  const uint16_t
    numLEDs;       // Number of RGB LEDs in strip
  uint16_t counter;
  uint32_t time;
  uint32_t  c;
  uint8_t  wait;
  uint8_t  dir;

  uint16_t  cycleCounter;
  uint16_t  cycle;

  uint16_t  mRainbowSpeed;
  
};

#endif // PROC_BASE_CLASS

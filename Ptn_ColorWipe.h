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

#ifndef COLOR_WIPE_H
#define COLOR_WIPE_H

#include <Adafruit_NeoPixel.h>
#include "NeoPixel_Pattern.h"

class Ptn_ColorWipe : public NeoPixel_Pattern{

 public:

  // Constructor: number of LEDs, pin number, LED type
  Ptn_ColorWipe(Adafruit_NeoPixel* strip);
  ~Ptn_ColorWipe();
#if 0
  void reset();
  void setPixelColor(uint32_t c);
  void setWait(uint8_t wait);
  void setDir(uint8_t wait);
#endif
  uint8_t 
    process(void);
#if 0
 private:
  Adafruit_NeoPixel* strip;
  const uint16_t
    numLEDs;       // Number of RGB LEDs in strip
  uint16_t counter;
  uint32_t time;
  uint32_t  c;
  uint8_t  wait;
  uint8_t  dir;
#endif
};

#endif // COLOR_WIPE_H

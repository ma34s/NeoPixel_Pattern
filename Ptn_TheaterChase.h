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

#ifndef THEATER_CHASE
#define THEATER_CHASE

#include <Adafruit_NeoPixel.h>
#include "NeoPixel_Pattern.h"

class Ptn_TheaterChase : public NeoPixel_Pattern{

 public:

  // Constructor: number of LEDs, pin number, LED type
  Ptn_TheaterChase(Adafruit_NeoPixel* strip);
  ~Ptn_TheaterChase();
  uint8_t 
    process(void);

 private:
  uint8_t  cycleCounter;
  uint8_t  cycle;
};

#endif // THEATER_CHASE

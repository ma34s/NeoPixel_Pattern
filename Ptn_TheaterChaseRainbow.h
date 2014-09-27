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
#ifndef  PTN_THEATER_CHASE_RAINBOW_H
#define  PTN_THEATER_CHASE_RAINBOW_H

#include <Adafruit_NeoPixel.h>
#include "NeoPixel_Pattern.h"
#include "Ptn_TheaterChase.h"

class Ptn_TheaterChaseRainbow : public Ptn_TheaterChase{

 public:
  // Constructor: number of LEDs, pin number, LED type
  Ptn_TheaterChaseRainbow(Adafruit_NeoPixel* strip);
  ~Ptn_TheaterChaseRainbow();

  void setCycle(uint8_t cycle);
  void setRainbowSpeed(uint16_t rainbowSpeed);

protected:
    uint32_t getColorCode(int i);

private:
    uint16_t  mRgbCycle;

};

#endif //  PTN_THEATER_CHASE_RAINBOW_H

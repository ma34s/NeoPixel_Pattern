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
#ifndef  RAINBOW_H
#define  RAINBOW_H

#include <Adafruit_NeoPixel.h>
#include "Ptn_FlatRainbow.h"

class Ptn_CycleRainbow : public Ptn_FlatRainbow{

 public:
  // Constructor: number of LEDs, pin number, LED type
  Ptn_CycleRainbow(Adafruit_NeoPixel* strip);
  ~Ptn_CycleRainbow();

  void setCycle(uint8_t cycle);
  void setRainbowSpeed(uint16_t rainbowSpeed);
  uint8_t process(void);
  
protected:
    uint32_t getColorCode(int i);

private:
    uint16_t  mRgbCycle;

};

#endif //  RAINBOW_H

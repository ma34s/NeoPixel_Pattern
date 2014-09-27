#include "Ptn_CycleRainbow.h"

Ptn_CycleRainbow::Ptn_CycleRainbow(Adafruit_NeoPixel* strip) : Ptn_FlatRainbow(strip){
  
  wait = 20;
  mRgbCycle = 1;
  mRainbowSpeed = 2;
  setCycle(mRgbCycle);
}
Ptn_CycleRainbow::~Ptn_CycleRainbow(){
}

void Ptn_CycleRainbow::setRainbowSpeed(uint16_t rainbowSpeed){
  this->mRainbowSpeed = rainbowSpeed;
  setCycle(mRgbCycle);
}
void Ptn_CycleRainbow::setCycle(uint8_t cycle){
	this->mRgbCycle = cycle;
	this->cycle = mRgbCycle*5*(RAINBOW_MAX_STEP/mRainbowSpeed);
}

uint32_t Ptn_CycleRainbow::getColorCode(int i) {
	return Wheel( ( (i * RAINBOW_MAX_STEP / numLEDs) + cycleCounter*mRainbowSpeed) & 255);
}

#if 0
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
#endif

uint8_t Ptn_CycleRainbow::process(void) {
  uint8_t ret;
  uint32_t  now;

  now = millis();
  ret = 0;
 
  if( counter < 1 )
  {
#if 0
    Serial.print("now=");
    Serial.print(now);
    Serial.print(" ,wait=" );
    Serial.println(( now - time ));
#endif
    if( ( now - time ) > wait )
    {
      for (int i=0; i < numLEDs; i++) {
        strip->setPixelColor(i, getColorCode(i) );    //turn every third pixel on
      }
      strip->show();

      counter++;
      time = now;
    }
  }
  else
  {
	if( cycleCounter < cycle )
	{
		cycleCounter++;
		counter = 0;
	}
	else
	{
//		strip->clear();
//		strip->show();
    	ret = 1;
	}
  }
  
  return ret;
}

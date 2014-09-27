#include "Ptn_FlatRainbow.h"

Ptn_FlatRainbow::Ptn_FlatRainbow(Adafruit_NeoPixel* strip) : NeoPixel_Pattern(strip){
  
  mRgbCycle = 1;
  
  mRainbowSpeed = 1;
  cycle = 1*(RAINBOW_MAX_STEP/mRainbowSpeed);
}
Ptn_FlatRainbow::~Ptn_FlatRainbow(){
}

void Ptn_FlatRainbow::setRainbowSpeed(uint16_t rainbowSpeed){
  this->mRainbowSpeed = rainbowSpeed;
  setCycle(mRgbCycle);
}
void Ptn_FlatRainbow::setCycle(uint8_t cycle){
	this->mRgbCycle = cycle;
	this->cycle = mRgbCycle*(RAINBOW_MAX_STEP/mRainbowSpeed);
}



uint32_t Ptn_FlatRainbow::getColorCode(int i) {
	return Wheel( (i+cycleCounter*mRainbowSpeed) % 255);
}
uint8_t Ptn_FlatRainbow::process(void) {
  uint8_t ret;
  uint32_t  now;

  now = millis();
  ret = 0;
 
  if( counter < 1 )
  {
#if 1
    Serial.print("now=");
    Serial.print(now);
    Serial.print(" ,wait=" );
    Serial.println(( now - time ));
#endif
    if( ( now - time ) > wait )
    {
      for (int i=0; i < numLEDs; i++) {
        strip->setPixelColor(i, getColorCode(1) );    //turn every third pixel on
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

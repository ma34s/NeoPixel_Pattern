#include "Ptn_TheaterChaseRainbow.h"

Ptn_TheaterChaseRainbow::Ptn_TheaterChaseRainbow(Adafruit_NeoPixel* strip) : Ptn_TheaterChase(strip){
  
  mRgbCycle = 1;
  
  mRainbowSpeed = 8;
  cycle = 1*(RAINBOW_MAX_STEP/mRainbowSpeed);
}
Ptn_TheaterChaseRainbow::~Ptn_TheaterChaseRainbow(){
}

void Ptn_TheaterChaseRainbow::setRainbowSpeed(uint16_t rainbowSpeed){
  this->mRainbowSpeed = rainbowSpeed;
  setCycle(mRgbCycle);
}
void Ptn_TheaterChaseRainbow::setCycle(uint8_t cycle){
	this->mRgbCycle = cycle;
	this->cycle = mRgbCycle*(RAINBOW_MAX_STEP/mRainbowSpeed);
}



uint32_t Ptn_TheaterChaseRainbow::getColorCode(int i) {
	return Wheel( (i+cycleCounter*mRainbowSpeed) % 255);
}


#include "NeoPixel_Pattern.h"
NeoPixel_Pattern::NeoPixel_Pattern(Adafruit_NeoPixel* strip) : numLEDs(strip->numPixels()){
 // numLEDs = strip->numPixels();
  this->strip = strip;
  counter = 0;
  time = 0;  //
  c    = 0;
  wait  = 50;
  dir	= FLOW_DIR_NORMAL;
}
NeoPixel_Pattern::~NeoPixel_Pattern(){
}

void NeoPixel_Pattern::setPixelColor(uint32_t c){
this->c = c; 
}
void NeoPixel_Pattern::setWait(uint8_t wait){
this->wait = wait;
}
#if 0
void NeoPixel_Pattern::setCycle(uint8_t cycle){
this->cycle = cycle;
}
#endif
void NeoPixel_Pattern::reset(void) {
  counter = 0;
  time = 0;  //
}



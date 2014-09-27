#include "Ptn_ColorWipe.h"
Ptn_ColorWipe::Ptn_ColorWipe(Adafruit_NeoPixel* strip) : NeoPixel_Pattern(strip){
}
Ptn_ColorWipe::~Ptn_ColorWipe(){
}

uint8_t Ptn_ColorWipe::process(void) {
  uint8_t ret;
  uint32_t  now;
  now = millis();
  ret = 0;
  uint16_t target;
  
  if( counter < numLEDs )
  {
#if 0
    Serial.print("now=");
    Serial.print(now);
    Serial.print(" ,wait=" );
    Serial.println(( now - time ));
#endif
    if( ( now - time ) > wait )
    {
      
      if(dir==FLOW_DIR_NORMAL)
  	  {
  	  	target = counter;
  	  }
      else
      {
		target = numLEDs -1 - counter;
      }
      Serial.println(target);
      strip->setPixelColor(target, c);
      strip->show();

      counter++;
      time = now;
    }
  }
  else
  {
    ret = 1;
  }
  
  return ret;
}


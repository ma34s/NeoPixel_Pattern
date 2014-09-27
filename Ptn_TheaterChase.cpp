#include "Ptn_TheaterChase.h"
Ptn_TheaterChase::Ptn_TheaterChase(Adafruit_NeoPixel* strip) : NeoPixel_Pattern(strip){
  cycle = 10;
  wait  = 80;
}
Ptn_TheaterChase::~Ptn_TheaterChase(){
}

uint32_t Ptn_TheaterChase::getColorCode(int i) {
	return c;
}


uint8_t Ptn_TheaterChase::process(void) {
  uint8_t ret;
  uint32_t  now;

  const uint8_t index[2][3] = 
  {
	{0,1,2,},
	{2,1,0,},
  };
  
  now = millis();
  ret = 0;
 
  if( counter < 3 )
  {
#if 0
    Serial.print("now=");
    Serial.print(now);
    Serial.print(" ,wait=" );
    Serial.println(( now - time ));
#endif
    if( ( now - time ) > wait )
    {
      for (int i=0; i < numLEDs; i=i+3) {
        strip->setPixelColor(i+index[dir][counter], getColorCode(i) );    //turn every third pixel on
      }
      strip->show();

      for (int i=0; i < numLEDs; i=i+3) {
        strip->setPixelColor(i+index[dir][counter], 0);    //turn every third pixel off
      }
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
		strip->clear();
		strip->show();
    	ret = 1;
	}
  }
  
  return ret;
}


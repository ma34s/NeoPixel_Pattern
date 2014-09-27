#include <Adafruit_NeoPixel.h>
#include <Ptn_ColorWipe.h>
#include <Ptn_TheaterChase.h>
#include <Ptn_TheaterChaseRainbow.h>
#include <Ptn_FlatRainbow.h>
#include <Ptn_CycleRainbow.h>

#define PIN 6
#define NUMPIXELS      6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Ptn_ColorWipe wipe = Ptn_ColorWipe(&strip);
Ptn_ColorWipe wipeOut = Ptn_ColorWipe(&strip);
Ptn_TheaterChase tc = Ptn_TheaterChase(&strip);
Ptn_TheaterChaseRainbow tcr = Ptn_TheaterChaseRainbow(&strip);
Ptn_FlatRainbow fr = Ptn_FlatRainbow(&strip);
Ptn_CycleRainbow cr = Ptn_CycleRainbow(&strip);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.


uint8_t run_colorWipe(struct tg_color_wipe* ctl);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  //wipe(&strip);
  
 // initialize serial:
  Serial.begin(9600); 
  
  
//  reset_colorWipe_s( (struct tg_color_wipe *)&fttPtn_ColorWipe ,strip.Color(  0,   0, 127), 30);
  wipe.setPixelColor(strip.Color(  0,   0, 40));
  wipeOut.setPixelColor(strip.Color(  0,   0, 0));
  //wipeOut.setDir(WIPE_DIR_REVERSE);
  tc.setPixelColor(strip.Color(  0,   20, 20));
  tc.setDir(FLOW_DIR_REVERSE);
}

uint8_t state=0;

void loop() {
   //static struct tg_color_wipe fttPtn_ColorWipe;
  
#if 0
#else
  uint8_t ret;
 
  switch(state)
  {
#if 0
    case 0:
    ret = wipe.process();
    if( ret == 1 )
    { 
      wipe.reset();
      state++;
    }
    break;
  case 1: 
    delay(500);
    state++;
    break;
  case 2:
    ret = wipeOut.process();
    if( ret == 1 )
    { 
      wipeOut.reset();
      state++;
    }
    break;
  case 3:
    ret = tc.process();
    if( ret == 1 )
    { 
      tc.reset();
      state++;
    }
    break;
  case 4:
    ret = tcr.process();
    if( ret == 1 )
    { 
      tcr.reset();
      state++;
    }
    break; 

  case 5:
    ret = fr.process();
    if( ret == 1 )
    { 
      fr.reset();
      state++;
    }
    break;
#endif
  case 6:
    ret = cr.process();
    if( ret == 1 )
    { 
      cr.reset();
      state++;
    }
    break;      
  default:
    delay(500);
    state = 6;
    break;
  }

  
#endif
}


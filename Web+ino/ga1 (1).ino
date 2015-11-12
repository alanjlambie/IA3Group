/*
 * This is a minimal example, see extra-examples.cpp for a version
 * with more explantory documentation, example routines, how to
 * hook up your pixels and all of the pixel types that are supported.
 *
 */

#include "application.h"
#include "neopixel/neopixel.h"

SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D0
#define PIXEL_COUNT 10
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup()
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
void loop()
{
  butterfly1(200);
  butterfly2(200);
  butterfly3(20);
  butterfly3(20);
  butterfly3(20);
  butterfly3(20);
  butterfly3(20);
}

void butterfly1(uint8_t wait) {
  uint16_t i, j;
  strip.setBrightness(128);
  strip.setPixelColor(0, 0, 0, 255);
  strip.setPixelColor(1, 0, 255, 0);
  strip.setPixelColor(2, 255, 0, 0);
  strip.setPixelColor(3, 0, 255, 255);
  strip.setPixelColor(4, 255, 255, 0);
  strip.setPixelColor(5, 255, 0, 255);
  strip.show();
  delay(wait);
}

void butterfly2(uint8_t wait) {
  uint16_t i, j;
  strip.setBrightness(128);
  strip.setPixelColor(0, 255, 0, 255);
  strip.setPixelColor(1, 255, 255, 0);
  strip.setPixelColor(2, 0, 255, 255);
  strip.setPixelColor(3, 255, 0, 0);
  strip.setPixelColor(4, 0, 255, 0);
  strip.setPixelColor(5, 0, 0, 255);
  strip.show();
  delay(wait);
}

void butterfly3(uint8_t wait) {
  uint16_t i, j;
  strip.setBrightness(128);
  for(j=0; j<256; j++) {
      for(i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel((i+j) & 255));
      }
      strip.show();
      delay(wait);
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

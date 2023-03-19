/*****************************/
 // HAZI TECH
 // Programmed by Hasitha Jayasundara
 // Visit my YouTube Channel - http://www.youtube.com/c/HAZITECH?sub_confirmation=1

 // RGB Screen Recorder v1.0
 // for more info visit 
 // https://www.rgbscreenrecorder.com
/*****************************/

#include "FastLED.h" // add fastled library
#include "SdFat.h"   // add sdfat library

#define NUM_LEDS 204  // total leds  
#define DATA_PIN 7   // led data pin
CRGB leds[NUM_LEDS];

//SD chip select pin
const uint8_t chipSelect = SS; //chipSelect = 10;

SdFat sd;
SdFile file;

long file_size;

void setup() 
{ 
// Uncomment/edit one of the following lines for your leds arrangement.
       FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
      //FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  
}

void loop() { 
  
   sd.begin(chipSelect, SPI_FULL_SPEED);
  
/*******************************************/
  // effect file - D11.dat
  // file size 176868 bytes
/*******************************************/
  
   file.open("D11.led", O_READ);           //enter the effect file name here
   file_size = 1596928;                    //enter the file size in bytes here
   for(int i = 0 ;i<(file_size/(NUM_LEDS*3));i++)
  {   
   file.read((uint8_t*)leds,NUM_LEDS*3);                        
   FastLED.show();
   delay(20); // delay between each frame 
  }

  file.close();

}

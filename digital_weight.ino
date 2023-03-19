#include "HX711.h"
#include <Arduino.h>
#include <TM1637TinyDisplay.h>

#define DOUT_HX  4
#define CLK_HX   5
#define CLK_TM   2
#define DIO_TM   3

HX711 scale;
TM1637TinyDisplay display(CLK_TM, DIO_TM);

float weight;
float weight_gms;

const uint8_t SEG_CALC[] = {
  SEG_F | SEG_E | SEG_D,                           // L
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,   // A
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,          // D
};

/*boolean fluctuation(int current_value, int prev_value){
  if ((current_value - prev_value) >= 5)
    return true;
  else if ((prev_value - current_value) >= 5)
    return true;
  else
    return false;
}*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  scale.begin(DOUT_HX, CLK_HX);
  scale.set_scale(-2193520);  //Calibration Factor obtained from first sketch
  scale.tare();
  display.setBrightness(7);

  //display.setSegments(SEG_CALC);
  delay(5000);
        scale.tare();
}

void loop() {
  // put your main code here, to run repeatedly:
  //old_value = weight;

  weight = scale.get_units();
  /*Serial.print("Old: ");
  Serial.print(old_value, 3);
  Serial.print("  New: ");
  Serial.println(weight, 3);
  bool change_value = fluctuation(weight, old_value);
  
  if (change_value){
    weight_gms = weight * 1000;
    weight_kgs = weight;
  }
  else{
    weight_gms = old_value * 1000;
    weight_kgs = old_value;
  }*/
  weight_gms = weight * 1000 * -10;
  //if (weight_gms <= 6)
  //  display.setSegments(SEG_CALC);
  if (weight_gms <= 10000)
  {
    display.showNumberDec(weight_gms, false);
    Serial.println(weight_gms);
  }
  else
   display.setSegments(SEG_CALC);
   
}

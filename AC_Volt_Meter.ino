#include <Arduino.h>
#include <TM1637TinyDisplay.h>

#define CLK_TM   4
#define DIO_TM   5

TM1637TinyDisplay display(CLK_TM, DIO_TM);

int relay = 13;
int high = 11;
int low = 10;



void setup(void) {
  ///Serial.begin(9600);
    display.setBrightness(3);
  pinMode(relay, OUTPUT);
  pinMode(high, OUTPUT);
  pinMode(low, OUTPUT);
  analogReference(INTERNAL);  // set ADC positive reference voltage to 1.1V (internal)
  delay(5000);
}


// get maximum reading value
uint16_t get_max() {
  uint16_t max_v = 0;
  for(uint8_t i = 0; i < 100; i++) {
    uint16_t r = analogRead(A3);  // read from analog channel 3 (A3)
    if(max_v < r) max_v = r;
    delayMicroseconds(200);
  }
  return max_v;
}

// main loop
void loop() {

  char buf[10];
  // get amplitude (maximum - or peak value)
  uint32_t v = get_max();
  // get actual voltage (ADC voltage reference = 1.1V)
  v = v * 1065/1023;
  // calculate the RMS value ( = peak/√2 )
  v /= sqrt(2);

  sprintf(buf, "%03u Volts", v);
  display.showNumberDec(v, false);
  //Serial.println(v);
delay(300);

 if ( (v >= 0)  &&  (v < 190) )
    {
      //Serial.print("Low");
      digitalWrite(relay, LOW);
      digitalWrite(low, HIGH);
      digitalWrite(high, LOW);
    }
    // Case 2 Normal Rated Voltage
    if ( (v >= 190)  &&  (v <= 255) )
    {
      //Serial.print("Normal");
      digitalWrite(relay, HIGH);
      digitalWrite(low, HIGH);
      digitalWrite(high, HIGH);
    }
    // Case 3 Over Voltage
    if ( v > 260 )
    {
      //Serial.print("High");
      digitalWrite(relay, LOW);
      digitalWrite(low, HIGH);
      digitalWrite(high, LOW);
    }
}

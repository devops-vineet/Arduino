#include "arduino_secrets.h"
#include "thingProperties.h"


float R1 = 30000.0;
float R2 = 7500.0; 
float ref_voltage = 3.3;
float Cal_Fact = 80.5;

#define OVER_VOL D5
#define UNDER_VOL D6
// #define RELAY_PIN D2
#define VOLT_PIN A0


void setup() {
  Serial.begin(9600);
  pinMode(OVER_VOL, OUTPUT);
  pinMode(UNDER_VOL, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);  
  pinMode(VOLT_PIN, INPUT);
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
 voltage = (analogRead(VOLT_PIN));
 voltage = (voltage * ref_voltage) / 1024.0;
 voltage = voltage / (R2/(R1+R2)) * Cal_Fact;

// Case 1 Under Voltage
if( (voltage > 0)  &&  (voltage < 175) ){
  led = false;
  under_volt = true;
  status = false;
digitalWrite(LED_BUILTIN, HIGH);
digitalWrite(UNDER_VOL, HIGH);
digitalWrite(OVER_VOL, LOW);  
}
 
// Case 2 Normal Voltage
if( (voltage >= 190)  &&  (voltage <= 250) ){
  led = false;
  under_volt = false;
  status = true;
digitalWrite(LED_BUILTIN, LOW);
digitalWrite(UNDER_VOL, LOW);
digitalWrite(OVER_VOL, LOW);
}
 
// Case 3 Over Voltage
if(voltage > 265){
  led = true;
  under_volt = false;  
  status = false;
digitalWrite(LED_BUILTIN, HIGH);
digitalWrite(UNDER_VOL, LOW);
digitalWrite(OVER_VOL, HIGH);
}
 
}


/*
  Since LedSwitch is READ_WRITE variable, onLedSwitchChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedSwitchChange()  {
 if(led_switch){
   digitalWrite(LED_BUILTIN, LOW);
 }
   else{
    digitalWrite(LED_BUILTIN, HIGH);
   }
 }

void onVoltageChange()  {

}

void onLedChange()  {
 
}

void onStatusChange()  {
  
}
void onUnderVoltChange()  {
 
}

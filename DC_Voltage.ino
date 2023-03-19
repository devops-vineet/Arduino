#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Define analog input
#define ANALOG_IN_PIN1 A1
#define ANALOG_IN_PIN2 A2
int bat1 = 8;
int bat2 = 9;
// Floats for ADC voltage & Input voltage
float adc_voltage1 = 0.0;
float in_voltage1 = 0.0;

float adc_voltage2 = 0.0;
float in_voltage2 = 0.0;
 
// Floats for resistor values in divider (in ohms)
float R1 = 9960.0;
float R2 = 4740.0; 
 
// Float for Reference Voltage
float ref_voltage = 5.0;
 
// Integer for ADC value
int adc_value1 = 0;
int adc_value2 = 0;

 
void setup()
{
   // Setup Serial Monitor
   lcd.init();
   lcd.backlight();
   pinMode(bat1, OUTPUT);
   pinMode(bat2, OUTPUT);
   digitalWrite(bat1, HIGH);
   digitalWrite(bat2, HIGH);
   Serial.begin(9600);
   Serial.println("DC Voltage Test");
  lcd.setCursor(0, 0);
  lcd.print("BAT1:");
  lcd.setCursor(0, 1);
  lcd.print("BAT2:");
  lcd.setCursor(10, 0);
  lcd.print("V");
  lcd.setCursor(10, 1);
  lcd.print("V");
}
 
void loop(){
   // Read the Analog Input
   adc_value1 = analogRead(ANALOG_IN_PIN1);
   adc_value2 = analogRead(ANALOG_IN_PIN2); 
   // Determine voltage at ADC input
   adc_voltage1  = (adc_value1 * ref_voltage) / 1024.0; 
   adc_voltage2  = (adc_value2 * ref_voltage) / 1024.0; 
   // Calculate voltage at divider input
   in_voltage1 = adc_voltage1 / (R2/(R1+R2)) ; 
   in_voltage2 = adc_voltage2 / (R2/(R1+R2)) ;   
   // Print results to Serial Monitor to 2 decimal places
  Serial.print("Input Voltage = ");
  Serial.println(in_voltage1, 2);
  lcd.setCursor(5, 0);
  lcd.print(in_voltage1);
  lcd.setCursor(5, 1);
  lcd.print(in_voltage2);

  if (in_voltage1 > 0.90 )
    {
      digitalWrite(bat1, LOW);
      digitalWrite(bat2, HIGH);
      lcd.setCursor(12, 0);
      lcd.print("ON ");
      lcd.setCursor(12, 1);
      lcd.print("OFF");
    }
    else if (in_voltage1 < 0.89 )
    {
      digitalWrite(bat1, HIGH);
      digitalWrite(bat2, LOW);
      lcd.setCursor(12, 0);
      lcd.print("OFF"); 
      lcd.setCursor(12, 1);
      lcd.print("ON "); 
    }
  
  // Short delay
  delay(500);
}

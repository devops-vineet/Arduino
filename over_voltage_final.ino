#include <Filters.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
float testFrequency = 50;  // test signal frequency (Hz)
int Sensor = A2; //Sensor analog input, here it's A0
int relay = 11;  //Define output pin for relay
int underv = 13;  //Define output pin for relay
int overv = 12;  //Define output pin for relay
float intercept = 0.7; // To be adjusted based on calibration testing
float slope = 0.04; // To be adjusted based on calibration testing
float current_Volts; // Voltage
unsigned long printPeriod = 600; //Refresh rate
unsigned long previousMillis = 0;


void setup()
{
  digitalWrite(relay, HIGH);
  digitalWrite(overv, LOW);
  digitalWrite(underv, LOW);
  lcd.init();
  lcd.backlight();
  pinMode(relay, OUTPUT);
  pinMode(underv, OUTPUT);
  pinMode(overv, OUTPUT);
  lcd.print("Voltage Monitor!");
  lcd.setCursor(0, 1);
  lcd.print("     System     ");
  delay(5000);
  lcd.clear();
  lcd.print("AC Mains:");
  lcd.setCursor(0, 1);
  lcd.print("Low:190 High:265");
  lcd.setCursor(9, 0);
  lcd.print("L      ");
  delay(600);
  lcd.setCursor(9, 0);
  lcd.print("Lo     ");
  delay(600);
  lcd.setCursor(9, 0);
  lcd.print("Loa    ");
  delay(600);
  lcd.setCursor(9, 0);
  lcd.print("Load   ");
  delay(600);
  lcd.setCursor(9, 0);
  lcd.print("Loadi  ");
  delay(600);
  lcd.setCursor(9, 0);
  lcd.print("Loadin ");
  delay(600);
  lcd.setCursor(9, 0);
  lcd.print("Loading");
  delay(600);
  lcd.clear();
  lcd.print("AC Mains:");
}
void loop()
{
  RunningStatistics inputStats;                // Easy life lines, actual calculation of the RMS requires a load of coding
  while ( true )
  {
    Sensor = analogRead(A2);  // Read the analog in value:
    inputStats.input(Sensor);  // Log to stats function
    if ((unsigned long)(millis() - previousMillis) >= printPeriod)
    {
      previousMillis = millis();   // Update time every second
      current_Volts = intercept + slope * inputStats.sigma(); // Calibartions for offset and amplitude
      current_Volts = current_Volts * (65.65);             // Further calibrations for the amplitude
      lcd.setCursor(9, 0);
      lcd.print(current_Volts);

      lcd.print("V");
    }

    // Case 1 Under Voltage
    if ( (current_Volts > 0)  &&  (current_Volts < 175) )
    {
      lcd.setCursor(0, 1);
      lcd.print("V:Low   Load:OFF");
      digitalWrite(relay, HIGH);
      digitalWrite(underv, LOW);
      digitalWrite(overv, HIGH);
    }
    // Case 2 Normal Rated Voltage
    if ( (current_Volts >= 190)  &&  (current_Volts <= 250) )
    {
      lcd.setCursor(0, 1);
      lcd.print("V:Normal Load:ON");
      digitalWrite(relay, LOW);
      digitalWrite(underv, LOW);
      digitalWrite(overv, LOW);
    }
    // Case 3 Over Voltage
    if ( current_Volts > 265 )
    {
      lcd.setCursor(0, 1);
      lcd.print("V:High  Load:OFF");
      digitalWrite(relay, HIGH);
      digitalWrite(underv, HIGH);
      digitalWrite(overv, LOW);
    }
  }
}

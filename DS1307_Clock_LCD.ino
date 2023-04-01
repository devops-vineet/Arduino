#include "Arduino.h"
#include "uRTCLib.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// uRTCLib rtc;
uRTCLib rtc(0x68);

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

unsigned long previousMillis = 0;   // initialize the previous time to 0
const long interval = 1000;         // declare the delay interval

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();  
  lcd.clear();
  delay(3000); // wait for console opening

  URTCLIB_WIRE.begin();

  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // for example to set January 13 2022 at 12:56 you would call:
   //rtc.set(0, 28, 14, 6, 31, 3, 23);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)
}

void loop() {

  unsigned long currentMillis = millis();

if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
  rtc.refresh();

  lcd.setCursor(0, 0);
  lcd.print("Time ");
  lcd.setCursor(0, 1);
  lcd.print(rtc.day());
  lcd.setCursor(2, 1);
  lcd.print('/');
  lcd.setCursor(3, 1);
  lcd.print(rtc.month());
  lcd.setCursor(5, 1);
  lcd.print('/');
  lcd.setCursor(6, 1);
  lcd.print(rtc.year());

  Serial.print(" (");
 // lcd.setCursor(0, 1);
 // lcd.print(daysOfTheWeek[rtc.dayOfWeek()-1]);
  Serial.print(") ");
  lcd.setCursor(5, 0);
  lcd.print(rtc.hour());
  lcd.setCursor(7, 0);
  lcd.print(':');
  lcd.setCursor(8, 0);
  lcd.print(rtc.minute());
  lcd.setCursor(10, 0);
  lcd.print(':');
  lcd.setCursor(11, 0);
  lcd.print(rtc.second());
  
  //delay(1000);
}
}
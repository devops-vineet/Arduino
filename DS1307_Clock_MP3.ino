#include "Arduino.h"
#include "uRTCLib.h"
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// uRTCLib rtc;
uRTCLib rtc(0x68);

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

unsigned long previousMillis = 0;   // initialize the previous time to 0
const long interval = 1000;         // declare the delay interval

//SoftwareSerial mySerial(10, 11); // RX, TX
//DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(9600);
  //mySerial.begin(9600);
  delay(3000); // wait for console opening

/*if (!myDFPlayer.begin(mySerial)) {  // Use softwareSerial to communicate with mp3 module
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code will stuck here when DFPlayer is not connected.
    }
  }*/

  //myDFPlayer.volume(100);  // Set volume to 100
  
  //myDFPlayer.play(2); // Play track 1
 // delay(5000);
  
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

//Night 12:00 AM
if (rtc.hour() == 00 && rtc.minute() == 0){
  Serial.println("Hello 12:00 AM ");
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 01:00 AM
if (rtc.hour() == 1 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 02:00 AM
if (rtc.hour() == 2 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 03:00 AM
if (rtc.hour() == 3 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 4:00 AM
if (rtc.hour() == 4 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 05:00 AM
if (rtc.hour() == 5 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 6:00 AM
if (rtc.hour() == 6 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 7:00 AM
if (rtc.hour() == 7 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 8:00 AM
if (rtc.hour() == 8 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 9:00 AM
if (rtc.hour() == 9 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 10:00 AM
if (rtc.hour() == 10 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 11:00 AM
if (rtc.hour() == 11 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 12:00 PM
if (rtc.hour() == 12 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 13:00 PM
if (rtc.hour() == 13 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 14:00 PM
if (rtc.hour() == 14 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 15:00 PM
if (rtc.hour() == 15 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 16:00 PM
if (rtc.hour() == 16 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 17:00 PM
if (rtc.hour() == 17 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 18:00 PM
if (rtc.hour() == 18 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 19:00 PM
if (rtc.hour() == 19 && rtc.minute() == 0){
 //myDFPlayer.play(1); // Play track 1
 //delay(3000);   
 //myDFPlayer.play(3);
 //delay(15000);
}
//Night 20:00 PM
if (rtc.hour() == 20 && rtc.minute() == 0){
// myDFPlayer.play(1); // Play track 1
// delay(3000);   
// myDFPlayer.play(3);
// delay(15000);
}
//Night 21:00 PM
if (rtc.hour() == 21 && rtc.minute() == 0){
// myDFPlayer.play(1); // Play track 1
// delay(3000);   
// myDFPlayer.play(3);
// delay(15000);
}
//Night 22:00 PM
if (rtc.hour() == 22 && rtc.minute() == 0){
// myDFPlayer.play(1); // Play track 1
// delay(3000);   
// myDFPlayer.play(3);
// delay(15000);
}
//Night 23:00 PM
if (rtc.hour() == 23 && rtc.minute() == 0){
// myDFPlayer.play(1); // Play track 1
// delay(3000);   
// myDFPlayer.play(3);
// delay(15000);
}

  Serial.print("Current Date & Time: ");
  Serial.print(rtc.day());
  Serial.print('/');
  Serial.print(rtc.month());
  Serial.print('/');
  Serial.print(rtc.year());

  Serial.print(" (");
  Serial.print(daysOfTheWeek[rtc.dayOfWeek()-1]);
  Serial.print(") ");
  Serial.print(rtc.hour());
  Serial.print(':');
  Serial.print(rtc.minute());
  Serial.print(':');
  Serial.println(rtc.second());
}
}
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

const int ledPin = 8;
const int speakerPin = 11;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  rtc.begin();
}

void loop() {
  DateTime now = rtc.now();
  int hour = now.hour();
  int minute = now.minute();

  if (hour == 8 && minute == 0) {
    digitalWrite(ledPin, HIGH);
    tone(speakerPin, 1000, 1000);
    delay(2000);
    digitalWrite(ledPin, LOW);
    noTone(speakerPin);
  }

  if (hour == 12 && minute == 0) {
    digitalWrite(ledPin, HIGH);
    tone(speakerPin, 1000, 1000);
    delay(2000);
    digitalWrite(ledPin, LOW);
    noTone(speakerPin);
  }

  if (hour == 18 && minute == 0) {
    digitalWrite(ledPin, HIGH);
    tone(speakerPin, 1000, 1000);
    delay(2000);
    digitalWrite(ledPin, LOW);
    noTone(speakerPin);
  }
}

#include <Wire.h>
#include <RtcDS3231.h>
#include <SoftwareSerial.h>

// Define the pins for the speaker or buzzer and the RTC module
const int speakerPin = 8;
const int rtcSda = 20;
const int rtcScl = 21;

// Create an instance of the RTC module
RtcDS3231<TwoWire> rtc(Wire);

// Set up a software serial connection to output debugging messages
SoftwareSerial serial(10, 11); // RX, TX

void setup() {
  // Initialize the speaker or buzzer pin as an output
  pinMode(speakerPin, OUTPUT);

  // Start the software serial connection
  serial.begin(9600);

  // Initialize the RTC module
  Wire.begin(rtcSda, rtcScl);
  rtc.Begin();

  // Set the time on the RTC module
  rtc.SetDateTime(__DATE__, __TIME__);
}

void loop() {
  // Get the current time from the RTC module
  RtcDateTime now = rtc.GetDateTime();

  // Check if the current time is at the top of the hour
  if (now.Minute() == 0 && now.Second() == 0) {
    // Convert the current hour to 12-hour format
    int hour = now.Hour();
    if (hour > 12) {
      hour -= 12;
    }

    // Play the announcement for the current hour
    playAnnouncement(hour);

    // Wait a few seconds to prevent multiple announcements
    delay(5000);
  }
}

void playAnnouncement(int hour) {
  // Convert the hour to a string
  String hourString;
  if (hour == 0) {
    hourString = "12";
  } else {
    hourString = String(hour);
  }

  // Build the announcement string
  String announcement = "The time is now " + hourString + " o'clock.";

  // Print the announcement to the serial console
  serial.println(announcement);

  // Play the announcement using the speaker or buzzer
  for (int i = 0; i < announcement.length(); i++) {
    char c = announcement.charAt(i);
    if (c == ' ') {
      delay(250);
    } else {
      tone(speakerPin, 1000, 250);
    }
  }

  // Pause for a moment after the announcement
  delay(1000);
}

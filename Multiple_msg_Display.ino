#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the analog input pins for the voltage and current sensors
int voltagePin = A0;
int currentPin = A1;

// Define the digital input pin for the switch
int switchPin = 8;

// Set the time interval between readings in milliseconds
unsigned long interval = 5000;

// Set the initial reading index to 0
int readingIndex = 0;

// Set the time when the current reading was taken
unsigned long readingTime = 0;

void setup() {
  // Set up the LCD display
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  // Print the column header for the readings
  lcd.print("Voltage: ");
}

void loop() {
  // Get the current time in milliseconds
  unsigned long currentTime = millis();

  // Check if it's time to take the next reading
  if (currentTime - readingTime >= interval) {
    // Clear the LCD display
    lcd.clear();

    // Read the voltage and current values
    float voltage = analogRead(voltagePin) * 0.0048828125;
    float current = analogRead(currentPin) * 0.0048828125;

    // Print the reading to the LCD display based on the current reading index
    switch (readingIndex) {
      case 0:
        // Print the voltage reading
        lcd.setCursor(0, 0);
        lcd.print("Voltage: ");
        lcd.print(voltage);
        lcd.print("V");
        break;
      case 1:
        // Print the current reading
        lcd.setCursor(0, 0);
        lcd.print("Current: ");
        lcd.print(current);
        lcd.print("A");
        break;
      case 2:
        // Print the current time
        lcd.setCursor(0, 0);
        lcd.print("Time: ");
        lcd.print(currentTime / 1000);
        lcd.print("s");
        break;
      case 3:
        // Print the switch status
        lcd.setCursor(0, 0);
        lcd.print("Switch: ");
        lcd.print(digitalRead(switchPin));
        break;
    }

    // Increment the reading index
    readingIndex++;

    // Wrap around to the beginning if we've printed all the readings
    if (readingIndex >= 4) {
      readingIndex = 0;
    }

    // Set the time when the reading was taken
    readingTime = currentTime;
  }
}

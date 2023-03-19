#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the pins for the push buttons
int button_up = 6;
int button_down = 7;
int button_select = 8;
int tonePin = 2;

// Define the pins for the relay module
int cola_relay_pin = 9;
int pepsi_relay_pin = 10;
int dew_relay_pin = 11;
int maza_relay_pin = 12;
int Thumps_Up_relay_pin = 13;

// Define the variables for the menu system
int selected_menu_item = 0;
int number_of_menu_items = 5;

// Define the variables for the pump control
int pump_duration = 5000; // in milliseconds
int pump_delay = 1000; // in milliseconds

void setup() {
  // Set up the LCD display
  lcd.init();
  lcd.backlight();
  //lcd.setCursor(0, 0);
  //lcd.print("Drink Dispenser");

  // Set up the push buttons
  pinMode(button_up, INPUT_PULLUP);
  pinMode(button_down, INPUT_PULLUP);
  pinMode(button_select, INPUT_PULLUP);
  // Set up the relay modules
  pinMode(cola_relay_pin, OUTPUT);
  digitalWrite(cola_relay_pin, HIGH);
  pinMode(pepsi_relay_pin, OUTPUT);
  digitalWrite(pepsi_relay_pin, HIGH);
  pinMode(dew_relay_pin, OUTPUT);
  digitalWrite(dew_relay_pin, HIGH);
  pinMode(maza_relay_pin, OUTPUT);
  digitalWrite(maza_relay_pin, HIGH);
  pinMode(Thumps_Up_relay_pin, OUTPUT);
  digitalWrite(Thumps_Up_relay_pin, HIGH);
  pinMode(tonePin, OUTPUT);
}

void loop() {

  switch(selected_menu_item) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print(">> Cola-Cola     ");
      lcd.setCursor(0, 1);
      lcd.print("   Pepsi         ");
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("   Cola-Cola         ");
      lcd.setCursor(0, 1);
      lcd.print(">> Pepsi          ");
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print(">> Dew           ");
      lcd.setCursor(0, 1);
      lcd.print("   Maaza          ");
      break;
    case 3:
      lcd.setCursor(0, 0);
      lcd.print("   Dew         ");
      lcd.setCursor(0, 1);
      lcd.print(">> Maaza        ");
      break;
    case 4:
      lcd.setCursor(0, 0);
      lcd.print(">> Thumps UP     ");
      lcd.setCursor(0, 1);
      lcd.print("   Cola-Cola     ");
      break;
  }

  // Check for button presses
  if(digitalRead(button_up) == LOW) {
    tone(tonePin, 1000, 100);
    //delay(100);
    selected_menu_item--;
    if(selected_menu_item < 0) {
      selected_menu_item = number_of_menu_items - 1;
    }
  }
  if(digitalRead(button_down) == LOW) {
    tone(tonePin, 1000, 100);
    //delay(100);
    selected_menu_item++;
    if(selected_menu_item >= number_of_menu_items) {
      selected_menu_item = 0;
    }
  }
  if(digitalRead(button_select) == LOW) {
    // Dispense the selected drink
    tone(tonePin, 1000, 100);
    //delay(100);
    switch(selected_menu_item) {
      case 0:
        dispense_cola();
        break;
      case 1:
        dispense_pepsi();
        break;
      case 2:
        dispense_dew();
        break;
      case 3:
        dispense_maza();
        break;
      case 4:
        dispense_thumps();
        break;
    }
  }

  // Wait for a short delay to prevent bouncing
  delay(100);
}

void dispense_cola() {
  // Turn on the pump
  digitalWrite(cola_relay_pin, LOW);
  msg();
  delay(pump_duration);
  // Turn off the pump
  digitalWrite(cola_relay_pin, HIGH);
}

void dispense_pepsi() {
  // Turn on the pump
  digitalWrite(pepsi_relay_pin, LOW);
  msg();
  delay(pump_duration);
  // Turn off the pump
  digitalWrite(pepsi_relay_pin, HIGH);
}

void dispense_dew() {
  // Turn on the pump
  digitalWrite(dew_relay_pin, LOW);
  msg();
  delay(pump_duration);
  // Turn off the pump
  digitalWrite(dew_relay_pin, HIGH);
}

void dispense_maza() {
  // Turn on the pump
  digitalWrite(maza_relay_pin, LOW);
  msg();
  delay(pump_duration);
  // Turn off the pump
  digitalWrite(maza_relay_pin, HIGH);
}

void dispense_thumps() {
  // Turn on the pump
  digitalWrite(Thumps_Up_relay_pin, LOW);
  msg();
  delay(pump_duration);
  // Turn off the pump
  digitalWrite(Thumps_Up_relay_pin, HIGH);
}

void msg()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Filling...");
  lcd.setCursor(0,1);
  lcd.print("Enjoy Your Drink");
}

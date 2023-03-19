#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int num1= "";
int num2= "";
float num3,total,ed,ec;
int fixed;
int unit;

void setup() {
    Serial.begin(9600);//to display value on serial monitor
    lcd.init();
    lcd.backlight();
    lcd.print("Know Your e-Bill");
    lcd.setCursor(0,1);
    lcd.print("Er. Vineet Kumar");
    Serial.println("---------\n");
    delay(500);
}

void prints(){
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("U:");
      lcd.setCursor(2,0);
      lcd.print(unit);

      lcd.setCursor(7,0);
      lcd.print("ED:");
      lcd.setCursor(10,0);
      lcd.print(ed);
      
      lcd.setCursor(0,1);
      lcd.print("EC:");
      lcd.setCursor(3,1);
      lcd.print(ec);

      lcd.setCursor(10,1);
      lcd.print("F:");
      lcd.setCursor(12,1);
      lcd.print(fixed);
      
      delay(10000);
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Pay Amt. :");
      lcd.setCursor(10,0);
      lcd.print(total);

      total = (total - (total*0.01));
      lcd.setCursor(0,1);
      lcd.print("By Due Dt:");
      lcd.setCursor(10,1);
      lcd.print(total);
}
void loop() {
  //input first number
  Serial.print("Enter Current Reading: ");
  while(Serial.available()==0)
  {
    //wait for input
    }
   num1= Serial.readString().toInt();
   Serial.println(num1);
   
// input 2nd number
    Serial.print("Enter Previous Reading: ");
   while(Serial.available()==0)
   {
    //wait for input
   }
   num2= Serial.readString().toInt();
   Serial.println(num2);
   // input 3rd number
   Serial.print("Enter Arrear Amount: ");
   while(Serial.available()==0)
   {
    //wait for input
   }
   num3= Serial.parseFloat();
   Serial.println(num3);
   
   unit = (num1 - num2);

if (unit<=100)
{
  fixed = 50;
}
else
{
  fixed = 90;
}

   if (unit<=100) //0 to 100 unit rate 3.5
   {

    total = (unit*3) + fixed;
    ed = (total*0.05);
    total = total + ed + num3;
    ec = (unit*3);
   }
   else if ( (unit>=101)  &&  (unit<=150) )
   {
    total = (100*3.35) + ((unit-100)*3.85)+fixed;
    ed = (total*0.05);
    total = total + ed + num3;
    ec = (100*3.35) + ((unit-100)*3.85);

   }
   else
   {
    total = (100*3.35) + (50*3.85) + ((unit-150)*5)+fixed;
    ed = (total*0.05);
    total = total + ed + num3;
    ec = (100*3.35) + (50*3.85) + ((unit-150)*5);
   }
prints();      
}

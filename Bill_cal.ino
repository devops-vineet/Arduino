#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int num1= "";
int num2= "";
float num3;
#define menu 7
int fixed;
float total;
float ed;
void setup() {
Serial.begin(9600);//to display value on serial monitor
pinMode(menu, INPUT);
  lcd.init();
  lcd.backlight();
lcd.print("Electricity Bill");
lcd.setCursor(0,1);
lcd.print("UPPCL-DVVNL KNP.");
Serial.println("---------\n");
delay(500);
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
   }
   num2= Serial.readString().toInt();
   Serial.println(num2);
   // input 3rd number
Serial.print("Enter Arrear Amount: ");
   while(Serial.available()==0)
   {
   }
   num3= Serial.parseFloat();
   Serial.println(num3);
   
   int unit = (num1 - num2);


   //Serial.println(fixed);
   if (unit<=100) //0 to 100 unit rate 3.5
   {
    fixed = 50;
    total = (unit*3.35) + fixed;
    Serial.println(total);
    ed = (total*0.05);
    total = total + ed + num3;
     Serial.println(total);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("U:");
    lcd.setCursor(2,0);
    lcd.print(unit);
    lcd.setCursor(0,1);
    lcd.print("EC:");
    lcd.setCursor(3,1);
    lcd.print((unit*3.35));
    lcd.setCursor(8,0);
    lcd.print("ED:");
    lcd.setCursor(11,0);
    lcd.print(ed);
    lcd.setCursor(10,1);
    lcd.print("F:");
    lcd.setCursor(12,1);
    lcd.print(fixed);
    delay(8000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Bill:Rs");
    lcd.setCursor(7,0);
    lcd.print(total);
    lcd.setCursor(0,1);
    lcd.print("BBDD:Rs");
    lcd.setCursor(7,1);
    total = total-total*0.01;
    lcd.print(total);
   }
   else if ( (unit>=101)  &&  (unit<=150) )//101 to 150 rate 3.85
   {
    total = (100*3.35) + ((unit-100)*3.85)+fixed;
    ed = (total*0.05);
    total = total + ed + num3;
    //Serial.println(ed);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("U:");
    lcd.setCursor(2,0);
    lcd.print(unit);
    lcd.setCursor(0,1);
    lcd.print("EC:");
    lcd.setCursor(3,1);
    lcd.print((100*3.35) + ((unit-100)*3.85));
    lcd.setCursor(8,0);
    lcd.print("ED:");
    lcd.setCursor(11,0);
    lcd.print(ed,2);
    lcd.setCursor(10,1);
    lcd.print("F:");
    lcd.setCursor(12,1);
    lcd.print(fixed);
    delay(8000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Bill:Rs");
    lcd.setCursor(7,0);
    lcd.print(total,2);
    lcd.setCursor(0,1);
    lcd.print("BBDD:Rs");
    lcd.setCursor(7,1);
    total = total-total*0.01;
    lcd.print(total,2);
   }
   else (unit>=151);//151 to 300 rate is 5
   {
    total = (100*3.35) + (50*3.85) + ((unit-150)*5)+fixed;
    ed = (total*0.05);
    total = total + ed + num3;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("U:");
    lcd.setCursor(2,0);
    lcd.print(unit);
    lcd.setCursor(0,1);
    lcd.print("EC:");
    lcd.setCursor(3,1);
    lcd.print((100*3.35) + (50*3.85) + ((unit-150)*5));
    lcd.setCursor(8,0);
    lcd.print("ED:");
    lcd.setCursor(11,0);
    lcd.print(ed,2);
    lcd.setCursor(10,1);
    lcd.print("F:");
    lcd.setCursor(12,1);
    lcd.print(fixed);
    delay(8000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Bill:Rs");
    lcd.setCursor(7,0);
    lcd.print(total,2);
    lcd.setCursor(0,1);
    lcd.print("BBDD:Rs");
    lcd.setCursor(7,1);
    total = total-total*0.01;
    lcd.print(total);
   }
}

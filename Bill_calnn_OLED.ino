#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);


int num1= "";
int num2= "";
float num3,total,ed,ec;
int fixed;
int unit;

void setup() {
    Serial.begin(9600);//to display value on serial monitor
      display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
      display.clearDisplay();
      display.setTextSize(1);
  display.setTextColor(WHITE);
        display.setCursor(13,0);
    display.print("Know Your e-Bill");
    display.setCursor(14,16);
 display.print("Er. Vineet Kumar");
  //  Serial.println("---------\n");
    delay(500);
    display.display();
}

void prints(){
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.print("UNIT:");
      display.setCursor(33,0);
      display.print(unit);

      display.setCursor(0,16);
     display.print("ED  :");
     display.setCursor(33,16);
     display.print(ed);
      
     display.setCursor(0,26);
     display.print("EC  :");
     display.setCursor(33,26);
     display.print(ec);

     display.setCursor(0,36);
     display.print("Fix :");
     display.setCursor(33,36);
     display.print(fixed);
      
    display.setCursor(0,46);
    display.print("Pay Amt.:");
    display.setCursor(60,46);
    display.print(total);

      total = (total - (total*0.01));
   display.setCursor(0,56);
   display.print("By Due Dt:");
   display.setCursor(60,56);
   display.print(total);
          display.display();
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

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <EEPROM.h>
#define menu 3
#define up  4
#define down 5
#define low 13
#define high 12
int m,v,vo,vu,dl,dly,dly1,tmp;
unsigned long vtm;
bool st,dt;

void setup(){
  Serial.begin(9600);
  digitalWrite(high, LOW);
  digitalWrite(low, LOW); 
   digitalWrite(11, HIGH); 
  lcd.init();
  lcd.backlight();
  pinMode(11,OUTPUT);
  pinMode(low,OUTPUT);
  pinMode(high,OUTPUT);
  pinMode(menu,INPUT_PULLUP);
  pinMode(up,INPUT_PULLUP);
  pinMode(down,INPUT_PULLUP);
  lcd.print("Low-High Voltage");
  lcd.setCursor(0,1);     
  lcd.print(" Protect System");
  delay(5000);
  lcd.setCursor(0,0);     
  lcd.print("MAIN:250V OP:OFF");
  lcd.setCursor(0,1);     
  lcd.print("HL:250-210V D:10");
 

  // a=
   //
  
   vo=EEPROM.read(0);
   vo=vo+EEPROM.read(1)*100;
   if(vo>300) vo=0;
  vu=EEPROM.read(2);
   if(vu>200) vu=0;
   dl=EEPROM.read(3);
   if(dl>50) dl=0;
}
void loop(){
   for(int i=0;i<500;i++){
  v=analogRead(A2);
  
  v=map(v,0,1023,0,2950);
  vtm=vtm+v;
  }
  dly1++;
  if(dly1>9){dly1=0;dt=!dt;}
 v=vtm/5000;
 v=(v+3);
 //if(v<0)v=0;
 vtm=0;
  if(v<vu-10|v>vo){
     digitalWrite(11,1);
    dly=dly1=0;dt=1;
  }
   if(v>vu&v<vo-1){
    if(dly<dl&dly1==9)dly++;
    if(dly==dl){ digitalWrite(11,0);dt=1; }

    }
  if (v<vu)
  {
    digitalWrite(low, HIGH);
    digitalWrite(high, LOW);    
  }
  else if(v>vo)
  {
    digitalWrite(high, HIGH);
    digitalWrite(low, LOW);   
  }
  if(v>vu&v<vo-1){
   digitalWrite(high, LOW);
   digitalWrite(low, LOW); 
  }
  if(m==0){
  
lcd.setCursor(5,0); 
if(v<100)lcd.print(" "); 
   lcd.print(v);
   lcd.setCursor(13,0); 
   if(digitalRead(11))lcd.print("OFF");
   else  lcd.print("ON ");
   //lcd.print("MAIN:250V OP:OFF");
   lcd.setCursor(3,1); 
if(vo<100)lcd.print(" "); 
   lcd.print(vo);   
   lcd.setCursor(7,1); 
   lcd.print(vu); 
   if(vu<100)lcd.print("V ");
   else lcd.print("V");  
   lcd.setCursor(14,1); 
  if(dt|digitalRead(2)) lcd.print(dl); 
  else lcd.print("  ");
lcd.print(" ");


}
if(digitalRead(menu)&digitalRead(up)&digitalRead(down)){st=0;}
  
  if(!digitalRead(menu)&st==0){
    lcd.clear();
   m++;
   if(m>3){
    lcd.setCursor(0,0);     
   lcd.print("MAIN:250V OP:OFF");
   lcd.setCursor(0,1);     
   lcd.print("HL:250-210V D:10");
   EEPROM.update(0,vo%100); 
   EEPROM.update(1,vo/100); 
    EEPROM.update(2,vu); 
    EEPROM.update(3,dl); 
    m=0;}
   
    st=1;
    //
    }
   
if(!digitalRead(up)&st==0){
  if(m==1)vo+=5;
  
   if(m==2)vu+=5;
    if(m==3)dl+=1;
    if(vo>300)vo=300;
    if(vu>200)vu=200;
    if(dl>50)dl=50;
   st=1;
}
if(!digitalRead(down)&st==0){
  if(m==1)vo-=5;
   if(m==2)vu-=5;
    if(m==3)dl-=1;

    if(vo<200)vo=200;
    if(vu<100)vu=100;
    if(dl<0)dl=0;
   st=1;
 }

  if(m==1){
  
lcd.setCursor(0,0); 
lcd.print(" SET HIGH VOLT  ");
   lcd.setCursor(6,1); 
   lcd.print(vo);    

}
  if(m==2){
  
lcd.setCursor(0,0); 
lcd.print("  SET LOW VOLT ");
   lcd.setCursor(6,1); 
   lcd.print(vu); 
     

}
  if(m==3){
  
lcd.setCursor(0,0); 
lcd.print("  SET ON DELAY  ");
   lcd.setCursor(7,1); 
   lcd.print(dl);    
lcd.print(" "); 
}
}

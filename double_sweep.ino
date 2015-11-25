#include <Servo.h>
Servo sv5;
Servo sv9;
const int sv5Pin = 8;  // sv5 接 Pin 8
const int sv9Pin = 9;  // sv9 接 Pin 9
const int every555 = 15;
const int every999 = 50;
unsigned long last555 = 0;
unsigned long last999 = 0; // last moving time
int dir5 = 1;
int dir9 = -1;
int pos555 = 90;
int pos999 = 90;
void setup() { 
   sv9.attach(sv9Pin); 
   sv5.attach(sv5Pin); 
   Serial.begin(9600);
   sv9.write(pos999);
   sv5.write(pos555);
   Serial.println("Test 2 Serbo");
   delay(568);
} 
void loop( ) {
  check555( );
  check999( );
  check888( );
}
void check555( ) {
   if(millis( ) - last555 < every555) return;   //如果(现在时间—上次做事时间)<every)就立即离开函数,不再继续
   last555 = millis( );
   pos555 += dir5;
   sv5.write(pos555);
   if(dir5 == 1){
      if(pos555 >179) dir5 = -1;
   }else{
      if(pos555 < 1) dir5 = 1;
   }
}
void check999( ) {
   if(millis( ) - last999 < every999) return; 
   last999 = millis( );
   pos999 += dir9;
   sv9.write(pos999);
   if(dir9 == 1){
      if(pos999 >179) dir9 = -1;
   }else{
      if(pos999 < 1) dir9 = 1;
   }
}
void check888( ) {
  // more Servo ?
}

#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
#include <Adafruit_NeoPixel.h>

#define PIN 5
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);



const int SP_PIN[2]={11,10};
const int MOTOR_PIN[4] = {9,8,7,6};

const int blueTx=3;
const int blueRx=2;
SoftwareSerial mySerial(blueTx, blueRx);

void setup() 
{
  strip.begin();
  strip.show(); 
  
  Serial.begin(9600);   
  mySerial.begin(9600); 
  for(int i=0;i<2;i++) { pinMode(SP_PIN[i],OUTPUT); }
  for(int i=0;i<4;i++) { pinMode(MOTOR_PIN[i],OUTPUT); }
}
char c=' ';
unsigned long previous_time = 0;
unsigned long current_time = 0;
uint16_t i, j;
void loop()
{
  if (mySerial.available()) {
    c = mySerial.read();
    Serial.write(c);
    command(c);
  }
  if (Serial.available()) {         
    mySerial.write(Serial.read()); 
  }


  current_time = millis()/1000;
  if(previous_time != current_time){
    if(current_time >=(256*5)) {
      current_time = 0;
    }
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + current_time) & 255));
    }
    strip.show();
    previous_time = current_time;
  }
}

void command(int c) {
  if(c=='w'){ // foward
    MVF(80,80);
  }
  else if(c=='a'){ //left
    MVL(50);
  }
  else if(c=='d') { //right
    MVR(50);
  }
  else if(c=='x') { //back
    MVB(80,80);
  }
  else { //stop
    MVF(0,0); 
  } 
}

void MVF(int L,int R){
  analogWrite(SP_PIN[0],L);
  analogWrite(SP_PIN[1],R);
  boolean motor_direction[4] = {LOW,HIGH,LOW,HIGH};
  for(int i=0;i<4;i++){
    digitalWrite(MOTOR_PIN[i],motor_direction[i]);
  }
}
void MVB(int L,int R){
  analogWrite(SP_PIN[0],L);
  analogWrite(SP_PIN[1],R);
  boolean motor_direction[4] = {HIGH,LOW,HIGH,LOW};
  for(int i=0;i<4;i++){
    digitalWrite(MOTOR_PIN[i],motor_direction[i]);
  }
}

void MVR(int R){
  analogWrite(SP_PIN[0],R);
  analogWrite(SP_PIN[1],R);
  boolean motor_direction[4] = {LOW,HIGH,HIGH,LOW};
  for(int i=0;i<4;i++){
    digitalWrite(MOTOR_PIN[i],motor_direction[i]);
  }
}
void MVL(int L){
  analogWrite(SP_PIN[0],L);
  analogWrite(SP_PIN[1],L);
  boolean motor_direction[4] = {HIGH,LOW,LOW,HIGH};
  for(int i=0;i<4;i++){
    digitalWrite(MOTOR_PIN[i],motor_direction[i]);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

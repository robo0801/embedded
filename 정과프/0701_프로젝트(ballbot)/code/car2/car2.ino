#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

const int SP_PIN[2]={11,10};
const int MOTOR_PIN[4] = {9,8,7,6};

const int blueTx=3;
const int blueRx=2;
SoftwareSerial mySerial(blueTx, blueRx);

void setup() 
{
  Serial.begin(9600);   
  mySerial.begin(9600); 
  for(int i=0;i<2;i++) { pinMode(SP_PIN[i],OUTPUT); }
  for(int i=0;i<4;i++) { pinMode(MOTOR_PIN[i],OUTPUT); }
}
char c=' ';
void loop()
{
  if (mySerial.available()) {
    c = mySerial.read();
    Serial.write(c); 

    command(c);
  }
  if (Serial.available()) {         
    mySerial.write(Serial.read());  //시리얼 모니터 내용을 블루추스 측에 WRITE
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
  boolean motor_direction[4] = {HIGH,LOW,HIGH,LOW};
  for(int i=0;i<4;i++){
    digitalWrite(MOTOR_PIN[i],motor_direction[i]);
  }
}
void MVB(int L,int R){
  analogWrite(SP_PIN[0],L);
  analogWrite(SP_PIN[1],R);
  boolean motor_direction[4] = {LOW,HIGH,LOW,HIGH};
  for(int i=0;i<4;i++){
    digitalWrite(MOTOR_PIN[i],motor_direction[i]);
  }
}

void MVR(int R){
  analogWrite(SP_PIN[0],R);
  analogWrite(SP_PIN[1],R);
  boolean motor_direction[4] = {HIGH,LOW,LOW,HIGH};
  for(int i=0;i<4;i++){
    digitalWrite(MOTOR_PIN[i],motor_direction[i]);
  }
}
void MVL(int L){
  analogWrite(SP_PIN[0],L);
  analogWrite(SP_PIN[1],L);
  boolean motor_direction[4] = {LOW,HIGH,HIGH,LOW};
  for(int i=0;i<4;i++){
    digitalWrite(MOTOR_PIN[i],motor_direction[i]);
  }
}

#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
 
int blueTx=2;   //Tx (보내는핀 설정)at
int blueRx=3;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
int in1 = 9;
int in2 = 10;
void setup() 
{
  Serial.begin(9600);   //시리얼모니터
  mySerial.begin(9600); //블루투스 시리얼
  
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
}
char c = ' ';
void loop()
{

  if (mySerial.available()) {       
    c = mySerial.read();
    Serial.write(c);  //블루투스측 내용을 시리얼모니터에 출력
  }
  if (Serial.available()) { 
    mySerial.write(Serial.read());  //시리얼 모니터 내용을 블루추스 측에 WRITE 
  }
  
  if(c == 'w'){
    analogWrite(in1, 200);
    analogWrite(in2, 0);
  }
  else if(c == 'x'){
    analogWrite(in1, 0);
    analogWrite(in2, 200);
  }
  else if(c == 'a'){
    analogWrite(in1, 0);
    analogWrite(in2, 100);
  }
  else if(c == 'd'){
    analogWrite(in1, 100);
    analogWrite(in2, 0);
 }
 else {
   analogWrite(in1, 0);
   analogWrite(in2, 0);
  
  }
}

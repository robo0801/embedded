#include <SoftwareSerial.h>
#include <Servo.h>

/* DC Motor Pin */
const int DCmotorPin[4] = {11,10,6,5};
/* servo Motor pin */
const int ServoPin = 9;
/* bluetooth pin */
const int blueTx = 2;
const int blueRx = 3;
/* ultrasonic sensor pin */
const int trig = 13;
const int echo = 12;

/* bluetooth setting */
SoftwareSerial mySerial(blueTx, blueRx);
/* servo Motor setting */
Servo servo; 

int Lsp = 200, Rsp = 200; // DC motor speed left and right
char c = ' '; //?

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  
  servo.attach(ServoPin);
  
  for(int i=0;i<4;i++){
    pinMode(DCmotorPin[i],OUTPUT);
  }

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

long duration1,duration2;
double distance1,distance2;

void loop() {

  
  //sm();
  servo.write(90);

  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);

  if(digitalRead(echo)==LOW){ duration1 = pulseIn(echo, HIGH); }
  distance1 = (double)duration1 / 29.0 / 2.0;
  Serial.println(distance1);

  if(distance1 < 20) {
    //servo.write(20);
    delay(20);
    
    digitalWrite(trig, HIGH);
    delay(10);
    digitalWrite(trig, LOW);
  
    if(digitalRead(echo)==LOW){ duration1 = pulseIn(echo, HIGH); }
    distance1 = (double)duration1 / 29.0 / 2.0;
    Serial.print(distance1);
    Serial.print("    ");
    //servo.write(160);
    delay(1000);
  
    digitalWrite(trig, HIGH);
    delay(10);
    digitalWrite(trig, LOW);
  
    if(digitalRead(echo)==LOW){ duration2 = pulseIn(echo, HIGH); }
    distance2 = (double)duration2 / 29.0 / 2.0;
    Serial.println(distance2);
    if(distance1>= distance2){
      mvL();
      delay(500);
    }
    else{
      mvR();
      delay(500);
    }

  }
  
  mvF();
  delay(20);
  
}

void mvF() {
  analogWrite(DCmotorPin[0],Lsp);
  analogWrite(DCmotorPin[1],0);
  analogWrite(DCmotorPin[2],Rsp);
  analogWrite(DCmotorPin[3],0);
}
void mvB() {
  analogWrite(DCmotorPin[0],0);
  analogWrite(DCmotorPin[1],Lsp);
  analogWrite(DCmotorPin[2],0);
  analogWrite(DCmotorPin[3],Rsp);
}

void mvL() {
  analogWrite(DCmotorPin[0],0);
  analogWrite(DCmotorPin[1],Lsp/2);
  analogWrite(DCmotorPin[2],Rsp/2);
  analogWrite(DCmotorPin[3],0);
}

void mvR() {
  analogWrite(DCmotorPin[0],Lsp/2);
  analogWrite(DCmotorPin[1],0);
  analogWrite(DCmotorPin[2],0);
  analogWrite(DCmotorPin[3],Rsp/2);
}

void up(){
  if(Lsp <=255-3) { Lsp+=3; }
  if(Rsp <=255-3) { Rsp+=3; }
}

void down(){
  if(0+3 <= Lsp)  { Lsp-=3; }
  if(0+3 <= Rsp ) { Rsp-=3; }
}

void Lup(){
  if(Lsp <=255-3) { Lsp+=3; }
}
void Rup(){
  if(Rsp <=255-3) { Rsp+=3; }
}

void sm() {
  analogWrite(DCmotorPin[0],0);
  analogWrite(DCmotorPin[1],0);
  analogWrite(DCmotorPin[2],0);
  analogWrite(DCmotorPin[3],0);  
}



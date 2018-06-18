#include <SoftwareSerial.h>


const int DCmotorPin[4] = {11,10,6,5};
const int blueTx = 2;
const int blueRx = 3;

SoftwareSerial mySerial(blueTx, blueRx);

int Lsp = 200, Rsp = 200;
char c = ' ';

void mvF();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  for(int i=0;i<4;i++){
    pinMode(DCmotorPin[i],OUTPUT);
  }
}
void loop() {
  
    if (mySerial.available()) {       
        c=mySerial.read();
        Serial.println(c);
        if(c == 'w'){ mvF(); }
        else if(c == 'a') { mvR(); }
        else if(c == 'x') { mvB(); }
        else if(c == 'd') { mvL(); }
        else if(c == '1') { Lup(); }//L UP
        else if(c == '2') { up(); }//F UP
        else if(c == '3') { Rup(); }//R UP
        else if(c == '4') { down(); }//B DOWN
        else { sm(); }
    }
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



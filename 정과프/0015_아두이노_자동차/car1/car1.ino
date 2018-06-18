#include <SoftwareSerial.h>


const int DCmotorPin[4] = {11,10,6,5};
const int blueTx = 2;
const int blueRx = 3;

SoftwareSerial mySerial(blueTx, blueRx);

int Lsp = 150, Rsp = 150;
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
  /*
    if (mySerial.available()) {       
        c=mySerial.read();
        Serial.println(c);
        if(c == 'a'){
            mvF();
        }
      

    }
    */
  mvF();  
}

void mvF() {
  analogWrite(DCmotorPin[0],Lsp);
  analogWrite(DCmotorPin[1],0);
  analogWrite(DCmotorPin[2],Rsp);
  analogWrite(DCmotorPin[3],0);
}

void sm() {
  analogWrite(DCmotorPin[0],0);
  analogWrite(DCmotorPin[1],0);
  analogWrite(DCmotorPin[2],0);
  analogWrite(DCmotorPin[3],0);  
}


const int SP_PIN[2]={11,10};
const int MOTOR_PIN[4] = {9,8,7,6};

void setup() {
  for(int i=0;i<2;i++) { pinMode(SP_PIN[i],OUTPUT); }
  for(int i=0;i<4;i++) { pinMode(MOTOR_PIN[i],OUTPUT); }
}

void loop() {
  MVF(80,80);
  delay(3000);

  MVF(0,0);
  delay(3000);
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

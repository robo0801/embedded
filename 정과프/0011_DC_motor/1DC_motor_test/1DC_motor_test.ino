
int in1 = 9;
int in2 = 8;

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  //pinMode(10,OUTPUT);
}

void loop() {

  analogWrite(in1, 200);     // Motor A 방향설정1
  analogWrite(in2, 0);      // Motor A 방향설정2
  delay(3000);                    // 3초 유지

  analogWrite(in1, 100);     // Motor A 방향설정1
  analogWrite(in2, 0);      // Motor A 방향설정2
  delay(3000);                    // 3초 유지

}



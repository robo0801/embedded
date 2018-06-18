//출력핀(trig)과 입력핀(echo) 연결 설정
int TrigPin = 2;
int EchoPin = 3;
int OutPin = 13;

//시리얼 속도설정, trigPin을 출력, echoPin을 입력으로 설정
void setup() {
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(OutPin, OUTPUT);
}

void loop() {
  long duration;
  double distance;
  
  //Trig 초음파 발사^^; Echo 대기  
  digitalWrite(TrigPin, HIGH);
  delay(10);
  digitalWrite(TrigPin, LOW);
  
  // Echo가 초음파를 수신할 동안의 시간 계산
  if(digitalRead(EchoPin)==LOW){
    duration = pulseIn(EchoPin, HIGH);
  }

  else {
    pinMode(EchoPin,OUTPUT);
    digitalWrite(EchoPin,LOW);
    pinMode(EchoPin,INPUT);  
  }
  // 340m/s --> 1cm/29us. 왕복거리이므로 2로 나눠준다.
  distance = (double)duration / 29.0 / 2.0;

  //시리얼모니터에 Echo가 HIGH인 시간 및 거리를 표시해준다.
  Serial.print("Duration:");    Serial.print(duration);
  Serial.print("\nDIstance:");  Serial.print(distance);   Serial.println("cm\n");
  if (distance < 5) {
    digitalWrite(OutPin, HIGH);
    delay(100);
    digitalWrite(OutPin, LOW);
    delay(200);
  }
  else {
    digitalWrite(OutPin, LOW);
  }
  delay(500); // 0.5 초 간격...
}

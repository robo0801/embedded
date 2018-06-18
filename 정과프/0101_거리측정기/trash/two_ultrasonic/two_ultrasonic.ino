const int T1 = 7, E1 = 6;
const int T2 = 8, E2 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(T1, OUTPUT);
  pinMode(E1, INPUT);
  pinMode(T2, OUTPUT);
  pinMode(E2, INPUT);
}


void loop() {
  digitalWrite(T1,LOW);
  delayMicroseconds(2);
  digitalWrite(T1,HIGH);
  delayMicroseconds(10);
  digitalWrite(T1,LOW);

  double distance1 = pulseIn(E1, HIGH)/58.0;

  delay(500);
  
  digitalWrite(T2,LOW);
  delayMicroseconds(2);
  digitalWrite(T2,HIGH);
  delayMicroseconds(10);
  digitalWrite(T2,LOW);

  double distance2 = pulseIn(E2, HIGH)/58.0;
  
  Serial.println("Distance(cm)1 = " + String(distance1));

  Serial.println("Distance(cm)2 = " + String(distance2));
  
  Serial.println(" ");
  delay(500);
}

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
}

void loop() {
  Serial.println(analogRead(A1));
  Serial.println(digitalRead(2));
}

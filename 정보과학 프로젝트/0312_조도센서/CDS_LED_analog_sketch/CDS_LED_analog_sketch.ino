//aruduino CDS sensor and LED

void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop() {
  float cds_value = analogRead(A1);
  analogWrite(10, (cds_value-50)*2);
  Serial.println(cds_value);
}

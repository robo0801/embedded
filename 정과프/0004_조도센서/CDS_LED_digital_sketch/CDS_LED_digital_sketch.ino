// arduino CDS sensor and LED
// digitalWrite in LED

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop() {
  float cds_value = analogRead(A1);
  if(cds_value < 80){digitalWrite(13,HIGH);}
  else {digitalWrite(13, LOW);}
  //delay(50);
  Serial.println(cds_value);
}

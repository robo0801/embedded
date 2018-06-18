// use Serial communication
// https://kocoafab.cc/tutorial/view/501

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    if(Serial.parseInt() == 1){
        digitalWrite(13,HIGH);
        Serial.write("1");
   }
    else {
       digitalWrite(13,LOW);  
        Serial.write("0");
    }
  }
}

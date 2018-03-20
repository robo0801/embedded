# define L  9
# define E  10
# define D  11

# define B 8
# define U 12
# define T 13


void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  pinMode(8,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  pinMode(13,INPUT_PULLUP);
}

void loop() {
  int s1 = digitalRead(8);
  int s2 = digitalRead(12);
  int s3 = digitalRead(13);

  
  
  if(s1 == 0) digitalWrite(L,HIGH);
  else digitalWrite(L,LOW);
  if(s2 == 0) digitalWrite(E,HIGH);
  else digitalWrite(E,LOW);
  if(s3 == 0) digitalWrite(D,HIGH);
  else digitalWrite(D,LOW);
}

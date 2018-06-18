#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int T1 = 6, E1 = 8;
const int T2 = 9, E2 = 7;

void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");

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
  delayMicroseconds(2);
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
  delayMicroseconds(2);
  digitalWrite(T2,LOW);
  delayMicroseconds(2);
  digitalWrite(T2,HIGH);
  delayMicroseconds(10);
  digitalWrite(T2,LOW);
  double distance2 = pulseIn(E2, HIGH)/58.0;


  lcd.clear();
  Serial.println(distance1);Serial.println(distance2);
  Serial.println(" ");
  lcd.setCursor(0, 0);
  lcd.print(String(distance1)+" "+String(distance2));
  lcd.setCursor(0, 1);
  lcd.print(String(distance1+distance2+5)+"cm");
  delay(500);
}


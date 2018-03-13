#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729

//음계 데이터 (24개)
int melody[] = {NOTE_G7, NOTE_G7, NOTE_A7, NOTE_A7, NOTE_G7,
                NOTE_G7, NOTE_E7, NOTE_G7, NOTE_G7, NOTE_E7,
                NOTE_E7, NOTE_D7, NOTE_G7, NOTE_G7, NOTE_A7,
                NOTE_A7, NOTE_G7, NOTE_G7, NOTE_E7, NOTE_G7,
                NOTE_E7, NOTE_D7, NOTE_E7, NOTE_C7
               };
               
//음의길이, 4:4분음표, 2:2분음표
int noteDurations[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1};

int speakerPin = 12;          // Speaker
int buttonPin = 4;            // Pushbutton

int lastButtonState = HIGH;   // the previous reading from the input pin

long lastDebounceTime = 0;    // the last time the output pin was toggled
long debounceDelay = 50;      // the debounce time; increase if the output flickers

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for (int thisNote = 0; thisNote < 24; thisNote++)  {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(speakerPin, melody[thisNote], noteDuration);   // Sound play
          delay(noteDuration * 1.30);                         // delay
          noTone(speakerPin);                                 // Sound stop
  }
}

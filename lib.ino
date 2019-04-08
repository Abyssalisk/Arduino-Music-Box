void _setup() {
  Serial.begin(9800);

  pinMode(nextButton, INPUT_PULLUP);

  pinMode(speaker, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(bigE, OUTPUT);

}

void _run() {
  checkStuff();
  play(state);
}

void checkStuff() { // check for state change
  setState();
  setTempo(); // check for tempo change;
  setPitch();
}

void setState() {
  Serial.print("current state: ");
  Serial.println(state);
  Serial.print("Reading: "); Serial.println(dr(nextButton));
  if(!dr(nextButton) && pressed == false) {
    state ++;
    if (state >= songCount) {
      state = 0;
    } 
    pressed = true;
  }
  else if(dr(nextButton) && pressed == true){
    pressed = false;
  }
}

void play(int s) {
  switch (s) {
    case 0: zelda(); break;
    case 1: fairy(); break;
    case 2: scale(); break;
    case 3: dragonforce(); break;
    default: break;
  }
}

void setTempo() {
  tempoKnob = analogRead(tempoPin);
  Serial.print("Tempo Before: ");
  Serial.println(tempo);

  // total bits is 1024. Divide by n for n sections.
  if (tempoKnob <= 64)tempo = 0.25;
  if (tempoKnob >= 65 && tempoKnob <= 128)tempo = 0.3;
  if (tempoKnob >= 129 && tempoKnob <= 192)tempo = 0.4;
  if (tempoKnob >= 193 && tempoKnob <= 256)tempo = 0.5;
  if (tempoKnob >= 257 && tempoKnob <= 320)tempo = 0.6;
  if (tempoKnob >= 321 && tempoKnob <= 384)tempo = 0.7;
  if (tempoKnob >= 385 && tempoKnob <= 448)tempo = 0.8;
  if (tempoKnob >= 449 && tempoKnob <= 512)tempo = 0.9;
  if (tempoKnob >= 513 && tempoKnob <= 576)tempo = 1;
  if (tempoKnob >= 577 && tempoKnob <= 640)tempo = 1.1;
  if (tempoKnob >= 641 && tempoKnob <= 704)tempo = 1.2;
  if (tempoKnob >= 705 && tempoKnob <= 768)tempo = 1.3;
  if (tempoKnob >= 769 && tempoKnob <= 832)tempo = 1.4;
  if (tempoKnob >= 833 && tempoKnob <= 896)tempo = 1.5;
  if (tempoKnob >= 897 && tempoKnob <= 960)tempo = 1.6;
  if (tempoKnob >= 961)tempo = 1.7;
  
  Serial.print("Tempo After Conversion: ");
  Serial.println(tempo);
  return tempo;
}

void setPitch() {
  pitchKnob = analogRead(pitchPin);
  //TODO add pitch knob
  // total bits is 1024. Divide by n for n sections.
  if (pitchKnob <= 64)pitch = 8;
  if (pitchKnob >= 65 && pitchKnob <= 128)pitch = 7;
  if (pitchKnob >= 129 && pitchKnob <= 192)pitch = 6;
  if (pitchKnob >= 193 && pitchKnob <= 256)pitch = 5;
  if (pitchKnob >= 257 && pitchKnob <= 320)pitch = 4;
  if (pitchKnob >= 321 && pitchKnob <= 384)pitch = 3;
  if (pitchKnob >= 385 && pitchKnob <= 448)pitch = 2;
  if (pitchKnob >= 449 && pitchKnob <= 512)pitch = 1;
  if (pitchKnob >= 513 && pitchKnob <= 576)pitch = 0;
  if (pitchKnob >= 577 && pitchKnob <= 640)pitch = -1;
  if (pitchKnob >= 641 && pitchKnob <= 704)pitch = -2;
  if (pitchKnob >= 705 && pitchKnob <= 768)pitch = -3;
  if (pitchKnob >= 769 && pitchKnob <= 832)pitch = -4;
  if (pitchKnob >= 833 && pitchKnob <= 896)pitch = -5;
  if (pitchKnob >= 897 && pitchKnob <= 960)pitch = -6;
  if (pitchKnob >= 961)pitch = -7;

  return pitch;
}

// Read inputs
boolean dr(int i) { // digital read pin
  return digitalRead(i);
}

void lightUpNoteLED(int note){
  turnOffAllLeds();
  switch(note){
  case NOTE_B0: dr(b, 'n'); break;
  case NOTE_C1: dr(c, 'n'); break; 
  case NOTE_CS1: dr(c, 'n'); break;
  case NOTE_D1: dr(d, 'n'); break; 
  case NOTE_DS1: dr(d, 'n'); break;
  case NOTE_E1: dr(e, 'n'); dr(bigE, 'n'); break;
  case NOTE_F1: dr(f, 'n'); break;
  case NOTE_FS1: dr(f, 'n'); break;
  case NOTE_G1: dr(g, 'n'); break;
  case NOTE_GS1: dr(g, 'n'); break;
  case NOTE_A1: dr(a, 'n'); break;  
  case NOTE_AS1: dr(a, 'n'); break;
  case NOTE_B1: dr(b, 'n'); break;  
  case NOTE_C2: dr(c, 'n'); break; 
  case NOTE_CS2: dr(c, 'n'); break;
  case NOTE_D2: dr(d, 'n'); break; 
  case NOTE_DS2: dr(d, 'n'); break;
  case NOTE_E2: dr(e, 'n'); dr(bigE, 'n'); break;
  case NOTE_F2: dr(f, 'n'); break;
  case NOTE_FS2: dr(f, 'n'); break;
  case NOTE_G2: dr(g, 'n'); break; 
  case NOTE_GS2: dr(g, 'n'); break;
  case NOTE_A2: dr(a, 'n'); break; 
  case NOTE_AS2: dr(a, 'n'); break;
  case NOTE_B2: dr(b, 'n'); break; 
  case NOTE_C3: dr(c, 'n'); break; 
  case NOTE_CS3: dr(c, 'n'); break;
  case NOTE_D3: dr(d, 'n'); break; 
  case NOTE_DS3: dr(d, 'n'); break;
  case NOTE_E3: dr(e, 'n'); dr(bigE, 'n'); break;
  case NOTE_F3: dr(f, 'n'); break;
  case NOTE_FS3: dr(f, 'n'); break;
  case NOTE_G3: dr(g, 'n'); break; 
  case NOTE_GS3: dr(g, 'n'); break;
  case NOTE_A3: dr(a, 'n'); break; 
  case NOTE_AS3: dr(a, 'n'); break;
  case NOTE_B3: dr(b, 'n'); break; 
  case NOTE_C4: dr(c, 'n'); break; 
  case NOTE_CS4: dr(c, 'n'); break;
  case NOTE_D4: dr(d, 'n'); break; 
  case NOTE_DS4: dr(d, 'n'); break;
  case NOTE_E4: dr(e, 'n'); dr(bigE, 'n'); break; 
  case NOTE_F4: dr(f, 'n'); break; 
  case NOTE_FS4: dr(f, 'n'); break;
  case NOTE_G4: dr(g, 'n'); break; 
  case NOTE_GS4: dr(g, 'n'); break;
  case NOTE_A4: dr(a, 'n'); break; 
  case NOTE_AS4: dr(a, 'n'); break;
  case NOTE_B4: dr(b, 'n'); break; 
  case NOTE_C5: dr(c, 'n'); break; 
  case NOTE_CS5: dr(c, 'n'); break;
  case NOTE_D5: dr(d, 'n'); break; 
  case NOTE_DS5: dr(d, 'n'); break;
  case NOTE_E5: dr(e, 'n'); dr(bigE, 'n'); break;
  case NOTE_F5: dr(f, 'n'); break;
  case NOTE_FS5: dr(f, 'n'); break;
  case NOTE_G5: dr(g, 'n'); break; 
  case NOTE_GS5: dr(g, 'n'); break;
  case NOTE_A5: dr(a, 'n'); break; 
  case NOTE_AS5: dr(a, 'n'); break;
  case NOTE_B5: dr(b, 'n'); break; 
  case NOTE_C6: dr(c, 'n'); break; 
  case NOTE_CS6: dr(c, 'n'); break;
  case NOTE_D6: dr(d, 'n'); break; 
  case NOTE_DS6: dr(d, 'n'); break;
  case NOTE_E6: dr(e, 'n'); dr(bigE, 'n'); break;
  case NOTE_F6: dr(f, 'n'); break; 
  case NOTE_FS6: dr(f, 'n'); break;
  case NOTE_G6: dr(g, 'n'); break; 
  case NOTE_GS6: dr(g, 'n'); break;
  case NOTE_A6: dr(a, 'n'); break; 
  case NOTE_AS6: dr(a, 'n'); break;
  case NOTE_B6: dr(b, 'n'); break; 
  case NOTE_C7: dr(c, 'n'); break; 
  case NOTE_CS7: dr(c, 'n'); break;
  case NOTE_D7: dr(d, 'n'); break; 
  case NOTE_DS7: dr(d, 'n'); break;
  case NOTE_E7: dr(e, 'n'); dr(bigE, 'n'); break;
  case NOTE_F7: dr(f, 'n'); break;
  case NOTE_FS7: dr(f, 'n'); break; 
  case NOTE_G7: dr(g, 'n'); break; 
  case NOTE_GS7: dr(g, 'n'); break;
  case NOTE_A7: dr(a, 'n'); break; 
  case NOTE_AS7: dr(a, 'n'); break;
  case NOTE_B7: dr(b, 'n'); break; 
  case NOTE_C8: dr(c, 'n'); break; 
  case NOTE_CS8: dr(c, 'n'); break;
  case NOTE_D8: dr(d, 'n'); break; 
  case NOTE_DS8: dr(d, 'n'); break;
  default: break;
  }
}

void turnOffAllLeds(){
  for(int i = 2; i <= 9; i++){
    dr(i, 'f');
  }
}

// turn on/off LEDS
void dr(int i, char c) { // led, n on, f off
  if (c == 'n') digitalWrite(i, HIGH); // turn on
  if (c == 'f') digitalWrite(i, LOW); // turn off
}

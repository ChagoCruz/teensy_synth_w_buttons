#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "notes.h"

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=225,179
AudioEffectEnvelope      envelope1; //added
AudioOutputI2S           i2s1;           //xy=570,191
AudioConnection          patchCord1(waveform1, envelope1); //added
AudioConnection          patchCord2(envelope1, 0, i2s1, 0); //added
AudioConnection          patchCord3(envelope1, 0, i2s1, 1); //added
AudioControlSGTL5000     sgtl5000_1;     //xy=284,402
// GUItool: end automatically generated code


void setup() {
  // put your setup code here, to run once:
  AudioMemory(15);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.6);

  waveform1.begin(1, 0, WAVEFORM_SINE);

  envelope1.noteOn();
  envelope1.attack(10);
  envelope1.delay(20);
  envelope1.release(250);

  Serial.begin(38400);
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);

}

void loop() {
  
  // put your main code here, to run repeatedly:
  if (digitalRead(24) == LOW) {
    waveform1.begin(1, NOTE_C4, WAVEFORM_SINE);
    
    Serial.println("Button C pressed");
  } 
  else if (digitalRead(25) == LOW) {
    waveform1.begin(1, NOTE_Cs4, WAVEFORM_SINE);
    Serial.println("Button C# pressed!!!");
  }
  else if (digitalRead(26) == LOW) {
    waveform1.begin(1, NOTE_D4, WAVEFORM_SINE);
    Serial.println("Button D pressed!!!"); 
  }
  else if (digitalRead(27) == LOW) {
    waveform1.begin(1, NOTE_Ds4, WAVEFORM_SINE);
    Serial.println("Button D# pressed!!!"); 
  }
  else if (digitalRead(28) == LOW) {
    waveform1.begin(1, NOTE_E4, WAVEFORM_SINE);
    Serial.println("Button E pressed!!!"); 
  }
  else if (digitalRead(29) == LOW) {
    waveform1.begin(1, NOTE_F4, WAVEFORM_SINE);
    Serial.println("Button F pressed!!!"); 
  }
  else if (digitalRead(30) == LOW) {
    waveform1.begin(1, NOTE_Fs4, WAVEFORM_SINE);
    Serial.println("Button F# pressed!!!"); 
  }
  else if (digitalRead(31) == LOW) {
    waveform1.begin(1, NOTE_G4, WAVEFORM_SINE);
    Serial.println("Button G pressed!!!"); 
  }
  else if (digitalRead(32) == LOW) {
    waveform1.begin(1, NOTE_Gs4, WAVEFORM_SINE);
    Serial.println("Button G# pressed!!!"); 
  }
  else if (digitalRead(33) == LOW) {
    waveform1.begin(1, NOTE_A4, WAVEFORM_SINE);
    Serial.println("Button A pressed!!!"); 
  }
  else if (digitalRead(34) == LOW) {
    waveform1.begin(1, NOTE_As4, WAVEFORM_SINE);
    Serial.println("Button A# pressed!!!"); 
  }
  else if (digitalRead(35) == LOW) {
    waveform1.begin(1, NOTE_B4, WAVEFORM_SINE);
    Serial.println("Button B pressed!!!"); 
  } else {
    waveform1.amplitude(0);
    Serial.println("Button not pressed!!!");
  }
  delay(250);
}
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH); // keep the power on
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
  pinMode(2, INPUT_PULLUP);
}

// Set that we've just been powered on.
int poweron = 1;

/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void playtune() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(6, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(6);
  }
}


// the loop function runs over and over again forever
void loop() {
  if ( digitalRead(2) == LOW || poweron == 1 ) {
    poweron = 0;
    int breakout = 0;
    tone(6, NOTE_C6, 100);
    delay(100);
    noTone(6);
    tone(6, NOTE_C7, 100);
    delay(100);
    noTone(6);
    for ( int minutes = 0; minutes < 2; minutes++ ) {
      for ( int quarters = 0; quarters < 4 ; quarters++ ) {
        if ( minutes == 1 ) {
          tone(6, NOTE_C6, 100);
          delay(100);
          noTone(6);
        }
        for ( int beep = 0; beep < quarters; beep++ ) {
          tone(6, NOTE_C8, 100);
          delay(120);
          noTone(6);
        }
        for ( int seconds = 0; seconds < 15; seconds++ ) { 
          digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(200);              // wait for 200ms
          digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(200);              // wait for 200ms
          digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(200);              // wait for 200ms
          digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(200);              // wait for 200ms
          digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
          digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
          digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
          digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
          delay(200);              // wait for 200ms
          if ( digitalRead(2) == LOW ) {
            if ( breakout == 2 ) {
              minutes = 2;
              quarters = 4;
              seconds = 15;
            } else {
              breakout++;
            }
          }
          
        }
      }
    }
    playtune();
    digitalWrite(12, LOW); // switch the power off
  }
}

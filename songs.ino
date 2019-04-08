void zelda() {
  int oldPitch = pitch;
  
  // notes in the melody:
  int zeldaNotes[] = {
    notes[46 + pitch], notes[41 + pitch], 0, notes[46 + pitch], notes[46 + pitch], notes[48 + pitch], notes[50 + pitch], notes[51 + pitch], 
    notes[53 + pitch], 0, notes[53 + pitch], notes[53 + pitch], notes[54 + pitch], notes[56 + pitch], notes[58 + pitch], 0, notes[58 + pitch], 
    notes[58 + pitch], notes[56 + pitch], notes[54 + pitch], notes[56 + pitch], notes[54 + pitch], notes[53 + pitch], 0, notes[53 + pitch], 
    notes[51 + pitch], notes[51 + pitch], notes[53 + pitch], notes[54 + pitch], 0, notes[53 + pitch], notes[51 + pitch], notes[49 + pitch], 
    notes[49 + pitch], notes[51 + pitch], notes[53 + pitch], 0, notes[51 + pitch], notes[49 + pitch], notes[48 + pitch], notes[48 + pitch], 
    notes[50 + pitch], notes[52 + pitch], 0, notes[55 + pitch],notes[53 + pitch], notes[41 + pitch], notes[41 + pitch], notes[41 + pitch], 
    notes[41 + pitch], notes[41 + pitch], notes[41 + pitch], notes[41 + pitch], notes[41 + pitch], notes[41 + pitch], notes[41 + pitch]
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int zeldaNoteDurations[] = {
    2, 2, 16, 4, 8, 8, 8, 8, 2, 16, 4, 4, 8, 8, 2, 16, 4, 4, 8, 8, 4, 4, 2, 16, 2, 4, 8, 8, 2, 16, 4, 4, 4, 8, 8, 2, 16, 4, 4, 4, 8, 8, 2, 16, 2, 4,
    8, 8, 4, 8, 8, 4, 8, 8, 4, 4
  };

  // loop through the notes and check for changes that could change the song.
  for (int thisNote = 0; thisNote < (sizeof(zeldaNotes)/sizeof(int)); thisNote++) {
    checkStuff(); // try and check stuff after every note
    if(state != 0)
    {
      break;
    }
    else if(oldPitch != pitch)
    {
      break;
    }
    
    lightUpNoteLED(zeldaNotes[thisNote]);
    
    int noteDuration = (1000 / zeldaNoteDurations[thisNote]) * tempo;
    tone(speaker, zeldaNotes[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;// to distinguish the notes, set a minimum time between them. The note's duration + 30% seems to work well:
    delay(pauseBetweenNotes);
  }
}

void fairy() {
  int oldPitch = pitch;
  
  // notes in the melody:
  int fairyNotes[] = {
   notes[70 + pitch], notes[63 + pitch], notes[59 + pitch], notes[56 + pitch], notes[68 + pitch], notes[63 + pitch], notes[59 + pitch], notes[56 + pitch], 
   notes[67 + pitch], notes[63 + pitch], notes[59 + pitch], notes[56 + pitch], notes[68 + pitch], notes[63 + pitch], notes[59 + pitch], notes[56 + pitch],
   notes[68 + pitch], notes[61 + pitch], notes[58 + pitch], notes[54 + pitch], notes[66 + pitch], notes[61 + pitch], notes[58 + pitch], notes[54 + pitch],
   notes[65 + pitch], notes[61 + pitch], notes[58 + pitch], notes[54 + pitch], notes[66 + pitch], notes[61 + pitch], notes[58 + pitch], notes[54 + pitch],
   notes[66 + pitch], notes[59 + pitch], notes[56 + pitch], notes[53 + pitch], notes[65 + pitch], notes[59 + pitch], notes[56 + pitch], notes[53 + pitch],
   notes[64 + pitch], notes[59 + pitch], notes[56 + pitch], notes[53 + pitch], notes[65 + pitch], notes[59 + pitch], notes[56 + pitch], notes[53 + pitch],
   notes[65 + pitch], notes[58 + pitch], notes[54 + pitch], notes[51 + pitch], notes[63 + pitch], notes[58 + pitch], notes[54 + pitch], notes[51 + pitch],
   notes[62 + pitch], notes[58 + pitch], notes[54 + pitch], notes[51 + pitch], notes[63 + pitch], notes[58 + pitch], notes[54 + pitch], notes[51 + pitch],
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int fairyNoteDurations[] = {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
  };

  // loop through the notes and check for changes that could change the song.
  for (int thisNote = 0; thisNote < (sizeof(fairyNotes)/sizeof(int)); thisNote++) {
    checkStuff(); // try and check stuff after every note
    if(state != 1)
    {
      break;
    } else if(oldPitch != pitch)
    {
      break;
    }
    
    lightUpNoteLED(fairyNotes[thisNote]);

    int noteDuration = (1000 / fairyNoteDurations[thisNote]) * tempo;
    tone(speaker, fairyNotes[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;// to distinguish the notes, set a minimum time between them. The note's duration + 30% seems to work well:
    delay(pauseBetweenNotes);
  }
}

void scale() {
  int oldPitch = pitch;
  
   // notes in the melody:
  int scaleNotes[] = {
    notes[49 + pitch], notes[51 + pitch], notes[53 + pitch], notes[54 + pitch], notes[56 + pitch], notes[58 + pitch], notes[60 + pitch], notes[61 + pitch], 
    notes[60 + pitch], notes[58 + pitch], notes[56 + pitch], notes[54 + pitch], notes[53 + pitch], notes[51 + pitch], notes[49 + pitch] 
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int scaleNoteDurations[] = {
    2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2
  };

  // loop through the notes and check for changes that could change the song.
  for (int thisNote = 0; thisNote < (sizeof(scaleNotes)/sizeof(int)); thisNote++) {
    checkStuff(); // try and check stuff after every note
    if(state != 2)
    {
      break;
    }
    else if(oldPitch != pitch)
    {
      break;
    }
    
    lightUpNoteLED(scaleNotes[thisNote]);
    
    int noteDuration = (1000 / scaleNoteDurations[thisNote]) * tempo;
    tone(speaker, scaleNotes[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;// to distinguish the notes, set a minimum time between them. The note's duration + 30% seems to work well:
    delay(pauseBetweenNotes);
  }
}

void dragonforce() {
  int oldPitch = pitch;
  
   // notes in the melody:
  int dragonNotes[] = {
    notes[39 + pitch], notes[41 + pitch], notes[42 + pitch], notes[39 + pitch], notes[41 + pitch], notes[42 + pitch], notes[44 + pitch], notes[42 + pitch], 
    notes[46 + pitch], notes[42 + pitch], notes[44 + pitch], notes[41 + pitch], notes[42 + pitch], notes[41 + pitch], notes[39 + pitch], notes[37 + pitch],
    notes[39 + pitch], notes[41 + pitch], notes[42 + pitch], notes[39 + pitch], notes[41 + pitch], notes[42 + pitch], notes[44 + pitch], notes[42 + pitch], 
    notes[46 + pitch], notes[42 + pitch], notes[44 + pitch], notes[41 + pitch], notes[42 + pitch], notes[41 + pitch], notes[39 + pitch], notes[37 + pitch],
    
    notes[42 + pitch], notes[42 + pitch], notes[39 + pitch], notes[42 + pitch], notes[42 + pitch], notes[39 + pitch], notes[42 + pitch], notes[39 + pitch], 
    notes[42 + pitch], notes[42 + pitch], notes[39 + pitch], notes[42 + pitch], notes[42 + pitch], notes[39 + pitch], notes[42 + pitch], notes[39 + pitch], 
    notes[46 + pitch], notes[46 + pitch], notes[39 + pitch], notes[46 + pitch], notes[46 + pitch], notes[39 + pitch], notes[46 + pitch], notes[39 + pitch], 
    notes[46 + pitch], notes[46 + pitch], notes[39 + pitch], notes[46 + pitch], notes[46 + pitch], notes[39 + pitch], notes[46 + pitch], notes[39 + pitch],
    notes[44 + pitch], notes[44 + pitch], notes[39 + pitch], notes[44 + pitch], notes[44 + pitch], notes[39 + pitch], notes[44 + pitch], notes[39 + pitch],
    notes[44 + pitch], notes[44 + pitch], notes[39 + pitch], notes[44 + pitch], notes[44 + pitch], notes[39 + pitch], notes[44 + pitch], notes[39 + pitch],
    notes[42 + pitch], notes[42 + pitch], notes[39 + pitch], notes[42 + pitch], notes[42 + pitch], notes[39 + pitch], notes[42 + pitch], notes[39 + pitch], 

    notes[37 + pitch], notes[39 + pitch], notes[42 + pitch], notes[41 + pitch], notes[37 + pitch], notes[39 + pitch], notes[42 + pitch], notes[44 + pitch],
    notes[39 + pitch], notes[41 + pitch], notes[42 + pitch], notes[44 + pitch], notes[46 + pitch], notes[44 + pitch], notes[42 + pitch], notes[41 + pitch],

    notes[42 + pitch], notes[42 + pitch], notes[39 + pitch], notes[42 + pitch], notes[42 + pitch], notes[39 + pitch], notes[42 + pitch], notes[39 + pitch], 
    notes[42 + pitch], notes[42 + pitch], notes[39 + pitch], notes[42 + pitch], notes[42 + pitch], notes[39 + pitch], notes[42 + pitch], notes[39 + pitch], 
    notes[46 + pitch], notes[46 + pitch], notes[39 + pitch], notes[46 + pitch], notes[46 + pitch], notes[39 + pitch], notes[46 + pitch], notes[39 + pitch], 
    notes[46 + pitch], notes[46 + pitch], notes[39 + pitch], notes[46 + pitch], notes[46 + pitch], notes[39 + pitch], notes[46 + pitch], notes[39 + pitch],
    notes[44 + pitch], notes[44 + pitch], notes[39 + pitch], notes[44 + pitch], notes[44 + pitch], notes[39 + pitch], notes[44 + pitch], notes[39 + pitch],
    notes[44 + pitch], notes[44 + pitch], notes[39 + pitch], notes[44 + pitch], notes[44 + pitch], notes[39 + pitch], notes[44 + pitch], notes[39 + pitch]
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int dragonNoteDurations[] = {
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
  };

  // loop through the notes and check for changes that could change the song.
  for (int thisNote = 0; thisNote < (sizeof(dragonNotes)/sizeof(int)); thisNote++) {
    checkStuff(); // try and check stuff after every note
    if(state != 3)
    {
      break;
    }
    else if(oldPitch != pitch)
    {
      break;
    }
    
    lightUpNoteLED(dragonNotes[thisNote]);
    
    int noteDuration = (1000 / dragonNoteDurations[thisNote]) * tempo;
    tone(speaker, dragonNotes[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;// to distinguish the notes, set a minimum time between them. The note's duration + 30% seems to work well:
    delay(pauseBetweenNotes);
  }
}

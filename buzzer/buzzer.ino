// Based on SparkFun's Circuit 2A - Buzzer
// https://github.com/sparkfun/SIK-Guide-Code

int PIN_BUZZER = 10;
int BEAT_LENGTH = 150; // Length of each beat (ms)
int BEAT_DELAY = 50; // Delay after each beat (ms)

void setup() {
  pinMode(PIN_BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  play('g', 2); //ha
  play('g', 1); //ppy
  play('a', 4); //birth
  play('g', 4); //day
  play('C', 4); //to
  play('b', 4); //you

  play(' ', 2); //pause for 2 beats

  play('g', 2); //ha
  play('g', 1); //ppy
  play('a', 4); //birth
  play('g', 4); //day
  play('D', 4); //to
  play('C', 4); //you

  play(' ', 2); //pause for 2 beats

  play('g', 2); //ha
  play('g', 1); //ppy
  play('G', 4); //birth
  play('E', 4); //day
  play('C', 4); //dear
  play('b', 4); //your
  play('a', 6); //name

  play(' ', 2); //pause for 2 beats

  play('F', 2); //ha
  play('F', 1); //ppy
  play('E', 4); //birth
  play('C', 4); //day
  play('D', 4); //to
  play('C', 6); //you

  while (true)
  {
  } //get stuck in this loop forever so that the song only plays once
}

void play(char note, int beats) {
  char notes[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B', ' '};
  int frequencies[] = { 131, 147, 165, 175, 196, 220, 247, 262, 294, 330, 349, 392, 440, 494, 0};

  int frequency;

  // Look up frequency for given note.
  // TODO: Better to use a C enum here?
  for (int i = 0; i < sizeof(notes)/sizeof(notes[0]); i++) {
    if (note == notes[i]) {

      Serial.println(note);
      Serial.println(frequencies[i]);

      frequency = frequencies[i];
    }
  }

  tone(PIN_BUZZER, frequency);
  delay(beats*BEAT_LENGTH);
  noTone(PIN_BUZZER);

  delay(BEAT_DELAY);
}
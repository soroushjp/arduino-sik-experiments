int PIN_R_LED = 9;
int PIN_G_LED = 10;
int PIN_B_LED = 11;

int PIN_PHOTO = A0;
int PIN_POT   = A1;

void setup() {
  pinMode(PIN_R_LED, OUTPUT);
  pinMode(PIN_G_LED, OUTPUT);
  pinMode(PIN_B_LED, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int photo = analogRead(PIN_PHOTO);
  int pot = analogRead(PIN_POT);

  String logPhoto = String("photo: ");
  logPhoto.concat(String(photo));
  Serial.println(logPhoto);
  
  String logPot = String("pot: ");
  logPot.concat(String(pot));
  Serial.println(logPot);

  int rVal;
  int gVal;
  int bVal;
  if (pot < 300) {
    rVal = 255;
    gVal = 0;
    bVal = 0;
  } else if (pot > 300 && pot < 600) {
    rVal = 0;
    gVal = 255;
    bVal = 0;
  } else {
    rVal = 0;
    gVal = 0;
    bVal = 255;
  }

  static bool lightOn = false;
  if (photo > 500) {
    analogWrite(PIN_R_LED, 0);
    analogWrite(PIN_G_LED, 0);
    analogWrite(PIN_B_LED, 0);
    lightOn = false;
  } else {
    float i;
    float dimSteps = 100.0;
    if (lightOn == true) {
      // no fade
      i = dimSteps;
    } else {
      // fade
      i = 1;
      lightOn = true;
    }
    while (i<=dimSteps) {
      analogWrite(PIN_R_LED, rVal*i/dimSteps);
      analogWrite(PIN_G_LED, gVal*i/dimSteps);
      analogWrite(PIN_B_LED, bVal*i/dimSteps);
      i++;
      delay(50);
    }
  }
}
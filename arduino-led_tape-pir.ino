#define led          3          // led Pin (PWM)
#define pir          2          // pir input Pin
#define timeon       120000     // 5 minutes of time with the led on
#define vfade        50         // Fade speed
#define brightness   15         // Max is 255

int fade = 0;

//-----------------------------//
void setup() {
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
}

//-----------------------------//
void turnon() {
  while (fade <= brightness) {
    fade ++;
    analogWrite(led, fade);
    delay(vfade);
  }
}

//-----------------------------//
void turnoff() {
  while (fade > 0) {
    fade --;
    analogWrite(led, fade);
    delay(vfade);
    if (digitalRead(pir)) break;
  }
}

//-----------------------------//
void loop() {

  if (digitalRead(pir)) {
    turnon();
    delay(timeon);
    turnoff();
  }
}

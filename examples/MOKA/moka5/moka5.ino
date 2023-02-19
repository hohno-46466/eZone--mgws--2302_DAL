
// moka5.ino

// Last version: 2023-02-19 by @hohno_at_kuimc

// pins for the LEDs
int LEDs[3] = {0, 0, 0};
const int LEDpins[3] = {11, 10, 9};
// pins for the Buttons
boolean SWs[3] = {false, false, false};
const int SWpins[3] = {A5, A4, A3};
// pins for the Potentiometers
int POTs[3] = {0, 0, 0};
const int POTpins[3] = {A2, A1, A0};

void setup() {
  // initialize serial:
  Serial.begin(57600);
  // make the LEDLEDpins outputs:
  for (int i = 0; i <= 2; i++) {
    pinMode(LEDpins[i], OUTPUT);
    pinMode(SWpins[i], INPUT_PULLUP);
  }
}

void loop() {
  // read Buttons and Potentiometers
  for (int i = 0; i <= 2; i++) {
    SWs[i] = digitalRead(SWpins[i]);
    POTs[i] = analogRead(POTpins[i]);
  }
  Serial.print("S/P\t");
  Serial.print(millis()); Serial.print("\t");
  // print the six numbers in one string with TABs:
  for (int i = 0; i <= 2; i++) {
    Serial.print(SWs[i]); Serial.print("\t");
    Serial.print(POTs[i]); Serial.print("\t");
  }
  Serial.println();

  if (Serial.available() > 0) {
    uint32_t d = millis();
    while (Serial.available() > 0) {
      for (int i = 0; i <= 2; i++) {
        LEDs[i] = Serial.parseInt();
      }
      if (Serial.read() == '\n') {
        Serial.print("LED\t");
        Serial.print(millis()); Serial.print("\t");
        // fade the three LEDs and print the three numbers in one string with TABs:
        for (int i = 0; i <= 2; i++) {
          // constrain the values to 0 - 255
          LEDs[i] = constrain(LEDs[i], 0, 255);
          analogWrite(LEDpins[i], 255 - LEDs[i]);
          Serial.print(LEDs[i]); Serial.print("\t");
        }
        Serial.println();
      }
    }
  } else {
    delay(200);
  }
}

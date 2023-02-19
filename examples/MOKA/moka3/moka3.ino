// moka3.ino

// Last update: Sun Feb 19 09:56:03 AST 2023

const int SWpins[3] = {A3, A4, A5};
int dummyNum = 100;

void setup() {
  Serial.begin(57600);
  pinMode(SWpins[0], INPUT_PULLUP);
  pinMode(SWpins[1], INPUT_PULLUP);
  pinMode(SWpins[2], INPUT_PULLUP);
  randomSeed(micros());
}

void loop() {
  Serial.print("Hello, World! This is moka3"); Serial.print("\t");
  Serial.print(millis());      Serial.print("\t");
  Serial.print(digitalRead(SWpins[0])); Serial.print("\t");
  Serial.print(digitalRead(SWpins[1])); Serial.print("\t");
  Serial.print(digitalRead(SWpins[2])); Serial.print("\t");
  Serial.print(dummyNum); Serial.print("\t"); dummyNum += random(-50,50);
  Serial.print(dummyNum); Serial.print("\t"); dummyNum += random(-50,50);
  Serial.print(dummyNum); Serial.println();   dummyNum += random(-50,50);
  delay(200);
}

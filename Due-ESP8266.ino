int LED = 13;
boolean LEDst = false;

//always high
int CH_PD_8266 = 53;

void setup() {
  Serial.begin(74880);
  Serial3.begin(74880);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LEDst);
  pinMode(CH_PD_8266, OUTPUT);
  digitalWrite(CH_PD_8266, HIGH);
}

void loop() {
  while (Serial.available() > 0) {
    char a = Serial.read();
    Serial3.write(a);
  }
  serialEvent3();
}

void serialEvent3() {
  while (Serial3.available() > 0) {
    char a = Serial3.read();
    Serial.write(a);
    ToggleLED();
  }
}

void ToggleLED(){
  digitalWrite(LED, LEDst = !LEDst);
}


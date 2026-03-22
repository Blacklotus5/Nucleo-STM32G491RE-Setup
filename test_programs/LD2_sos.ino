void setup() {
  pinMode(PA5, OUTPUT);
}

void loop() {
  // First beat
  digitalWrite(PA5, HIGH);
  delay(100); 
  digitalWrite(PA5, LOW);
  delay(100);

  // Second beat
  digitalWrite(PA5, HIGH);
  delay(100);
  digitalWrite(PA5, LOW);

  // Long pause
  delay(800);
}
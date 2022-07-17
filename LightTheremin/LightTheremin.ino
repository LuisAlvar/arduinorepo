const int piezoOutPin = 8;
const int photoTransIn = A0;

int sensorValue;
int sensorLow = 1023;
int sensorHight = 0;

const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(96000);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(photoTransIn);
  }

  digitalWrite(ledPin, LOW);
  Serial.println("Ready");
}

void loop() {
  // put your main code here, to run repeatedly:
}
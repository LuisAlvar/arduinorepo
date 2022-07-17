// Calibrate: Move your hand up and down over the phototransistor, changing the amount
// of the light that reaches it. 
const int piezoOutPin = 8;
const int photoTransIn = A0;

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

//You'll use this as an indicator that your sensor has finished calibrating. 
//For this project, use the on-board LED connected to pin 13.
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Processing...");
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  //millis() function to check the current tim, reports how long the
  //arduino has been running since it was last powered on or reset. 
  while (millis() < 5000) {
    sensorValue = analogRead(photoTransIn);

    if (sensorValue > sensorHigh)
    {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow)
    {
      sensorLow = sensorValue;
    }
  }

  Serial.println("Ready");
  Serial.print("SensorHigh: ");
  Serial.print(sensorHigh);
  Serial.print("\tSensorLow: ");
  Serial.println(sensorLow);
  
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);

  //50 to 4000, these numbers set the range of frquencies the Arduino will generate.
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  
  Serial.print("SensorValue: ");
  Serial.print(sensorValue);
  Serial.print("\tPitch: ");
  Serial.println(pitch);
  tone(8, pitch, 20);
  
  delay(5);
}

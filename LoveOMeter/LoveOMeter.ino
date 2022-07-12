const int sensorPin = A0;
float coldEndpoint = 80.0;
float hotEndpoint = 85.0;
float interval = hotEndpoint - coldEndpoint;
float baselineTemp = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int pinNum = 2; pinNum < 5; pinNum++)
  {
    pinMode(pinNum, OUTPUT);
    digitalWrite(pinNum, LOW);
  }

  delay(100);
  baselineTemp = analogRead(sensorPin);
  Serial.print("Sensor baseline value: ");
  Serial.print(baselineTemp);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensorPin);
  Serial.print("Sensor new value: ");
  Serial.println(sensorValue);

  //convert ADC to voltage
  float voltage = (sensorValue / 1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;
  float tempF = (temperature * 9 / 5.0) + 32;

  Serial.print("Volts: ");
  Serial.println(voltage);

  Serial.print("Degrees C:");
  Serial.println(temperature);


  Serial.print("Degrees F:");
  Serial.println(tempF);

  SetLEDs(Calculate(tempF));

}

int Calculate(float rtTemp)
{
  return ceil((rtTemp - coldEndpoint) / interval);
}

void SetLEDs(int range)
{
  Serial.print("Range:");
  Serial.println(range);
  
  if(range == 1)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);  
  }
  else if (range == 2)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW); 
  }
  else if (range == 3)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);   
  }
  delay(100);
}

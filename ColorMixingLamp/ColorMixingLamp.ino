//------------------------------------------------------------------------------------------
//---- Hardware Variables To Mod
//------------------------------------------------------------------------------------------
// Phototransistor with red gel connect to A0 with a 10 KiloOhms resistor at the end
const int redSensorPin = A0;
// Phototransistor with green gel connect to A1 with a 10 KiloOhms resistor at the end.
const int greenSensorPin = A1;
// Phototransistor with blue gel connect to A2 with a 10 KiloOhms resistor at the end.
const int blueSensorPin = A2;

// The LED with 4 legs is a common cathode RGB LED. Pin order on the LED[red, ground, blue, green]).
// We will register in the following order green, red, and blue
const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

//------------------------------------------------------------------------------------------
//---- Variables To Use
//------------------------------------------------------------------------------------------
// Read the data from the phototransistor 
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

// Calculate value for the RGB LED
int redValue = 0;
int greenValue = 0;
int blueValue = 0;


// Code runs only once
void setup() {
  Serial.begin(9600);

  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  
}

// Code on repeat
void loop() {
  
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);

  //the delay is to allow the sensor to be properly read
  
  Serial.print("Raw Sensor Value \t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.println(blueSensorValue);

  //Calculate the value for the RGB LED 

  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  Serial.print("Mapped Sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.println(blueValue);

  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
  
  
}

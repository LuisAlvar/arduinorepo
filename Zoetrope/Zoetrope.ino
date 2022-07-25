// Analog Input; will control the speed of the motor. 
const int potentioPin = A0;

// Digital Input with 10KOhms in a series to the ground.
const int directionSwitchPin = 4;
const int onoffSwitchPin = 5;

// H-bridge: place the component where the imprinted letter can be 
// read from left and right. 
// Connection 7 and 2 the output signals on 6 and 3 on the H-bridge
  // Connect pin 7 to digital pin 2.
  const int controlPin1 = 2;
  // Connect pin 2 of H-bridge to digital pin 3; 
  // These controlpins will control the direction. 
  const int controlPin2 = 3;
  // Connect pin 1 of H-bridge to digital pin 9; on: receives 5V off: reveives 0V on motor.
  const int enablePin = 9;

int motorEnable = 0;
int motorSpeed = 0;
int motorDirection = 1;

int directionSwitchState;
int onoffSwitchState;
int preDirectionSwitchState;
int preOnOffSwitchState;

int potentioVal;

void setup() {
  // Digital INPUT
  pinMode(directionSwitchPin, INPUT);
  pinMode(onoffSwitchPin, INPUT);
  // OUTPUT
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potentioVal = analogRead(potentioPin);
  directionSwitchState = digitalRead(directionSwitchPin);
  onoffSwitchState = digitalRead(onoffSwitchPin);

  motorSpeed = potentioVal / 4;

  Serial.print("PotentioVal: \t");
  Serial.print(potentioVal);
  Serial.print("\tDirection Switch: \t");
  Serial.print(directionSwitchState);
  Serial.print("\tOnAndOff Switch: \t");
  Serial.println(onoffSwitchState);

  if (onoffSwitchState != preOnOffSwitchState && onoffSwitchState == HIGH)
  {
    motorEnable = !motorEnable;
  }

  if (directionSwitchState != preDirectionSwitchState && directionSwitchState == HIGH)
  {
    motorDirection = !motorDirection;
  }

  if (motorDirection == 1)
  {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnable == 1) {
    analogWrite(enablePin, motorSpeed);
  } else {
    analogWrite(enablePin, 0);
  }

  //Saving the previous state - prevents the case where the user holds down the 
  //push botton longer than neccessary, 1 != 1 && HIGH -> therefore, it will no 
  //trigger a change. 
  preDirectionSwitchState = directionSwitchState;
  preOnOffSwitchState = onoffSwitchState;

}

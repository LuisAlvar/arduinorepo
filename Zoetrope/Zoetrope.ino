const int potentioPin = A0;
const int directionSwitchPin = 4;
const int onoffSwitchPin = 5;
const int controlPin1 = 2;
const int controlPin2 = 3;
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
  // INPUT
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

  preDirectionSwitchState = directionSwitchState;
  preOnOffSwitchState = onoffSwitchState;

}

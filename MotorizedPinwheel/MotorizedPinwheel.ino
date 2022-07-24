const int switchPin = 2;
const int potPin = A0;
const int motorPin = 9;

int switchState = 0;
int potValue = 0;
float amount = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);

  potValue = analogRead(potPin);
  amount = map(potValue, 0, 1023, 0, 1);

  Serial.print("PotValue ");
  Serial.println(potValue);

  Serial.print("Amount ");
  Serial.println(amount);

  digitalWrite(motorPin, amount);
  
  //  if (switchState == HIGH) {
  //    digitalWrite(motorPin, HIGH);
  //  } else {
  //    digitalWrite(motorPin, LOW);
  //  }

}

int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  
  // resistor color [brown, black, orange, gold]
  // 1 0 x 10^3 +- 5% =  10k Ohms
  pinMode(2, INPUT); 

  // resistor color [red, red, blue, black, brown]
  // 2 2 6 x 10^0 +- 1% = 226 Ohms
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == LOW)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else
  {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);

  }
}

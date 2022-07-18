// the Pin 8 will read data from the tilt sensor
const int switchPin = 8;

//This will hold the time an LED was last changed
unsigned long previousTime = 0;

// Holds the current state
int switchState = 0;
// Holds the previous state
int prevSwitchState = 0;
// This is starting index of the LED output pins
int led = 2;
// 600,000 ms = 10 minutes
long interval = 60000;

bool bComplete = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Setting up..");
  
  for (int x = 2; x < 8; ++x)
  {
    pinMode(x, OUTPUT);
  }

  pinMode(switchPin, INPUT);
  Serial.println("Ready");
}

void loop() {

  // store the amouhnt of time the Arduino has been running 
  unsigned long currentTime = millis();

  Serial.print("currentTime ");
  Serial.print(currentTime);
  Serial.print("\tpreviousTime  ");
  Serial.println(previousTime);
  
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    if(led == 7){
      bComplete = true;
    }
    ++led;
  }

  switchState = digitalRead(switchPin);
  
  Serial.print("switchState ");
  Serial.print(switchState);
  Serial.print("\tPrevious State: ");
  Serial.println(prevSwitchState);

  if(switchState != prevSwitchState){
    for(int x = 2; x < 8; ++x)
    {
      digitalWrite(x, LOW); 
     }
     led = 2;
     bComplete = false;
     previousTime  = currentTime;
  }

  if(bComplete)
  {
    for(int x = 2; x <= 7; ++x)
    {
      digitalWrite(x, LOW);  
    }  
    delay(5);
    for(int x = 7; x <= 2; --x)
    {
      digitalWrite(x, HIGH);  
    } 
  }
  
  prevSwitchState = switchState;
}

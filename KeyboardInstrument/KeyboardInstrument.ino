// tone() function will generate sound, but it does have a few limitations.
// It can only create square waves, not smoth sine waves or triangles. 
// Square waves are more like series of on and off pulses. 

int notes[] = {262, 294, 330, 349};

int oPiezoPin = 8;
int iPushAnlog = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int keyVal = analogRead(iPushAnlog);
  
  Serial.print("keyValue ");
  Serial.println(keyVal);

  if(keyVal == 1023)
  {
    tone(oPiezoPin, notes[0]);
  }
  else if(keyVal >= 990 && keyVal <= 1010)
  {
    tone(oPiezoPin, notes[1]);  
  }
  else if (keyVal >= 505 && keyVal <= 515)
  {
    tone(oPiezoPin, notes[2]);
  }
  else if (keyVal >= 5 && keyVal <= 10)
  {
    tone(oPiezoPin, notes[3]);  
  }
  else 
  {
    //providing the pin numbe to stop playing sound on. 
    //dont use tone for this. 
    noTone(oPiezoPin);  
  }
}

int led = 13;
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(led, 13);
  
  digitalWrite(latchPin, LOW);
  digitalWrite(led, 1);
  shiftOut(dataPin, clockPin, MSBFIRST, 0x0);
  digitalWrite(latchPin, HIGH);
  digitalWrite(led, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int j = 0; j < 256; j++) {
    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, LOW);
    delay(1000);
    shiftOut(dataPin, clockPin, LSBFIRST, j);   
    //return the latch pin high to signal chip that it 
    //no longer needs to listen for information
    digitalWrite(latchPin, HIGH);
    delay(1000);
  }   
}

void escribirLed(unsigned int led)
{
  led = (byte)constrain(led, 0, 7);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 1 << led);
  digitalWrite(latchPin, HIGH);  
}


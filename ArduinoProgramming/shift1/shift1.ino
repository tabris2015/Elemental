#define CLOCK_PIN 3
#define DATA_PIN 4
#define LATCH_PIN 5
#define LED_PIN 13

//int nLed = 0;
void setup() {
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(CLOCK_PIN, 0);
  digitalWrite(DATA_PIN, 0);
  digitalWrite(LATCH_PIN, 0);
  digitalWrite(LED_PIN, 0);
}

void loop() {
  for(int i = 0; i < 4; i++)
  {
  	encender2Leds(i, 7-i);
  	delay(500);
  }
  
  for(int i = 3; i >= 0; i--)
  {
  	encender2Leds(i, 7 - i);
  	delay(500);
  }
  

}

void encenderLed(int nLed)
{
  digitalWrite(LATCH_PIN, 0);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 1 << nLed);
  digitalWrite(LATCH_PIN, 1);
}
void encender2Leds(int nLed1, int nLed2)
{
  digitalWrite(LATCH_PIN, 0);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, (1 << nLed1)|(1 << nLed2));
  digitalWrite(LATCH_PIN, 1);	
}
void encenderLed16(int nLed)
{
  digitalWrite(LATCH_PIN, 0);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST,((1 << nled) >> 8) );
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, );
  
  digitalWrite(LATCH_PIN, 1);	
}
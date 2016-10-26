#define BOTON 8
volatile int contador = 0;
// Install Pin change interrupt for a pin, can be called multiple times
void pciSetup(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}
// Use one Routine to handle each group
ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
 {    
   contador++;
   contador = contador > 100 ? 0 : contador; 
 }
void setup() {  
  pinMode(BOTON, INPUT_PULLUP);
// enable interrupt for pin...
  pciSetup(8);
  Serial.begin(9600);
}
void loop() {
  Serial.println(contador);
  delay(1000);
}
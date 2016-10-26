#include <LowPower.h>
int estado = 0;
void setup() {
  /* code */
  pinMode(13,OUTPUT);
}
void loop() {
  /* code */
  estado = !estado;
  digitalWrite(13, estado);
  for(int i = 0; i < 450; i++)
  {
  	LowPower.powerDown(SLEEP_500MS, ADC_OFF, BOD_OFF); // pone al micro en modo sleep	
  }
  
}
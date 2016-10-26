#include "avr/wdt.h"

void setup() {
  wdt_disable();
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("iniciando programa...");
  // habilitamos el watchdog
  wdt_enable(WDTO_1S); // un segundo de tiempo
}
void loop() {
  //
  wdt_reset(); // 
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(13, 0);
  delay(100);
  Serial.println("todo marcha bien");
  
}
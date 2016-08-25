#include "ServoSweep.h"
#define S_PIN 9
#define INTER 80
long interval = 30;

ServoSweep aguja(S_PIN, INTER);
void setup() {
  
}
void loop() {
  aguja.update();
}
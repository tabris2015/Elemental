#include "ServoSweep.h"
#include "Parpadeador.h"
#define S_PIN 9
#define INTER 80
long interval = 30;
Servo servo;
ServoSweep aguja(INTER);
Parpadeador led(13, 500);

void setup() {
  Serial.begin(9600);
  servo.attach(S_PIN);
}
void loop() {
  aguja.Update(&servo);
  led.Actualizar();
}

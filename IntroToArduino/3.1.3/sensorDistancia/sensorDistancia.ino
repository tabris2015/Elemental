#include <NewPing.h>
#define LED_PIN 13
#define TRIG_PIN 10
#define ECHO_PIN 9

#define MAX_DIST 100

NewPing sensor(TRIG_PIN, ECHO_PIN, MAX_DIST);
int distancia;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  distancia = sensor.ping_cm();
  Serial.println(distancia);
  if(distancia == 0) // fuera de rango
  {
  	distancia = 100;
  }
  if(distancia < 20)
  {
  	digitalWrite(LED_PIN, 1);
  }
  else
  {
  	digitalWrite(LED_PIN, 0);
  }
  delay(100);
}
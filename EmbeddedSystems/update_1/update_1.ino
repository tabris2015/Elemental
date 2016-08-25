#define LED 13
int estado_led = 0;
long tiempo_anterior_led;
long intervalo_led = 500;
void setup() {
  pinMode(LED, OUTPUT);
}
void loop() {
  long tiempo = millis();
  if((tiempo - tiempo_anterior_led) > intervalo_led)
  {
    tiempo_anterior_led = tiempo;
    estado_led = !estado_led;
    digitalWrite(LED, estado_led);
  }
}

// parpadea un led a una frecuencia 
// determinada por la macro FREQ
// para cambiar la frecuencia solamente
// cambie la macro
#define LED_PIN 13
#define FREQ 10 // <-- cambiar esto! (Hz)
#define TIEMPO 500 / FREQ // (ms)
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, 1);
  delay(TIEMPO);
  digitalWrite(LED_PIN, 0);
  delay(TIEMPO);
}

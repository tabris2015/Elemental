// definiciones de pines y constantes
#define LED 13
#define BOTON 2
#define FREQ1 2
#define FREQ2 6
#define FREQ3 18
#define __TIME(f) 500/f  // macro para obtener medio periodo
#define TIME_MSG 10000    // intervalo para mandar el mensaje

volatile int cnt = 0;
volatile int modo = 0;
int estadoLed = 1;
const long tiempos[3] = {__TIME(FREQ1), __TIME(FREQ2), __TIME(FREQ3)};
volatile long periodo = tiempos[0];
long tiempo_ant_led = 0;
long tiempo_ant_msg = 0;
// funcion de interrupcion
void buttonISR()
{
  cnt++;              // incrementamos contador
  if(++modo > 2)      // aseguramos que no pase de 2
  {
    modo = 0;
  }
  periodo = tiempos[modo];  // actualizamos periodo
}

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BOTON), buttonISR, RISING);
  Serial.begin(9600);
}
void loop()
{
  // verificamos el tiempo para parpadear el led
  if((millis()-tiempo_ant_led) > periodo)
  {
    tiempo_ant_led = millis();    // actualizamos tiempo anterior
    estadoLed = !estadoLed;
    digitalWrite(LED, estadoLed);
  }
  // verificamos el tiempo para enviar el mensaje
  if((millis() - tiempo_ant_msg) > TIME_MSG)
  {
    tiempo_ant_msg = millis();    // actualizamos tiempo anterior
    Serial.println(cnt);
    cnt = 0; // reiniciamos contador
  }
}

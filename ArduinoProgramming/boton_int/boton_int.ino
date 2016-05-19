#define LED_PIN 13
#define BOTON_PIN 2

volatile int retardo = 500;

void cambioRetardo()
{
	retardo = retardo - 50;
	if(retardo < 0)
	{
		retardo = 500;
	}
}

void setup()
{
	pinMode(LED_PIN, OUTPUT);
	pinMode(BOTON_PIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(BOTON_PIN), cambioRetardo, RISING);
}
void loop() {
  digitalWrite(LED_PIN, 1);
  delay(retardo);
  digitalWrite(LED_PIN, 0);
  delay(retardo);
}
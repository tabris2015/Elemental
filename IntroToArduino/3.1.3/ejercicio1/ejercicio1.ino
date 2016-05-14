#define LED_PIN 13
#define BOTON_PIN 12
int estado;
int estado_ant;
int bandera = 0;
void setup()
{
	pinMode(LED_PIN, OUTPUT);
	pinMode(BOTON_PIN, INPUT_PULLUP);
}
void loop()
{
	estado = digitalRead(BOTON_PIN);
	if(estado != estado_ant)
	{
		if(estado == 1)
		{
			bandera = !bandera;
		}
	}
	digitalWrite(LED_PIN, bandera);
	estado_ant = estado;
	delay(50);
}

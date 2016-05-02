#define IN1 5
#define IN2 4
#define ENA 9
#define BOT_PIN 12

int estado;
int estado_ant;
int acumulador = 0;
int velocidad; // 

void setup()
{
	pinMode(BOT_PIN, INPUT_PULLUP);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);

	digitalWrite(IN1, 0);
	digitalWrite(IN2, 1);

}
void loop()
{
	estado = digitalRead(BOT_PIN);
	if(estado != estado_ant && estado == 1)
	{
		acumulador++;
		if(acumulador > 10)
		{
			acumulador = 0;
		}
	}
	velocidad = acumulador * 25;
	analogWrite(ENA, velocidad);

	estado_ant = estado;
	delay(50);
}
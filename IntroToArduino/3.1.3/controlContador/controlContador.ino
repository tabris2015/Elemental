#define LED_PIN 13
#define IN1 5
#define IN2 4
#define BOTON_PIN 12
int estado;
int estado_ant;
int modo = 0;
int contador = 0;
void setup()
{
	pinMode(LED_PIN, OUTPUT);
	pinMode(BOTON_PIN, INPUT_PULLUP);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	Serial.begin(9600);
}
void loop()
{
	estado = digitalRead(BOTON_PIN);
	if(estado != estado_ant)
	{
		if(estado == 1)
		{
			contador = contador + 1;
			Serial.println(contador);
			if(modo == 0)
			{
				if(contador > 2)
				{
					modo = 1;
					contador = 0;
					Serial.println("entrando modo 1");
				}
			}
			else if(modo == 1)
			{
				if(contador > 2)
				{
					modo = 2;
					contador = 0;
					Serial.println("entrando modo 2");
				}
			}
			else if(modo == 2)
			{
				if(contador > 1)
				{
					modo = 0;
					contador = 0;
					Serial.println("entrando modo 0");
				}
			}
		}
	}

	if(modo == 0) // detener
	{
		digitalWrite(IN1, 0);
		digitalWrite(IN2, 0);
	}
	else if(modo == 1) // adelante
	{
		digitalWrite(IN1, 0);
		digitalWrite(IN2, 1);	
	}
	else if(modo == 2) // atras
	{
		digitalWrite(IN1, 1);
		digitalWrite(IN2, 0);
	}
	else
	{
		digitalWrite(IN1, 0);
		digitalWrite(IN2, 0);
	}

	estado_ant = estado;
	delay(50);
}

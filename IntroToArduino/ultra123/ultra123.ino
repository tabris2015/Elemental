#include <NewPing.h>
#define TRIG_PIN 10
#define ECHO_PIN 9
#define LED_PIN 13
#define LEJANO (distancia > 40)
#define MEDIO (distancia <= 40 && distancia > 20)
#define CERCANO (distancia != 0 && distancia <= 20)
int distancia;
long tiempo_anterior;
long tiempo;
NewPing sensor(TRIG_PIN, ECHO_PIN, 200);
void setup()
{
	Serial.begin(9600);
}
void loop()
{
	// lectura del sensor
	distancia = sensor.ping_cm();

	if(LEJANO)
	{
		//parpadeas lento
		digitalWrite(LED_PIN, 1);
		delay(500);
		digitalWrite(LED_PIN, 0);
		delay(500);
	}
	else if(MEDIO)
	{
		//parpadeas rapido-
		digitalWrite(LED_PIN, 1);
		delay(150);
		digitalWrite(LED_PIN, 0);
		delay(150);
	}
	else if(CERCANO)
	{
		// te quedas encendido
		digitalWrite(LED_PIN, 1);
	}
}

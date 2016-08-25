#include "Arduino.h"
#include "Parpadeador.h"
Parpadeador::Parpadeador(int pin, long inter)
{
	ledPin = pin;
	pinMode(ledPin, OUTPUT);
	intervalo = inter;
	estado = 0;
	tiempo_ant = 0;
}
void Parpadeador::Actualizar()
{
	long tiempo = millis();
	if((tiempo - tiempo_ant) > intervalo)
	{
		tiempo_ant = tiempo;
		estado = !estado;
		digitalWrite(ledPin, estado);
	}	
}
void Parpadeador::CambiarIntervalo(long nItervalo)
{
	intervalo = nItervalo;
}
long Parpadeador::Intervalo()
{
	return intervalo;
}
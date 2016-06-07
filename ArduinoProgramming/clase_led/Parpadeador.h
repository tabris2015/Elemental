#ifndef PARPADEADOR_H
#define PARPADEADOR_H

class Parpadeador
{
	int ledPin;
	long intervalo;
	int estado;
	long tiempo_ant;
public:
	Parpadeador(int pin, long inter);
	void Actualizar();
};

#endif
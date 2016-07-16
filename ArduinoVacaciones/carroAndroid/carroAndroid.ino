#include <Elemental.h>
ElementalMotors carro;
char comando; // variable que almacena el comando que
			  // llega del puerto serial (bluetooth)

void setup()
{
	Serial.begin(9600);
	Serial.println("a sus ordenes!");
}
void loop()
{
	// medicion de los sensores
	if(Serial.available())
	{
		comando = Serial.read();
	}

	//--------------------------
	// W -> adelante
	if(comando == 'W')
	{
		carro.conducir(100);
	}
	// A -> izquierda
	else if(comando == 'A')
	{
		carro.motorDerecho(100);
	}
	// S -> atras
	else if(comando == 'S')
	{
		carro.conducir(-100);
	}
	// D -> derecha
	else if(comando == 'D')
	{
		carro.motorIzquierdo(100);
	}
	// T -> detener
	else if(comando == 'T')
	{
		carro.detener();
	}
	else
	{
		carro.detener();
	}
	delay(100);
}
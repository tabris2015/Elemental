#include <RedBot.h>
// variable que almacena el comando llegado del puerto serial
char comando; 

RedBotMotors carro;

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
		carro.drive(100);
	}
	// A -> izquierda
	else if(comando == 'A')
	{
		carro.rightMotor(100);
	}
	// S -> atras
	else if(comando == 'S')
	{
		carro.drive(-100);
	}
	// D -> derecha
	else if(comando == 'D')
	{
		carro.drive(-100);
	}
	// T -> detener
	else if(comando == 'T')
	{
		carro.drive(-100);
	}
	else
	{
		carro.stop();
	}
	
	delay(100);

}
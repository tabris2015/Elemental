#include <RedBot.h>
#define SENS_IZQ A0
#define SENS_CEN A1
#define SENS_DER A2

#define IZQ_ES_NEGRO (med_izq == 1)
#define CEN_ES_NEGRO (med_cen == 1)
#define DER_ES_NEGRO (med_der == 1)

#define UMBRAL 700
// variables que almacenan las lecturas
int med_izq;
int med_cen;
int med_der;

RedBotMotors carro;

void setup()
{
	Serial.begin(9600);
}
void loop()
{
	// medicion de los sensores
	med_izq = analogRead(SENS_IZQ) >= UMBRAL ? 1 : 0;
	med_cen = analogRead(SENS_CEN) >= UMBRAL ? 1 : 0;
	med_der = analogRead(SENS_DER) >= UMBRAL ? 1 : 0;
	//--------------------------
	if(!IZQ_ES_NEGRO && CEN_ES_NEGRO && !DER_ES_NEGRO)
	{
		carro.drive(100);
		Serial.println("adelante!");
	}
	else if(IZQ_ES_NEGRO && !CEN_ES_NEGRO && !DER_ES_NEGRO)
	{
		// moverme a la izquierda
		carro.rightMotor(100);
		Serial.println("izquierda!");	
	}
	else if(IZQ_ES_NEGRO && CEN_ES_NEGRO && !DER_ES_NEGRO)
	{
		// moverme a la izquierda rapido
		carro.rightMotor(255);
		Serial.println("izquierda!");	
	}
	else
	{
		carro.stop();
	}
	delay(100);

}








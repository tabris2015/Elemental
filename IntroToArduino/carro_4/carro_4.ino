#include <RedBot.h>
#include <NewPing.h>

#define TRIG_IZQ 12
#define ECHO_IZQ 11
#define TRIG_DER 10
#define ECHO_DER 9

#define OBS_IZQ (med_izq == 1)
#define OBS_DER (med_der == 1)

#define UMBRAL 10  // umbral de distancia
// variables que almacenan las lecturas
int med_izq;
int med_der;

RedBotMotors carro;
NewPing sonarIzq(TRIG_IZQ, ECHO_IZQ, 100);
NewPing sonarDer(TRIG_DER, ECHO_DER, 100);

void setup()
{
	Serial.begin(9600);
}
void loop()
{
	// medicion de los sensores
	med_izq = sonarIzq.ping_cm() <= UMBRAL ? 1 : 0;
	med_der = sonarDer.ping_cm() <= UMBRAL ? 1 : 0;
	//--------------------------
	if(!OBS_IZQ && !OBS_DER)
	{
		carro.drive(100);
		Serial.println("adelante!");
	}
	else if(!OBS_IZQ && OBS_DER)
	{
		// moverme a la izquierda
		carro.rightMotor(100);
		Serial.println("izquierda!");	
	}
	else
	{
		carro.stop();
	}
	delay(100);

}








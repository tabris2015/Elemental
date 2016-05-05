#include <RedBot.h>
#define SENS_IZQ A0
#define SENS_CEN A1
#define SENS_DER A2

#define VEL1 100
#define VEL2 150
#define VEL3 200
#define VEL4 255

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
	med_izq = analogRead(SENS_IZQ); // >= UMBRAL ? 1 : 0;
	med_cen = analogRead(SENS_CEN); // >= UMBRAL ? 1 : 0;
	med_der = analogRead(SENS_DER); // >= UMBRAL ? 1 : 0;
	//--------------------------
  Serial.print(med_izq);
  Serial.print("--");
  Serial.print(med_cen);
  Serial.print("--");
  Serial.println(med_der);

  med_izq = med_izq > UMBRAL ? 1 : 0;
  med_cen = med_cen > UMBRAL ? 1 : 0;
  med_der = med_der > UMBRAL ? 1 : 0;
  //      0               1               0 
	if(!IZQ_ES_NEGRO && CEN_ES_NEGRO && !DER_ES_NEGRO)
	{
		carro.drive(VEL1);
		Serial.println("adelante!");
	}
  //           1               0               0 
	else if(IZQ_ES_NEGRO && !CEN_ES_NEGRO && !DER_ES_NEGRO)
	{
		// moverme a la izquierda
		carro.pivot(-VEL3);
		Serial.println("izquierda!");	
	}
  //           0              0               1 
  else if(!IZQ_ES_NEGRO && !CEN_ES_NEGRO && DER_ES_NEGRO)
  {
    // moverme a la izquierda
    carro.pivot(VEL3);
    Serial.println("derecha"); 
  }
	//           1               1               0 
  else if(IZQ_ES_NEGRO && CEN_ES_NEGRO && !DER_ES_NEGRO)
	{
		// moverme a la izquierda rapido
		carro.pivot(-VEL4);
		Serial.println("izquierda!");	
	}
  //           0               1               1 
  else if(!IZQ_ES_NEGRO && CEN_ES_NEGRO && DER_ES_NEGRO)
  {
    // moverme a la izquierda rapido
    carro.pivot(VEL4);
    Serial.println("der!"); 
  }
  //           0               0               0 
  else if(!IZQ_ES_NEGRO && !CEN_ES_NEGRO && !DER_ES_NEGRO)
  {
    // moverme a la izquierda rapido
    carro.drive(VEL1);
    Serial.println("perdido"); 
  }
	else
	{
		carro.stop();
	}
	delay(50);

}








#include <RedBot.h>
// variable que almacena el comando llegado del puerto serial
int vIzq;
int vDer;
int thrash;
RedBotMotors carro;

void setup()
{
	Serial.begin(9600);
	Serial.println("a sus ordenes!");
}
void loop()
{
	// medicion de los sensores
	while(Serial.available() && Serial.read() != '\n')
	{
		vIzq = Serial.parseInt();
    thrash = Serial.parseInt();
   
		vDer = Serial.parseInt();
	}
	//-----
	Serial.print(vIzq);
	Serial.print("---");
	Serial.println(vDer);
	//-----
	carro.rightMotor(vDer);
	carro.leftMotor(vIzq);

	delay(100);

}

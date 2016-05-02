#include <Servo.h>
#define BOTON_PIN 2
#define SERVO_PIN 9
#define LED_PIN 13
int estado;
int estado_ant = 1;
int modo = 0;	// define la velocidad del motor	
int retardo = 10;
Servo miServo;
void setup()
{
	pinMode(LED_PIN, OUTPUT);
	pinMode(BOTON_PIN, INPUT_PULLUP);
	miServo.attach(SERVO_PIN);
  	miServo.write(0);
	Serial.begin(9600);
  	Serial.println("iniciando...");
  	Serial.print("modo inicial: ");
  	Serial.println(modo);  	
}
void loop()
{	
	
	for(int i = 0; i <= 180; i++)
	{
      	estado = digitalRead(BOTON_PIN);
		if(estado != estado_ant)
		{
			if(estado == 1)
			{
				modo++;
				modo = modo > 2 ? 0 : modo;
				Serial.print("modo: ");
				Serial.println(modo);
			}
		}
		if(modo != 0)
		{
			retardo = modo*10 + 2;
          	miServo.write(i);
			delay(retardo);
		}
    	estado_ant = estado; 
	}
	for(int i = 180; i >= 0; i--)
	{
		estado = digitalRead(BOTON_PIN);
		if(estado != estado_ant)
		{
			if(estado == 1)
			{
				modo++;
				modo = modo > 2 ? 0 : modo;
				Serial.print("modo: ");
				Serial.println(modo);
			}
		}
		if(modo != 0)
		{
			retardo = modo*10 + 2;
          	miServo.write(i);
			delay(retardo);
		}
    	estado_ant = estado; 
	}
}

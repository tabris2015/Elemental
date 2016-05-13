#include <Servo.h>
#define SERVO_PIN 9
#define BOTON_PIN 12

Servo limpiador;
// variables para el estado del boton
int estado;
int estado_ant = 1;

long ult_tiempo;  // tiempo del cambio
long tiempo_rebote = 50; // tiempo del rebote

int modo = 0;
// variables para el servo
long delay_servo = 10;
long tiempo_ant_servo;
int pos = 0;
int sentido = 1;

void setup() {
	pinMode(BOTON_PIN, INPUT_PULLUP);
	limpiador.attach(SERVO_PIN);
	Serial.begin(9600);
}
void loop() {
	// lectura del boton
	int lectura = digitalRead(BOTON_PIN);
  // verificar el cambio y almacenar el tiempo
  if(lectura != estado_ant)  
  {
  	ult_tiempo = millis();
  	Serial.println("cambio");
  }
  if((millis() - ult_tiempo) > tiempo_rebote)
  { 
  	if(lectura != estado)
  	{
  		estado = lectura;
  		Serial.println("cambio de estado");
	  	if(estado == 1) // borde de subida
	  	{
	  		modo++;
	  		if(modo > 2)
	  		{
	  			modo = 0;
	  		}

	  		if(modo == 1) // rapido
	  		{
	  			delay_servo = 10;
	  		}
	  		else if(modo == 2) // lento
	  		{
	  			delay_servo = 25;
	  		}
	  		Serial.println(modo);
	  	}
  	}
  	
  }
  // servo 
  if((millis() - tiempo_ant_servo) > delay_servo)
  {
  	tiempo_ant_servo = millis(); // actualizando el tiempo
  	
  	if(modo != 0)
  	{
  		
  		if(sentido == 1) // adelante
  		{
  			pos++;
  			if(pos == 180)
  			{
  				sentido = 0;
  			}
  		}
  		else 
  		{
  			pos--;
  			if(pos == 0)
  			{
  				sentido = 1;
  			}
  		}
  		limpiador.write(pos);
  	}
  	else
  	{
  		limpiador.write(0);
  		pos = 0;
  		sentido = 1;
  	}
  	
  }

  estado_ant = lectura;
}

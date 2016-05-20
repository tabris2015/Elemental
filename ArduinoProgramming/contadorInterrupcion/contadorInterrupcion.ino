#include <Servo.h>
#define BOTON_PIN 2
#define SERVO_PIN 9
#define LED_PIN 13

#define PERIODO 2000

volatile int contador = 0;
long tiempo_ant;
long tiempo;
Servo miServo;
void setup()
{
	pinMode(LED_PIN, OUTPUT);
	pinMode(BOTON_PIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(BOTON_PIN), actualizarContador, RISING);
	miServo.attach(SERVO_PIN);
  	miServo.write(0);
	
	// secuencia inicial
  	secuenciaInicial();

}
void loop()
{	
  tiempo = millis();
  if((tiempo - tiempo_ant) > PERIODO)
  {
  	tiempo_ant = tiempo;
  	if(contador >= 6)
  	{
  		miServo.write(180);
  		contador = 0;
  	}
  	else
  	{
  		miServo.write(90);
  		contador = 0;
  	}
  }
	
}

void actualizarContador(void)
{
	contador ++;	
}

void secuenciaInicial()
{

	digitalWrite(LED_PIN, 1);
	delay(1000);
	digitalWrite(LED_PIN, 0);
	delay(1000);
	digitalWrite(LED_PIN, 1);
	delay(1000);
	digitalWrite(LED_PIN, 0);
	delay(1000);
	digitalWrite(LED_PIN, 1);
	delay(1000);
	digitalWrite(LED_PIN, 0);
	delay(1000);
	digitalWrite(LED_PIN, 1);
}
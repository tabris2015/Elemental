#include <NewPing.h>
#include <EEPROM.h>
#define LED_PIN 13
#define TRIG_PIN 12
#define ECHO_PIN 11
#define FAULT_SWITCH 2
#define MAX_DIST 300
#define INTERVALO 1000
#define UMBRAL 15
NewPing sensor(TRIG_PIN, ECHO_PIN, MAX_DIST);

struct fault_data_t
{
	int distancia;
	long tiempo;
};


int distancia;
long tiempo_ant;
int dir = 0;
volatile int flag = 0;
void falla()
{
  flag = 1;	
}
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(FAULT_SWITCH, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(FAULT_SWITCH), falla, FALLING);
  Serial.begin(9600);
  //-------
  fault_data_t last_fault_data;
  EEPROM.get(dir, last_fault_data);
  Serial.print("ultima lectura: ");
  Serial.println(last_fault_data.distancia);
  Serial.print("tiempo: ");
  Serial.println(last_fault_data.tiempo);
  
  //-------
}
void loop() {
  if(flag) // si hay una falla
  {
  	fault_data_t fault_data;
  	fault_data.distancia = sensor.ping_cm();
  	fault_data.tiempo = millis();
  	EEPROM.put(dir, fault_data);

  	while(1)
  	{
  		Serial.println("FALLA!");
  		delay(2000);
  	}
  }

 long tiempo = millis();
 if((tiempo - tiempo_ant) > INTERVALO)
 {
 	tiempo_ant = tiempo;
 	distancia = sensor.ping_cm();
 	Serial.print("distancia: ");
 	Serial.println(distancia);
 	if(distancia == 0)
 	{
 		distancia = MAX_DIST;
 	}

 	if(distancia < UMBRAL)
 	{
 		digitalWrite(LED_PIN, 1);
 	}
 	else
 	{
 		digitalWrite(LED_PIN, 0);
 	}
 }
}
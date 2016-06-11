// link del circuito https://123d.circuits.io/circuits/2315075-circuito-multitareas
#include <Servo.h>
#define LED 13
#define LED_EXT 8
#define SERVO_PIN 9
#define FREQ_LED 2
#define FREQ_LED_EXT 10
#define T_LED 500/FREQ_LED
#define T_LED_EXT 500/FREQ_LED_EXT
#define T_MSG 5000
#define T_PUERTA 2000
Servo puerta;
// paso 1
long tiempo_ant_led;
long tiempo_ant_led_ext;
long tiempo_ant_msg;
long tiempo_ant_puerta;
int estado_led = 0;
int estado_led_ext = 0;
int estado_puerta = 0;
int sentido = 0; // 0 adelante, 1 atras
// variables
long tiempo_tarea;
long tiempo_max = 0;
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED_EXT, OUTPUT);
  puerta.attach(SERVO_PIN);
  Serial.begin(9600);
}
void loop() {
  // paso 2 		* global
  long tiempo = millis();
  long t_aux = micros();
  // paso 3
  if((tiempo - tiempo_ant_led) > T_LED)
  {
  	// paso 4
  	tiempo_ant_led = tiempo;
  	// paso 5
  	estado_led = !estado_led;
  	digitalWrite(LED, estado_led);
  	
  }
  // paso 3
  if((tiempo - tiempo_ant_led_ext) > T_LED_EXT)
  {
  	// paso 4
  	tiempo_ant_led_ext = tiempo;
  	// paso 5
  	estado_led_ext = !estado_led_ext;
  	digitalWrite(LED_EXT, estado_led_ext);
  }
  // paso 3
  if((tiempo - tiempo_ant_msg) > T_MSG)
  {
  	// paso 4
  	tiempo_ant_msg = tiempo;
  	// paso 5
  	Serial.println("hola! ya pasaron 5 segundos!");
  }
  if((tiempo - tiempo_ant_puerta) > T_PUERTA)
  {
  	// paso 4
  	tiempo_ant_puerta = tiempo;
  	// paso 5
  	if(sentido == 0) // yendo adelante
  	{
  		estado_puerta++;
  		if(estado_puerta == 10)
  		{
  			sentido = 1; // ir para atras
  		}
  	}
  	else
  	{
  		estado_puerta--;
  		if(estado_puerta == 0)
  		{
  			sentido = 0; // ir para atras
  		}	
  	}

  	puerta.write(estado_puerta*18);

  }
  tiempo_tarea = micros() - t_aux;
  if(tiempo_tarea > tiempo_max)
  {
  	tiempo_max = tiempo_tarea;
  	Serial.println(tiempo_tarea);
  }
}
#include <Servo.h>
// definicion de pines
#define BOT_PIN 10
#define LED 13
// constantes util+es
#define INTERVALO 300   // intervalo de actualizacion de la aguja
#define TIEMPO 20000    // tiempo de juego en milisegundos
#define FACTOR 25       // factor para el servo
// definicion de variables
long tiempo;
long tiempo_ant;
long tiempo_inicial;
int estado;
int estado_ant;
int contador = 0;
int max_speed = 0;      // almacenamos la maxima velocidad

Servo aguja;
void setup() {
  aguja.attach(9);
  aguja.write(0);
  pinMode(BOT_PIN, INPUT_PULLUP);
  pinMode(LED,OUTPUT);
  // secuencia inicial
  digitalWrite(LED, 0);
  delay(1000);
  digitalWrite(LED, 1);
  delay(1000);
  digitalWrite(LED, 0);
  delay(1000);
  digitalWrite(LED, 1);
  delay(1000);
  digitalWrite(LED, 0);
  delay(1000);
  digitalWrite(LED, 1);
  delay(1000);
  digitalWrite(LED, 0);
  delay(1000);
  digitalWrite(LED, 1);
  // inicia el juego
  tiempo_inicial = millis();
  
}

void loop() {
  // verifica si hay cambios de estado
  // e incrementa un contador
  estado = digitalRead(BOT_PIN);
  if(estado != estado_ant)
  {
    if(estado == HIGH)
    {
      contador++;
    }
  }
  // verifica el intervalo para actualizar la aguja
  tiempo = millis();
  if(tiempo - tiempo_ant > INTERVALO)
  {
    tiempo_ant = tiempo;
    if(contador > max_speed)
    {
      max_speed = contador; // guardamos la maxima velocidad
    }
    aguja.write(contador*FACTOR);
    contador = 0;
  }
  else if(tiempo - tiempo_inicial > TIEMPO)
  { 
    digitalWrite(LED, 0);
    delay(1000);
    aguja.write(0);
    delay(1000);
    aguja.write(180);
    delay(1000);
    for(int i = 0; i < max_speed*FACTOR; i++)
    {
      aguja.write(i);
      delay(50);
    }
    digitalWrite(LED, 1);
    while(1)
    {
      
    }
  }
  estado_ant=estado;
}

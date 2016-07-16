#include <Servo.h>
#include <LiquidCrystal.h>
#define DEC_VEL 3   
#define INC_VEL 2
#define SERVO_PIN 10

#define T_TAREA3 200
#define T_TAREA4 500
// para el lcd    RS   E  D4 D5 D6 D7
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
long tiempo_ant_lcd;
// para el servo
Servo barra;
int pos = 0;
long tiempo_ant;
volatile long periodo = 10;
int sentido = 0;
// para los botones
volatile int modo = 0;
// para el potenciometro 
int valor;
long tiempo_ant_pot;
// rutinas de interrupcion
void incVelocidad()
{
  periodo--;
  if(modo == 0) modo = 1; // motor detenido
  if(periodo < 0) periodo = 0;
}
void decVelocidad()
{
  periodo++;
  if(periodo > 50) // parar motor
  {
    periodo = 50;
    modo = 0;
  }
}
void setup() {
  pinMode(DEC_VEL, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(DEC_VEL), decVelocidad, RISING);
  pinMode(INC_VEL, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INC_VEL), incVelocidad, RISING);
  barra.attach(SERVO_PIN);
  lcd.begin(16, 2);
  lcd.print("hola");
  delay(1000);
}
void loop() {
  // leemos el tiempo actual
  long tiempo = millis();
  // verificamos si el periodo se ha cumplido
  // TAREA 2
  if(((tiempo - tiempo_ant) >= periodo) && modo != 0)
  {
  	// actualizamos el tiempo
  	tiempo_ant = tiempo;
  	// realizamos la tarea
  	if(sentido == 0)
  	{
  	  pos++;
  	  if(pos == 180) sentido = 1;
  	}
  	else
  	{
  	  pos--;
  	  if(pos == 0) sentido = 0;
  	}
  	barra.write(pos);
  }
  // TAREA 3
  if((tiempo - tiempo_ant_pot) >= T_TAREA3)
  {
    tiempo_ant_pot = tiempo;
    valor = analogRead(A0);
  }
  // TAREA 4
  if((tiempo - tiempo_ant_lcd) >= T_TAREA4)
  {
    tiempo_ant_lcd = tiempo;
    // imprimir la pos
    lcd.setCursor(0,0);
    lcd.print("pos: ");
    lcd.print(pos);
    // imprimir la vel
    lcd.setCursor(9,0);
    lcd.print("vel: ");
    lcd.print(periodo);
    // imprimir el valor
    lcd.setCursor(0,1);
    lcd.print("Vin: ");
    lcd.print(valor);
  }
}
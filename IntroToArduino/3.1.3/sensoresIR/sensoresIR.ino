#include <Servo.h>
// definicion de pines
#define LED_PIN 13
#define SENS_IZQ_PIN 7
#define SENS_CEN_PIN 6
#define SENS_DER_PIN 5
#define SERVO_PIN 9

#define BLANCO 0
#define NEGRO 1
Servo aguja; // crear servo
// variables para las lecturas
int medIzq, medCen, medDer;
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(SENS_IZQ_PIN, INPUT);
  pinMode(SENS_CEN_PIN, INPUT);
  pinMode(SENS_DER_PIN, INPUT); 
  aguja.attach(SERVO_PIN);
}
void loop() {
  // medicion de sensores
  medIzq = digitalRead(SENS_IZQ_PIN);
  medCen = digitalRead(SENS_CEN_PIN);
  medDer = digitalRead(SENS_DER_PIN);

  if (medIzq == BLANCO && medCen == NEGRO && medDer == NEGRO)
  {
  	aguja.write(120);
  }
  else if(medIzq == NEGRO && medCen == BLANCO && medDer == NEGRO)
  {
  	aguja.write(90);
  }
  else if(medIzq == NEGRO && medCen == NEGRO && medDer == BLANCO)
  {
  	aguja.write(60);
  }
  else
  {
  	aguja.write(90);
  }
  delay(1000);
}
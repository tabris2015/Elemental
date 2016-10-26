#include <NewPing.h>
#include <Elemental.h>

#define TRIG A4
#define ECHO A5
#define IZQ_PIN A0
#define DER_PIN A1
#define UMBRAL_DER 500
#define UMBRAL_IZQ 500

NewPing dist(TRIG, ECHO, 50);

ElementalMotors carro;
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int distancia = dist.ping_cm();
  distancia = distancia == 0 ? 50 : distancia;

  int izq = analogRead(IZQ_PIN);
  int der = analogRead(DER_PIN);
  int code = (der > UMBRAL_DER) | ((izq > UMBRAL_IZQ)<<1);
  
  Serial.print("distancia: ");
  Serial.print(distancia);
  Serial.print(" izquierda: ");
  Serial.print(izq);
  Serial.print(" derecha: ");
  Serial.print(der);
  Serial.print(" codigo: ");
  Serial.println(code, BIN);
  
  
}

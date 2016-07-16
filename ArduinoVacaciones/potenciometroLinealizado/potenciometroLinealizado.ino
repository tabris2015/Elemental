#include <Servo.h>
#define SERVO_PIN 9
#define POT_PIN A0
Servo aguja;
int valor;
float voltaje;
int angulo;
void setup() {
  aguja.attach(SERVO_PIN);
  Serial.begin(9600);
}
void loop() {
  valor = analogRead(POT_PIN);
  voltaje = 0.0048 * valor;
  angulo = -6.8904*(voltaje * voltaje) + 71.155 * voltaje - 3.5819;
  aguja.write(angulo);
  Serial.print("voltaje: ");
  Serial.print(voltaje);
  Serial.print("[V]");
  Serial.print("  angulo: ");
  Serial.print(angulo);
  Serial.println(" grados");
}
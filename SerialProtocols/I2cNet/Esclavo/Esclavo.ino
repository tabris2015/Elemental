#include <Wire.h>
#include <Servo.h>
#define SENSOR_LUZ A0
#define SERVO_PIN 8
unsigned int lectura;
// PARA EL SERVO
Servo miMotor;
long t_ant_servo;
int pos_ant = 0;
int pos_des = 90;
long intervalo = 50;
int datosIn[50];
void setup() {
  miMotor.attach(SERVO_PIN);
  Wire.begin(9);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}
void loop() {
  long tiempo = millis();
  if((tiempo - t_ant_servo) > intervalo)
  {
    t_ant_servo = tiempo;
    //
    if(pos_des > pos_ant)
    {
      pos_ant++;
    }
    else if(pos_des < pos_ant)
    {
      pos_ant--;
    }
    miMotor.write(pos_ant);
  }  
}
// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  lectura = analogRead(SENSOR_LUZ)>>2;
  Wire.write(lectura);
  Serial.print("lectura: ");
  Serial.println(lectura);
}
void receiveEvent(int howMany) {
  int i = 0;
  while (0 != Wire.available()) { // loop through all but the last
    datosIn[i] = Wire.read(); // receive byte as a character
    Serial.println(datosIn[i]);
    i++;         // print the character
  }
  pos_des = datosIn[0];
  intervalo = datosIn[1];
}

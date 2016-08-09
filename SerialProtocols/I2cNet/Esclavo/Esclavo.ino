#include <Wire.h>
#include <Servo.h>
#define SENSOR_LUZ A0
#define SERVO_PIN 8
int lectura;
// PARA EL SERVO
Servo miMotor;
long t_ant_servo;
int pos_ant = 0;
int pos_des;
long intervalo = 50;
int datosIn[50];
void setup() {
  Wire.begin(9);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Wire.onReceive(receiveEvent);
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
  lectura = analogRead(SENSOR_LUZ);
  uint8_t lecBaja = lectura & 0xFF;
  uint8_t lecAlta = (lectura >> 8) & 0xFF;
  Wire.write(lecBaja); // respond with message of 6 bytes
  Wire.write(lecAlta); // respond with message of 6 bytes
  // as expected by master
}
void receiveEvent(int howMany) {
  int i = 0;
  while (1 < Wire.available()) { // loop through all but the last
    datosIn[i] = Wire.read(); // receive byte as a character
    i++;         // print the character
  }
  pos_des = datosIn[0];
  intervalo = datosIn[1];
}

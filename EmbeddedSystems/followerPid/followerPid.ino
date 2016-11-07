#include <Follower.h>
#include "defines.h"
SensorArray sensors;
Motors robot(L_PWM, L_CTRL1, L_CTRL1, R_PWM, L_CTRL1, L_CTRL1);

const float kp = 2.0;
const float ki = 0.56;
const float kd = 1.0;

uint16_t ts = 10;
unsigned long lastTime;
float setpoint = 0;
float input;
float output;

pid headingController(&input, &output, &setpoint, kp, ki, kd);

void setup() {
  #ifdef DEBUG
  Serial.begin(38400);
  Serial.println("seguidor de linea con pid");
  #endif
  headingController.SetSampleTime(ts);
  lastTime = millis();
}
void loop() {
  
  if((millis() - lastTime) > ts)
  {
    lastTime = millis();

    sensors.Update();
    input = (float)sensors.getPosition();
    int16_t heading = headingController.Compute();
    #ifdef DEBUG
      Serial.print("port: ");
      Serial.print(PINC, BIN);
      Serial.print(" raw: ");
      Serial.print(sensors.getRaw(), BIN);
      Serial.print(" density: ");
      Serial.print(sensors.getDensity());
      Serial.print(" position: ");
      Serial.print(sensors.getPosition());
      Serial.print(" output: ");
      Serial.println(heading);
    #endif
  }
  
}

#include <Follower.h>
#include "defines.h"
SensorArray sensors;
Motors robot(L_PWM, L_CTRL1, L_CTRL1, R_PWM, L_CTRL1, L_CTRL1);


void setup() {
  Serial.begin(38400);  
}
void loop() {
  sensors.Update();
  #ifdef DEBUG
    Serial.print("port: ");
    Serial.print(PINC, BIN);
    Serial.print(" raw: ");
    Serial.print(sensors.getRaw(), BIN);
    Serial.print(" density: ");
    Serial.print(sensors.getDensity());
    Serial.print(" position: ");
    Serial.println(sensors.getPosition());
  #endif
  
  
  delay(500);
}

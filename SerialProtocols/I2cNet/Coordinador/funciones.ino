// Example function A1
void LeerSensor(void)
{
  unsigned int lectura = 0;
  //
  uint16_t lecturas[2];
  int i = 0;
  Wire.requestFrom(esclavoAct, 2);
  lecturas[0] = Wire.read();
  //lecturas[1] = Wire.read();
  Serial.println(lecturas[0]);
  //Serial.println(lecturas[1]);
  /*
  while (Wire.available()) { // slave may send less than requested
    lecturas[i] = Wire.read(); // receive a byte as character
    i++;
    Serial.println(lecturas[i]);
  }
  */

  Serial.println(lectura);
}
// Example function A1
void MoverMotor(char *pos, char *vel)
{
  // Convert property to int
  uint8_t posicion = atoi(pos);  
  // Convert period to int
  uint8_t velocidad = atoi(vel);
  // enviar por I2C
  Serial.print("pos: ");
  Serial.println(posicion);
  Serial.print(" vel: ");
  Serial.println(velocidad);  
  Wire.beginTransmission(esclavoAct); // transmit to device #8
  Wire.write(posicion);        // sends five bytes
  Wire.write(velocidad);              // sends one byte
  Wire.endTransmission();    // stop transmitting
}

void SelEsclavo(char *dir)
{
  // Convert property to int
  int direccion = atoi(dir);  
  Serial.print("seleccion del esclavo: ");
  Serial.println(direccion);
  esclavoAct = direccion;
}



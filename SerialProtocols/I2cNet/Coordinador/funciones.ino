// Example function A1
void LeerSensor(void)
{
  int lectura = 0;
  //
  int i = 0;
  Wire.requestFrom(esclavoAct, 2);
  while (Wire.available()) { // slave may send less than requested
    lectura += Wire.read() << 8 * i; // receive a byte as character
    i++;
  }
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
  Serial.println("moviendo motor");
  Wire.beginTransmission(esclavoAct); // transmit to device #8
  Wire.write(pos);        // sends five bytes
  Wire.write(vel);              // sends one byte
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



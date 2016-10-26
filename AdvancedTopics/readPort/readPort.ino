#define PD2_MASK 0x04
void setup() {
  DDRD = DDRD & (~PD2_MASK); // PD2 como entrada
  Serial.begin(9600);
}
void loop() {
  uint8_t puertoD;
  puertoD = PIND;
  Serial.println(puertoD, BIN);
}
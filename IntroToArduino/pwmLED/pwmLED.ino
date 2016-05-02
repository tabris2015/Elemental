#define LED 9
int brillo;
void setup() {
}
void loop() {
  for(brillo = 0; brillo <=255; brillo++)
  {
    analogWrite(LED, brillo);
    delay(15);   
  }
  for(brillo = 255; brillo >= 0; brillo--)
  {
    analogWrite(LED, brillo);
    delay(15);
  }
}

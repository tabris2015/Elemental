// mascaras
#define PB5_MASK 0x20
#define PB1_MASK 0x02
#define INT1 600
#define INT2 1000
long t_led1, t_led2;
int e_led1 = 0;
int e_led2 = 0;
void setup() {
  // configuracion de la direccion del puerto B5
  DDRB = 0x22; // 0b00100010
}
void loop() {
  long t = millis();
  if((t - t_led1) > INT1)
  {
  	t_led1 = t;
  	e_led1 = !e_led1;
  	// magia
  	PORTB = e_led1 ? PORTB | PB5_MASK : PORTB & (~PB5_MASK);

  }
  if((t - t_led2) > INT2)
  {
  	t_led2 = t;
  	e_led2 = !e_led2;
  	// magia
  	PORTB = e_led1 ? PORTB | PB1_MASK : PORTB & (~PB1_MASK);
  	
  }
}
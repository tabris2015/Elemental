#define V_pin A0
#define K_20v 0.1955			// constantes para el rango
#define K_15v 0.1466
#define K_10v 0.0098
#define K_5v  0.0048

int rango;
int valor_med;
float voltaje;
char comando;
void setup() {
	Serial.begin(9600);
	Serial.println("Voltimetro multirango.");
	Serial.println("Rangos: \t 20v(0) \n\t 15v(1) \n\t 10v(2) \n\t 5v(3)");
}
void loop() {
  
  if(Serial.available())
  {
  	comando = Serial.read();

  }
  valor_med = analogRead(V_pin);
  switch(comando)
  {
  	case '0': 		// 20v
  		voltaje = K_20v * valor_med;
  		break;
  	case '1': 		// 15v
  		voltaje = K_15v * valor_med;
  		break;
  	case '2': 		// 10v
  		voltaje = K_10v * valor_med;
  		break;	
  	case '3': 		// 5v
  		voltaje = K_5v * valor_med;
  		break;
  	default:
  		voltaje= K_5v * valor_med;
  		break;
  }
  Serial.print("Voltaje: ");
  Serial.print(voltaje);
  Serial.println(" [V]");
  delay(200);
}
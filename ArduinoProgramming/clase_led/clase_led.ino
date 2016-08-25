#define LED 13
#define INTERVALO 500
int estado_led = 0;
long tiempo_ant;

class Parpadeador
{
	// datos: variables miembro
	int ledPin;
	long intervalo;
	int estado;
	long tiempo_ant;
	// comportamiento: metodos
public:
	// constructor ( inicializar)
	Parpadeador(int pin, long inter)
	{
		ledPin = pin;
		pinMode(ledPin, OUTPUT);
		intervalo = inter;
		estado = 0;
		tiempo_ant = 0;
	}
	void Actualizar()
	{
		long tiempo = millis();
		if((tiempo - tiempo_ant) > intervalo)
		{
			tiempo_ant = tiempo;
			estado = !estado;
			digitalWrite(ledPin, estado);
		}
	}
};

Parpadeador ledPlaca(13, 500);
Parpadeador ledExt(6, 600);


void setup() {
  /* code */
  //pinMode(LED, OUTPUT);
}
void loop() {
  /* code */
	ledPlaca.Actualizar();
	ledExt.Actualizar();
}
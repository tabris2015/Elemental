#define LED 13
// definicion de estados
enum estado 
	{
		OFF,
		BUSCANDO,
		ATACANDO,
		HUYENDO
    };
long tiempos[] = {5000, 0, 0, 1000};
long tiempos_ant[4];
bool banderas[4];
long T_OFF;
long T_HUYENDO;
// banderas de eventos:
int S_SW, B_SNS, O_SNS;
// estado inicial
int estado_actual = OFF;

void setup() {
  /* code */
	pinMode(LED, OUTPUT);
	Serial.begin(9600);

}
void loop() {
  /* code */
  long tiempo = millis();
  for(int i = 0; i < 4; i++)
  {
  	if(tiempos[i] != 0)
  	{
  		if((tiempo - tiempos_ant[i]) > tiempos[i])
  		{
  			tiempos_ant[i] = tiempo;
  			banderas[i] = 1;
  		}
  	}
  }

  leerSensores();

  int estado_sig;
  switch(estado_actual)
  {
  	case OFF:
  	// acciones del estado OFF
  		Serial.println("entrando al estado OFF");
  		estado_sig = OFF;
  		if(S_SW)// && banderas[T_OFF])
  		{

  			estado_sig = BUSCANDO;
  		}
  	break;
  	case BUSCANDO:
  	// acciones del estado BUSCANDO
  		Serial.println("entrando al estado: BUSCANDO");
  		estado_sig = BUSCANDO;
  		if(S_SW)
  		{
  			estado_sig = OFF;
  		}
  		else if(B_SNS)
  		{
  			estado_sig = HUYENDO;
  		}
  		else if(O_SNS)
  		{
  			estado_sig = ATACANDO;
  		}
  	break;
  	case ATACANDO:
  	// acciones del estado ATACANDO
  		Serial.println("entrando al estado: ATACANDO");
  		estado_sig = ATACANDO;
  		if(S_SW)
  		{
  			estado_sig = OFF;
  		}
  		else if(B_SNS)
  		{
  			estado_sig = HUYENDO;
  		}

  	break;

  	case HUYENDO:
  	// acciones del estado HUYENDO
  		Serial.println("entrando al estado HUYENDO");
  		estado_sig = HUYENDO;
  		if(!B_SNS)// && banderas[T_HUYENDO])
  		{
  			estado_sig = BUSCANDO;
  		}
  		else if(S_SW)
  		{
  			estado_sig = OFF;
  		}
  	break;
  }
  estado_actual = estado_sig;
  limpiarSensores();
}

void limpiarSensores()
{
	S_SW = 0;
	B_SNS = 0;
	O_SNS = 0;
	for(int i = 0; i < 4; i++)
	{
		banderas[i] = 0;
	}
}

void leerSensores()
{
	static char comando;
	if (Serial.available())
	{
		comando = Serial.read();
    //Serial.println(comando);
	}

	switch(comando)
	{
		case 'i':
			S_SW = 1;
			break;
		case 'o':
			O_SNS = 1;
			break;
		case 'b':
			B_SNS = 1;
	}
 Serial.print(S_SW);
 Serial.print("--");
 Serial.print(O_SNS);
 Serial.print("--");
 Serial.println(B_SNS);

}










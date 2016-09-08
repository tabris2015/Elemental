// estructura para cada estad
struct State
{
	/* data */
	void (*out_ptr)(void); // FUNCIONES DE SALIDA
	int Next[5]; // TRANSICIONCES
};

typedef const struct State STyp;
// definicion de los estados
#define OFF 0
#define BUSCANDO 1
#define ATACANDO 2
#define HUYENDO 3

// variables para trabajar con la FSM
int cState;
int Input;

// funciones de salida
// estado OFF
void off(void)
{
	Serial.println("entrando al estado OFF");
}

// estado BUSCANDO
void buscar(void)
{
	Serial.println("entrando al estado BUSCANDO");
}

// estado ATACANDO
void atacar(void)
{
	Serial.println("entrando al estado ATACANDO");
}

// estado HUYENDO
void huir(void)
{
	Serial.println("entrando al estado HUYENDO");
}

// crear la FSM
STyp FSM[4] = {
		{off, 		{BUSCANDO, OFF, OFF, OFF, OFF}},
		{buscar, 	{OFF, HUYENDO, ATACANDO, HUYENDO, BUSCANDO}},
		{atacar, 	{OFF, HUYENDO, ATACANDO, HUYENDO, ATACANDO}},
		{huir, 		{OFF, HUYENDO, HUYENDO, HUYENDO, BUSCANDO}}
};
// banderas de eventos:
int S_SW, B_SNS, O_SNS;

void setup() {
  /* code */
  Serial.begin(9600);
  cState = OFF;
}
void loop() {
  // ejecutamos funcion de salida
	(FSM[cState].out_ptr)();
	// leemos la entrada
	Input = leerEntradas();
	// realizamos las transiciones
	cState = FSM[cState].Next[Input];

	S_SW = 0;
	B_SNS = 0;
	O_SNS = 0;

}

int leerEntradas(void)
{
	static char comando;
	if(Serial.available())
	{
		comando = Serial.read();
	}

	switch(comando)
	{
		case 'i':
			S_SW = 1; break;
		case 'o':
			O_SNS = 1; break;
		case 'b':
			B_SNS = 1; break;
	}

	Serial.print(S_SW);
	Serial.print("--");
	Serial.print(O_SNS);
	Serial.print("--");
	Serial.println(B_SNS);

	if(S_SW) return 0;
	if(B_SNS) return 1;
	if(O_SNS) return 2;
	if(B_SNS && O_SNS) return 3;
	if(!B_SNS) return 4;

}

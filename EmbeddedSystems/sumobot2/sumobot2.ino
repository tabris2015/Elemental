#include <Elemental.h>
#include <NewPing.h>
// PINES PARA LAS ENTRADAS
#define S_IZQ A0
#define S_DER A1
#define TRIG A4
#define ECHO A5
#define UMBRAL_ENEMIGO 20

#define SWITCH 4
#define S_OP 5
#define UMBRAL 600
// sensor ultra
NewPing oponente(TRIG, ECHO, 70);

// EVENTOS
enum evento { BOTON_PRESIONADO, BORDE_DETECTADO, OPONENTE_DETECTADO};

//
ElementalMotors carro;
int s_dist = 0;
volatile int s_izq = 0;
volatile int s_der = 0;
// estructura para cada estad
struct State
{
	/* data */
	void (*out_ptr)(void); // FUNCIONES DE SALIDA
	int Next[5]; // TRANSICIONCES
};

typedef const struct State STyp;
// definicion de los estados para el sumobot
#define OFF 0
#define BUSCANDO 1
#define ATACANDO 2
#define HUYENDO 3
//
// variables para trabajar con la FSM
int cState;
int Input;

// funciones de salida
// estado OFF
void off(void)
{
	Serial.println("entrando al estado OFF");
	carro.detener();
}

// estado BUSCANDO
void buscar(void)
{
	Serial.println("entrando al estado BUSCANDO");
	// secuencia

	carro.detener();
	carro.motorIzquierdo(200);
}

// estado ATACANDO
void atacar(void)
{
	Serial.println("entrando al estado ATACANDO");
	carro.conducir(255);
}

// estado HUYENDO
void huir(void)
{
	Serial.println("entrando al estado HUYENDO");
	// secuencia
	int sensores = s_der | s_izq << 1;
	switch(sensores)
	{
		case 1: // sensor derecho
			carro.pivotar(255); break;
		case 2: // sensor izquierdo
			carro.pivotar(-255); break;
		case 3: // ambos
			carro.conducir(-255); break;
	}
}

// crear la FSM
STyp FSM[4] = {
		{off, 		{BUSCANDO, OFF, OFF, OFF, OFF}},
		{buscar, 	{OFF, HUYENDO, ATACANDO, HUYENDO, BUSCANDO}},
		{atacar, 	{OFF, HUYENDO, ATACANDO, HUYENDO, ATACANDO}},
		{huir, 		{OFF, HUYENDO, HUYENDO, HUYENDO, BUSCANDO}}
};
// banderas de eventos:
volatile int S_SW, B_SNS, O_SNS;
// ISR

void izqCallback()
{
  s_izq = 1;
}
void derCallback()
{
  s_der = 1;
}
void setup() {
  /* code */
  pinMode(S_SW, INPUT_PULLUP);
  pinMode(S_OP, INPUT);  
  Serial.begin(9600);
  cState = BUSCANDO; // ESTADO INICIAL
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
	int sw = 0;//digitalRead(S_SW);

	s_dist = oponente.ping_cm();
	s_dist = s_dist == 0 ? 70 : s_dist;

	s_dist = s_dist < UMBRAL_ENEMIGO ? 1 : 0;
	// sensores de linea
	s_izq = analogRead(S_IZQ);
	s_der = analogRead(S_DER);
	s_izq = s_izq < UMBRAL ? 1 : 0;
	s_der = s_der < UMBRAL ? 1 : 0;

	if(sw != 0) S_SW = 1;
	else if(s_izq || s_der) B_SNS = 1;
	
	if(s_dist == 1) O_SNS = 1;
	
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

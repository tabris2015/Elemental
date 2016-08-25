#ifndef SERVOSWEEP_H
#define SERVOSWEEP_H
#include "Servo.h"
class ServoSweep
{
	// datos: variables miembro
	int servoPin;
	long interval;
	int position;
	int sentido;
	long prev_time;
	Servo servo;
public:
	ServoSweep(int pin, long inter);
	void Update();
	void SetInterval(long inter);
	long GetInterval();
};
#endif
#include "Arduino.h"
#include "ServoSweep.h"

	ServoSweep::ServoSweep(int pin, long inter)
	{
		servoPin = pin;
		servo.attach(servoPin);
		interval = inter;
		position = 0;
		sentido = 0;
		prev_time = 0;
	}
	void ServoSweep::Update()
	{
		long cTime = millis();
		if((cTime - prev_time) > interval)
		{
			prev_time = cTime;
			if(sentido)
			{
				position++;
				if(position > 180) sentido = 0;
			}
			else
			{
				position--;
				if(position < 0) sentido = 1;
			}
			servo.write(position);
		}	
	}
	void ServoSweep::SetInterval(long inter)
	{
		interval = inter;
	}
	long ServoSweep::GetInterval()
	{
		return interval;
	}

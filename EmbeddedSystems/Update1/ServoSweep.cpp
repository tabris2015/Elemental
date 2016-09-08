#include "Arduino.h"
#include "ServoSweep.h"

	ServoSweep::ServoSweep(long inter)
	{
		interval = inter;
		position = 0;
		sentido = 0;
		prev_time = 0;
	}
	void ServoSweep::Update(Servo * servo)
	{
		long cTime = millis();
		if((cTime - prev_time) > interval)
		{
			prev_time = cTime;
			servo->write(position);
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
			Serial.println("actualiza servo");
      		Serial.println(position);
      		Serial.println(sentido);
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

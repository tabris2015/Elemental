#include "Follower.h"

SensorArray::SensorArray()
{
	DDRC = 0x00; // all port as input;
}
uint8_t SensorArray::getDensity()
{
	return _density;
}
int SensorArray::getPosition()
{
	return _position;
}
uint8_t SensorArray::getBit(uint8_t bit)
{
	return _bits[bit];
}
void SensorArray::getArray(uint8_t * values)
{
	for(int i = 0; i < 8; i++)
	{
		*(values + i) = _bits[i];
	}
}
void SensorArray::Update()
{
	readSensors(_bits);
}

uint8_t SensorArray::getRaw()
{
	return _data;
}

void SensorArray::readSensors(uint8_t * values)
{
	int accum = 0;

	_data = PINC;
	_density = 0;
	uint8_t i;
	for(i = 0; i < 8; i++)
	{
		if(((_data >> i) & 0x01) == 1)
		{
			_density++;
			accum += 32 * (i + 1);
		}

		*(values + i) = (_data >> i) && 0x01;
	}

	if (_density > 0)
	{
		_position = accum / _density - 144;
	}
}

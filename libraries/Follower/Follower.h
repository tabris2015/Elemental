#ifndef FOLLOWER_H
#define FOLLOWER_H

#include <Arduino.h>

#define NO_FILTER	0
#define FILTER_2S	1
#define FILTER_4S	2
#define FILTER_8S	3

class SensorArray
{
public:
	SensorArray();
	uint8_t getDensity();
	int getPosition();
	uint8_t getBit(uint8_t bit);
	void getArray(uint8_t * values);
	uint8_t getRaw();
	void Update();
private:
	uint8_t _data;
	int _position;
	uint8_t _bits[8];
	uint8_t _density;
	/* data */
	void readSensors(uint8_t * values);
};

class Motors
{
public:
	Motors(uint8_t l_pwm, uint8_t l_ctrl1, uint8_t l_ctrl2, uint8_t r_pwm, uint8_t r_ctrl1, uint8_t r_ctrl2);
	void drive(int16_t speed);  // Conducir ambos motores con la misma velocidad
    void drive(int16_t l_speed, int16_t r_speed);
    void pivot(int16_t speed);  // Conduce motores en direcciones opuestas
    void pivot(int16_t speed, uint16_t duration);  // pivotar con delay
    void stop();            // Detiene ambos motores
    void frenar();           // Frenado de ambos motores

  private:
    void leftForward(uint8_t speed); 	// funciones primitivas para mover los motores
    void leftBackward(uint8_t speed);
    void rightForward(uint8_t speed); 	// funciones primitivas para mover los motores
    void rightBackward(uint8_t speed);

    uint8_t l_pwm_pin;
    uint8_t r_pwm_pin;
  	uint8_t l_ctrl1_pin;
  	uint8_t l_ctrl2_pin;
  	uint8_t r_ctrl1_pin;
  	uint8_t r_ctrl2_pin;
    
      
};
class pid
{
public:
	pid(float * input, float * output, float * setpoint,
		float inKp, float inKi, float inKd);
	int16_t Compute();
	void SetLimits(float nMin, float nMax);
	void SetParameters(float nKp, float nKi, float nKd);
	void SetDirection(uint16_t dir);
	void SetSampleTime(uint16_t time);

	float getKp();
	float getKi();
	float getKd();

private:
	void Init();

	float * userInput;
	float * userOutput;
	float * userSetpoint;
	
	float kp;
	float ki;
	float kd;

	float ITerm;
	float lastInput;

	uint16_t sampleTime;
	float max_out;
	float min_out;
	uint16_t max_out_int;
	uint16_t min_out_int;
};
#endif
 					

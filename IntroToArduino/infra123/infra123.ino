#define SENSOR_PIN 9
#define LED_PIN 13
int lectura; // almacena el estado del sensor
void setup()
{
	pinMode(SENSOR_PIN, INPUT);
	pinMode(LED_PIN, OUTPUT);
	Serial.begin(9600);
}
void loop()
{
	lectura = digitalRead(SENSOR_PIN);
	digitalWrite(LED_PIN, lectura);
	Serial.println(lectura != 0 ? "NEGRO" : "BLANCO");
	delay(100);
}
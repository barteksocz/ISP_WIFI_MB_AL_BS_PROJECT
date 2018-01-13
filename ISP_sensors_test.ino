#include "sensors.h"

void setup() {
	Serial.begin(115200);
}

void loop() {
	int16_t temp_data = magnetic_sensor_read();
	Serial.println("M:");
	Serial.println(temp_data);
	delay(400);
	temp_data = temperature_sensor_read();
	Serial.println("T:");
	Serial.println(temp_data);
	delay(400);
}
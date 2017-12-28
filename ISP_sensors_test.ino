#include "sensors.h"

void setup() {
	Serial.begin(115200);
}

void loop() {
	int temp_data = magnetic_sensor_read();
	Serial.println("M:");
	Serial.println(temp_data);
	delay(1000);
	Serial.println("D:");
	temp_data = distance_sensor_read();
	Serial.println(temp_data);
	delay(1000);
	temp_data = temperature_sensor_read();
	Serial.println("T:");
	Serial.println(temp_data);
	delay(1000);
}
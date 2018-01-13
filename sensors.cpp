#include "sensors.h"

int16_t magnetic_sensor_read(void) {
	int temp_data = analogRead(MAGNETIC_SENSOR_ANALOG_PIN);
	if (temp_data <= MS_ADC_THRESHOLD)
		return 0;
	else
	    return 1;
}

int16_t temperature_sensor_read(void) {
	int temp_data;
	temp_data = analogRead(TEMP_SENSOR_ANALOG_PIN);
	temp_data = temp_data * TEMPERATURE_SCALE_FACTOR_1 / TEMPERATURE_SCALE_FACTOR_2;
	if ((temp_data % 10) >= 5)
	   return ((temp_data / 10) + 1);	
	else
	   return (temp_data / 10);
}

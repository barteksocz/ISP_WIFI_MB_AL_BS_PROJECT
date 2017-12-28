#include "sensors.h"

void sensors_init(void) {
	//trzeba uzupelnic
}

int16_t magnetic_sensor_read(void) {
	int temp_data = analogRead(MAGNETIC_SENSOR_ANALOG_PIN);
	if (temp_data <= MS_ADC_LOW_STATE_THRESHOLD)
		return 0;
	else if ((temp_data <= MS_ADC_HIGH_STATE_THRESHOLD_1) && (temp_data >= MS_ADC_HIGH_STATE_THRESHOLD_2))
	    return 1;
    else
		return SENSOR_ERROR;
}

int16_t distance_sensor_read(void) {
	long measured_time;
	digitalWrite(TRIG,HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG,LOW);
	measured_time = pulseIn(ECHO,HIGH);
	if ((measured_time == 0) || (measured_time >= TIME_THRESHOLD))
		return SENSOR_ERROR;
	else
		return measured_time / DISTANCE_SENSOR_FACTOR;
}

int16_t temperature_sensor_read(void) {
	//trzeba uzupelnic
}

#include "Arduino.h"

#define MAGNETIC_SENSOR_ANALOG_PIN 3

#define SENSOR_ERROR -1

#define MS_ADC_LOW_STATE_THRESHOLD 10
#define MS_ADC_HIGH_STATE_THRESHOLD_1 550
#define MS_ADC_HIGH_STATE_THRESHOLD_2 450

void sensors_init(void);
int16_t magnetic_sensor_read(void);
int16_t temperature_sensor_read(void);
int16_t distance_sensor_read(void);
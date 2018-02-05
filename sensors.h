#include "Arduino.h"

#define MAGNETIC_SENSOR_ANALOG_PIN 3
#define TEMP_SENSOR_ANALOG_PIN 2

#define MS_ADC_THRESHOLD 450

#define TEMPERATURE_SCALE_FACTOR_1 48876
#define TEMPERATURE_SCALE_FACTOR_2 10000

int16_t magnetic_sensor_read(void);
int16_t temperature_sensor_read(void);
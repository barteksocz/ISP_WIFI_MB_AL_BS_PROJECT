#include "Arduino.h"

#define MAGNETIC_SENSOR_ANALOG_PIN 3
#define TEMP_SENSOR_ANALOG_PIN 2
#define TRIG 2
#define ECHO 3

#define SENSOR_ERROR -1

#define MS_ADC_LOW_STATE_THRESHOLD 10
#define MS_ADC_HIGH_STATE_THRESHOLD_1 550
#define MS_ADC_HIGH_STATE_THRESHOLD_2 450

#define TEMPERATURE_SCALE_FACTOR_1 48876
#define TEMPERATURE_SCALE_FACTOR_2 10000

#define DISTANCE_SENSOR_FACTOR 58
#define TIME_THRESHOLD (58 * 200)

void distance_sensor_init(void);
int16_t magnetic_sensor_read(void);
int16_t temperature_sensor_read(void);
int16_t distance_sensor_read(void);
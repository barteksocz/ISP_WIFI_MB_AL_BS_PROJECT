#include "Arduino.h"

void sensors_init(void);
bool magnetic_sensor_read(void);
int16_t temperature_sensor_read(void);
int16_t distance_sensor_read(void);
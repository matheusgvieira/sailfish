#ifndef _sensor_h
#define _sensor_h

#include <stdio.h> 

#define ONEWIREDEVICELOCATION "/sys/bus/w1/devices/"
#define ONEWIRESLAVEDEVICE "/w1_slave"
#define DS18B20FAMILYCODE "28"
#define DEFAULTSENSORNAME "Sensor"

typedef struct Sensor
{
    char *SensorName;
    FILE *SensorFile;    
} Sensor;

Sensor *GetSensor(char *sensorId, char *sensorName);

float ReadTemperature(const Sensor *sensor);

#endif /* _sensor_h */
#include "sensor.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

Sensor *GetSensor(char *sensorId, char *sensorName)
{
    Sensor *sensor = malloc(sizeof(Sensor));
    sensor->SensorFile = fopen(sensorId, "r");
    sensor->SensorName = sensorName;
    return sensor;
}

float ReadTemperature(const Sensor *sensor)
{
    long deviceFileSize;
    char *buffer;

    FILE *deviceFile = sensor->SensorFile;
    fseek(deviceFile, 0, SEEK_END);
    deviceFileSize = ftell(deviceFile);
    fseek(deviceFile, 0, SEEK_SET);

    buffer = calloc(deviceFileSize, sizeof(char));
    
    fread(buffer, sizeof(char), deviceFileSize, deviceFile);
    char *temperatureComponent = strstr(buffer, "t=");
    if(!temperatureComponent)
    {
        free(buffer);
        return -1;
    }

    temperatureComponent +=2; //move pointer 2 spaces to compensate for t=
    
    float temperatureFloat = atof(temperatureComponent);
    temperatureFloat = temperatureFloat / 1000;

    if(temperatureFloat < -55)
        temperatureFloat = -55;
    else if(temperatureFloat > 125)
        temperatureFloat = 125;    

    free(buffer);
    return temperatureFloat;
}

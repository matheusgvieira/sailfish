#include <stdio.h>
#include <string.h>
#include "sensor.h"

#define lenSensorLocale 100
#define DS18B20 "28-021313d1b8aa"

int main(){
    char locale[lenSensorLocale] = "";
    float temp = 0;

    strcat(locale, ONEWIREDEVICELOCATION);
    strcat(locale, DS18B20);
    strcat(locale, ONEWIRESLAVEDEVICE);
    Sensor *sensor = GetSensor(locale, DEFAULTSENSORNAME);

    temp = ReadTemperature(sensor);
    printf("%.2f\n", temp);
    return 0;
}
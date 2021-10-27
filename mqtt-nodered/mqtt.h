#ifndef _MQTT_H_
#define _MQTT_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mosquitto.h>
#include <wiringPi.h>

#define PATHGPIO "/sys/class/gpio/gpio"

int rc;
struct mosquitto * mosq;

void MQTTConnect(const char *id, const char *host, int port, int keepalive, const char *username, const char *password);
void MQTTPub(const char *topic, const void *payload, int qos);
void delay(int milliseconds);
char * pinmonitor(int pin[3]);

#endif //_MQTT_H_
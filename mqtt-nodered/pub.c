#include "mqtt.h"
#include "sensor.h"


// Define sets
#define HOST        "10.0.0.120"
#define PORT        1883 
#define KEEPALIVE    60 
#define CLIENTID    "publisher-test"
#define TOPIC       "/sailfish/temp"
#define TOPICP       "/sailfish/painel"
#define QOS         0
#define USER        "sail"
#define PWD         "12345"
#define TIMEOUT     10000L
#define lenSensorLocale 100
#define DS18B20 "28-021313d1b8aa"
#define MAX 100
#define timedelay 1000


void delay(int milliseconds);

int main(){
    float temp = 0;
    char locale[lenSensorLocale] = "", strtemp[MAX], strpins[4];
    int pins[4] = {6, 22, 17, 26};

    strcat(locale, ONEWIREDEVICELOCATION);
    strcat(locale, DS18B20);
    strcat(locale, ONEWIRESLAVEDEVICE);
    Sensor *sensor = GetSensor(locale, DEFAULTSENSORNAME);

    MQTTConnect(CLIENTID, HOST, PORT, KEEPALIVE, USER, PWD);  

    while(1){
        temp = ReadTemperature(sensor);
        gcvt(temp, 3, strtemp);
        for (int i = 0; i < 4; i++)
            strpins[i] = pinmonitor(pins[i]);
        MQTTPub(TOPIC, strtemp, QOS); 
        MQTTPub(TOPICP, strpins, QOS);
        
        delay(timedelay);
    }
    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();

	return 0;
}



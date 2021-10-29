#include "mqtt.h"

void MQTTConnect(const char *id, const char *host, int port, int keepalive, const char *username, const char *password)
{

	mosquitto_lib_init();

	mosq = mosquitto_new(id, true, NULL);

	mosquitto_username_pw_set(mosq, username, password);

	rc = mosquitto_connect(mosq, host, port, keepalive);
	if (rc != 0)
	{
		printf("Client could not connect to broker! Error Code: %d\n", rc);
		mosquitto_destroy(mosq);
		return;
	}
}

void MQTTPub(const char *topic, const void *payload, int qos)

{
	mosquitto_publish(mosq, NULL, topic, strlen(payload), payload, qos, false);
}

void delay(int milliseconds)
{
	long pause;
	clock_t now, then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	now = then = clock();
	while ((now - then) < pause)
		now = clock();
}

char pinmonitor(int pin)
{ // red, blue, green, buzzer
	char filegpio[100], num[10];
	char val;
	strcpy(filegpio, PATHGPIO);
	sprintf(num, "%d", pin);
	strcat(filegpio, num);
	strcat(filegpio, "/value");

	FILE *filePointer = NULL;

	int thisCharacter;

	filePointer = fopen(filegpio, "r");

	if (!filePointer)
	{
		printf("Erro na abertura do arquivo");
		exit(-1);
	}

	while ((thisCharacter = fgetc(filePointer)) != EOF)
	{
		val = thisCharacter;
		break;
	}

	fclose(filePointer);
	filePointer = NULL;

	return val;
}

char *get_temp()
{	
	float num;
	char *numstr = malloc(2 * sizeof(char));
	FILE *fptr;

	if ((fptr = fopen("/home/pi/sailfish/mqtt-nodered/temperature.txt", "r")) == NULL)
	{
		printf("Error! opening file");
		exit(1);
	}

	fscanf(fptr, "%f", &num);
	sprintf(numstr, "%.2f", num);

	fclose(fptr);

	return numstr;
}

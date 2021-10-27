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

	mosquitto_disconnect(mosq);
	mosquitto_destroy(mosq);

	mosquitto_lib_cleanup();
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

char *pinmonitor(int pin[3])
{ // red, blue, green, buzzer
	char filegpio[10], num[10];
	char values[10], ch;
	strcat(values, "[");

	for (int j = 0; j < 4; j++)
	{
		strcat(filegpio, PATHGPIO);
		sprintf(num, "%d", pin[j]);
		strcat(filegpio, num);
		strcat(filegpio, "/value");

		FILE *fp;

		fp = fopen(filegpio, "r"); // read mode

		if (fp == NULL)
		{
			perror("Error while opening the file.\n");
			exit(EXIT_FAILURE);
		}

		while ((ch = fgetc(fp)) != EOF)
			strcat(values, ch);
		if (j < 3) strcat(values, ", ");

		for (int i = 0; i < 10; i++){
			filegpio[i] = "";
		} 
	}
	strcat(values, "]");

	return values;
}

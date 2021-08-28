#ifndef _BUZZER_H_
#define _BUZZER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GPIO_PATH "/sys/class/gpio"

#define pinBuzzer 26

int write_to_file(char *file_name, char *content);
int read_from_file(char *file_name, char *content, int N);
int setGPIOdirection(int pin, char *direction);
int BuzzerState(int value);
int GPIOread(int pin);

#endif //_BUZZER_H_
#ifndef _RGB_H_
#define _RGB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GPIO_PATH "/sys/class/gpio"

const int _green = 22;
const int _blue = 17;
const int _red = 6;

int write_to_file(char *file_name, char *content);
int read_from_file(char *file_name, char *content, int N);
int setGPIOdirection(int pin, char *direction);

int RGBGreen(int value);
int RGBBlue(int value);
int RGBRed(int value);
int GPIOread(int pin);

#endif //_RGB_H_
#include "rgb.h"

int setGPIOdirection(int pin, char *direction)
{
	if((strcmp(direction, "out")!=0)&&(strcmp(direction, "in")!=0))
		return -1;
	int valid_pins[18]={0, 1, 4, 6, 7, 8, 9, 10, 11, 14, 15, 17, 18, 21, 22, 23, 24, 25};
	for(int c=0;c<18;c++)
	{
		if(pin == valid_pins[c])
		{
			char str[100];
			sprintf(str, "%d", pin);
			if(write_to_file(GPIO_PATH "/export", str)<0)
				return -3;
			sprintf(str, GPIO_PATH "/gpio%d/direction", pin);
			if(write_to_file(str, direction)<0)
				return -4;
			return 0;
		}
	}
	return -2;
}

int write_to_file(char *file_name, char *content)
{
	FILE* fp = fopen(file_name, "w");
	if(fp==NULL)
		return -1;
	int i = fprintf(fp, content);
	fclose(fp);
	if(i<0)
		return -2;
	return 0;
}

int read_from_file(char *file_name, char *content, int N)
{
	FILE* fp = fopen(file_name, "r");
	if(fp==NULL)
		return -1;
	int i = fread(content, N, sizeof(char), fp);
	fclose(fp);
	if(i<N)
		return -2;
	return 0;
}

int RGBGreen(int value)
{
	if((value!=0)&&(value!=1))
		return -1;
	char str[100], val[2];
	sprintf(str, GPIO_PATH "/gpio%d/value", _green);
	sprintf(val, "%d", value);
	if(write_to_file(str, val)<0)
		return -2;
	return 0;
}

int RGBBlue(int value)
{
	if((value!=0)&&(value!=1))
		return -1;
	char str[100], val[2];
	sprintf(str, GPIO_PATH "/gpio%d/value", _blue);
	sprintf(val, "%d", value);
	if(write_to_file(str, val)<0)
		return -2;
	return 0;
}

int RGBRed(int value)
{
	if((value!=0)&&(value!=1))
		return -1;
	char str[100], val[2];
	sprintf(str, GPIO_PATH "/gpio%d/value", _red);
	sprintf(val, "%d", value);
	if(write_to_file(str, val)<0)
		return -2;
	return 0;
}

void RGBOff()
{
	RGBGreen(0);
	RGBRed(0);
	RGBBlue(0);
}



int GPIOread(int pin)
{
	char str[100];
	char value;
	sprintf(str, GPIO_PATH "/gpio%d/value", pin);
	if(read_from_file(str, &value, 1)<0)
		return -1;
	return (int)(value - '0');
}
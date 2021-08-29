#include "rgb.h"
#include <string.h>

int main(int argc, char **argv)
{
    printf("arg[1] = %s \n", argv[1]);
    
    if (strcmp(argv[1], "red") == 0)
    {
        RGBRed(1);
        printf("Led vermelho ligou! \n");
    }

    if (strcmp(argv[1], "blue") == 0)
    {
        RGBBlue(1);
        printf("Led azul ligou! \n");
    }
    if (strcmp(argv[1], "green") == 0)
    {
        RGBGreen(1);
        printf("Led verde ligou! \n");
    }
    if (strcmp(argv[1], "off") == 0)
    {
        RGBOff();
        printf("Desligado todos os leds! \n");
    }

    return 0;
}
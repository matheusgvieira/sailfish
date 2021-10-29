#include "rgb.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    switch (atoi(argv[1]))
    {
    case 0:
        setGPIOdirection(_green, "out");
        setGPIOdirection(_blue, "out");
        setGPIOdirection(_red, "out");
        break;
    case 1:
        RGBRed(1);
        printf("Led vermelho ligou! \n");
        break;
    case 2:
        RGBBlue(1);
        printf("Led azul ligou! \n");
        break;
    case 3:
        RGBGreen(1);
        printf("Led verde ligou! \n");
        break;
    case 10:
        RGBRed(0);
        printf("Led vermelho desligou! \n");
        break;
    case 20:
        RGBBlue(0);
        printf("Led azul desligou! \n");
        break;
    case 30:
        RGBGreen(0);
        printf("Led verde desligou! \n");
        break;

    default:
        RGBOff();
        printf("Desligado todos os leds! \n");
        break;
    }

    return 0;
}
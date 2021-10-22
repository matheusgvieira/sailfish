#include "rgb.h"
#include <string.h>

int main(int argc, char **argv)
{
    setGPIOdirection(_green, "out");
    setGPIOdirection(_blue, "out");
    setGPIOdirection(_red, "out");
    
    if (strcmp(argv[1], "red") == 0)
    {
        RGBRed(1);
        printf("Led vermelho ligou! \n");
    }

    if (strcmp(argv[1], "offred") == 0)
    {
        RGBRed(0);
        printf("Led vermelho desligou! \n");
    }

    if (strcmp(argv[1], "blue") == 0)
    {
        RGBBlue(1);
        printf("Led azul ligou! \n");
    }
    if (strcmp(argv[1], "offblue") == 0)
    {
        RGBBlue(0);
        printf("Led azul desligou! \n");
    }
    if (strcmp(argv[1], "green") == 0)
    {
        RGBGreen(1);
        printf("Led verde ligou! \n");
    }
    if (strcmp(argv[1], "offgreen") == 0)
    {
        RGBGreen(0);
        printf("Led verde desligou! \n");
    }
    if (strcmp(argv[1], "off") == 0)
    {
        RGBOff();
        printf("Desligado todos os leds! \n");
    }

    return 0;
}
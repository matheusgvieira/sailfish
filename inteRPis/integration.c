#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATHGPIO "/sys/class/gpio/gpio"
#define VALUE "/value"

int main()
{
    int num;
    char * numstr = malloc(2*sizeof(char));
    FILE *fptr;
    char file[256], outs[256];
    char *pins[4] = {"6", "22", "17", "26"};
    
    for (int i = 0; i < 4; i++)
    {
        snprintf(file, sizeof(file), "%s%s%s", PATHGPIO, pins[i], VALUE);
        if ((fptr = fopen(file, "r")) == NULL)
        {
            printf("Error! opening file");
            exit(1);
        }

        fscanf(fptr, "%d", &num);
        sprintf(numstr, "%d", num);
        strcat(outs, numstr);
    }

    printf("%s\n", outs);
    fclose(fptr);

    return 0;
}

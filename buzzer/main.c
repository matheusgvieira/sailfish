#include "buzzer.h"
#include <string.h>  
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv){
    setGPIOdirection(pinBuzzer, "out");
    system("gpio export 26 out"); 
    int state = atoi(argv[1]);

    BuzzerState(state);
    if (state){
        printf("Ligou buzzer! \n");
    } else {
        printf("Desligou buzzer! \n");
    }

    return 0;
}
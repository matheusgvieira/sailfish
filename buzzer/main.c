#include "buzzer.h"
#include <string.h>  


int main(int argc, char **argv){
    int state = atoi(argv[1]);

    BuzzerState(state);
    if (state){
        printf("Ligou buzzer! \n");
    } else {
        printf("Desligou buzzer! \n");
    }

    return 0;
}
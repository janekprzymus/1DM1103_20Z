#include <stdio.h>
#include <stdlib.h>
#include "includy/p7_3_dodaj.h"
#include "includy/p7_3_liczydlo.h"

int main(int argc, char **argv) {
    
    printf("a+b= %f\n", dodaj(atof(argv[1]), atof(argv[2])));
    printf("suma(a+b+c) = %f\n", sumuj(atof(argv[1]), atof(argv[2]), atof(argv[3])));
    printf("Liczb wywolan sumuj jest rowna: %d\n", ilosc_wywolan);

    return 0;
}


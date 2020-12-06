#include <stdio.h>
#include <stdlib.h>

float dodaj(float a, float b);

int main(int argc, char **argv) {
    printf("a+b= %f\n", dodaj(atof(argv[1]), atof(argv[2])));
    return 0;
}

float dodaj(float a, float b) {
    return a+b;
}
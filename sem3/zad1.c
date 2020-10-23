#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    float a=atof(argv[1]);
    float b=a*a;
    
    printf("Argv to: %s\n",argv[1]);
    printf("Wartosc %f do kwadratu to %f.\n",a,b);
}
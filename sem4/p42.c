#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* cel: napisac samemu funkcje:
1. ktora zwroci dlugosc napisu (liczbe znakow)
2. ktora skopiuje napis z jednego miejsca pamieci w drugie */

void nawielkie(char *n)
{
    for(int i=0;i<strlen(n);i++)
    n[i]=toupper(n[i]);
        
}

int main(int argc, char *argv[])
{
    char napis[255];
    printf("%s ma dlugosc: %ld\n", argv[1], strlen(argv[1]));

    strncpy(napis, argv[2], 254);
    nawielkie(napis);
    printf("%s ma dlugosc: %ld\n", napis, strlen(napis));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char napis[]="Podstawy Programowania S4";
    int dlugosc=strlen(napis);
    for(int i=0; napis[i]!=0; i++)
        printf("%c", napis[i]);
    printf(" (%d)\n", dlugosc);

    return 0;
}
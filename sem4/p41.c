#include <stdio.h>
#include <stdlib.h>

/* cel: napisac samemu funkcje:
1. ktora zwroci dlugosc napisu (liczbe znakow)
2. ktora skopiuje napis z jednego miejsca pamieci w drugie */

int dlugosc_napisu(char *napis)
{
    int l=0;
    while(napis[l]!=0)
        l++;
    return l;

    /* GARGAMELOWATO:
    for(l=0; napis[l]!=0; l++);
    "pusty for" = nie wolno */
}

void skopiuj(char *gdzie, char *co)
{
    int i=0;
    while(co[i]!=0)
    {
        gdzie[i]=co[i];
        i++;
    }
}

int znajdz(char z, char *n)
{
    int i=0;
    int max=dlugosc_napisu(n);
    while((z!=n[i])&&(i<max))
        i++;
    if(i<max)
        return i;
    else
        return -1; //zwraca -1 gdy nie znajdzie znaku w napisie
    
}

void nawielkie(char *n)
{
    char *male = "abcdefghijklmnopqrstuvwxyz";
    char *duze = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i,j;
    for(i=0;i<dlugosc_napisu(n);i++)
    {
        j=znajdz(n[i], male);
        if(j>=0)
            n[i]=duze[j];
    }
}

int main(int argc, char *argv[])
{
    char napis[255];
    printf("%s ma dlugosc: %d\n", argv[1], dlugosc_napisu(argv[1]));

    skopiuj(napis, argv[2]);
    nawielkie(napis);
    printf("%s ma dlugosc: %d\n", napis, dlugosc_napisu(napis));
    return 0;
}
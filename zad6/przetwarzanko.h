#ifndef PRZETW_H
#define PRZETW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _macierz
{
    int r;
    int c;
    float **tab;
} macierz, *pmacierz;

void wczytaj(FILE *fin, macierz *m);
void zwolnij(macierz *m);
void wypisz(macierz m);
void zapisz(char nazwa[], macierz m);

#endif
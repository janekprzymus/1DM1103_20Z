#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wczytaj(FILE *fin, float *tablica, int *w1 , int *w2) {
    int wiersze, kolumny;
    int i;
    float liczba;

    fscanf(fin, "%d", &wiersze);
    *w1=wiersze;
    
    fscanf(fin, "%d", &kolumny);
    *w2=kolumny;

    for (i=0; i<(wiersze*kolumny); i++) 
    {
        fscanf(fin, "%f", &liczba);
        tablica[i] = liczba;
    }
}

float mnozenie(float *m1, float *m2, int w)
{
    float wyn=0;
    for(int i=0;i<w;i++)
    {
        wyn=wyn+(m1[i]*m2[i]);
    }
    return wyn;
}

void wypisz_macierz(float *w, int w1, int w2) {
    int k=0;
    printf("(%dx%d)\n", w1, w2);
    for (int i=0; i<w1; i++)
    {
        printf("[ ");
        for(int j=0; j<w2; j++)
        {
        printf("%.1f ", w[k]);
        k++;
        }
    printf("]\n");
    }
}

int main(int argc, char *argv[])
{
    FILE *fin1;
    FILE *fin2;
    float macierz[50], wektor[10], wynik[10];
    int wA1=0, wA2=0, wx1=0, wx2=0, wb1, wb2;

    fin1 = fopen(argv[1], "r");
    fin2 = fopen(argv[2], "r");
    wczytaj(fin1, macierz, &wA1, &wA2);
    wczytaj(fin2, wektor, &wx1, &wx2);

    printf("Macierz A:\n");
    wypisz_macierz(macierz, wA1, wA2);
    printf("Wektor x:\n");
    wypisz_macierz(wektor, wx1, wx2);

    if(wA2!=wx1)
    {
        printf("Podanych macierzy nie mozna wymnozyc.\n");
        exit(-99);
    }
    else
    {
        int i, j, k;
        float temp;
        for(i=0;i<wA1;i++)
        {
            temp=0;
            k=(i*wA2);
            j=0;
            while(j<wx1)
            {
                temp=temp+(macierz[k]*wektor[j]);
                j++;
                k++;
            }
            wynik[i]=temp;
        }
        wb1=wA1;
        wb2=wx2;
    }
    printf("\nWynik mnozenia b:\n");
    wypisz_macierz(wynik,wb1,wb2);

    return 0;
}
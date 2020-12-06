#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct macierz
{
    int r;
    int c;
    float tab[20][20];
};

void wczytaj(FILE *fin, struct macierz *m)
{
    int i, j;
    //fscanf(fin, "%d", &(*m).r);
    //fscanf(fin, "%d", &(*m).c);
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);

    for(i=0; i < m->r; i++)
    {
        for(j=0; j < m->c; j++)
        {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }
}

void wypisz(struct macierz m)
{
    int i, j;
    for(i=0; i<m.r; i++)
    {
        printf("[ ");
        for(j=0; j<m.c; j++)
        {
            printf("%3.1f ", m.tab[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

float norm(struct macierz m)
{
    float s=0;
    int i,j;

    for(i=0; i<m.r; i++)
        for(j=0; j<m.c; j++)
            s+=m.tab[i][j]*m.tab[i][j];
    return sqrt(s);
}

float suma(struct macierz m)
{
    float s=0;
    int i,j;

    for(i=0; i<m.r; i++)
        for(j=0; j<m.c; j++)
            s+=m.tab[i][j];
    return s;
}

void zapisz(char nazwa[], struct macierz m)
{
    FILE *fout = fopen(nazwa, "w");
    int i,j;

    fprintf(fout, "%d\n%d\n", m.r, m.c);
    for(i=0; i<m.r; i++)
    {
        for(j=0; j<m.c; j++)
            fprintf(fout, "%4.1f", m.tab[i][j]);
        fprintf(fout, "\n");
    }
    fclose(fout);
}

int main(int argc, char *argv[])
{
    struct macierz mac;
    FILE *fin;

    if(strcmp(argv[1], "norm")==0)
    {
        fin=fopen(argv[2], "r");
        wczytaj(fin, &mac);
        wypisz(mac);
        printf("Norma macierzy %s = %f\n", argv[1], norm(mac));
        fclose(fin);
    } 
    else if(strcmp(argv[1], "suma")==0)
    {
        fin=fopen(argv[2], "r");
        wczytaj(fin, &mac);
        wypisz(mac);
        printf("Suma elementow macierzy %s = %f\n", argv[1], suma(mac));
        fclose(fin);
    }
    else
    {
        printf("Nierozpoznany argument %s, Oczekiwalem: norm/suma\n", argv[1]);
    }
    
    zapisz("wynik.txt", mac);

    return 0;
}
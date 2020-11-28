#include "przetwarzanko.h"

void wczytaj(FILE *fin, macierz *m)
{
    int i, j;
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);

    m->tab = (float**) malloc((m->r)*sizeof(float**));
    for(i=0; i<m->r; i++)
        m->tab[i] = (float*) malloc((m->c)*sizeof(float*));

    for(i=0; i < m->r; i++)
    {
        for(j=0; j < m->c; j++)
        {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }
}

void zwolnij(macierz *m){
    int i;

    for(i=0; i<m->r; i++)
        free(m->tab[i]);
    free(m->tab);
}

void wypisz(macierz m)
{
    int i, j;
    printf("%d\n%d\n",m.r,m.c);
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

void zapisz(char nazwa[], macierz m)
{
    FILE *fout = fopen(nazwa, "w");
    int i,j;

    fprintf(fout, "%d\n%d\n", m.r, m.c);
    for(i=0; i<m.r; i++)
    {
        for(j=0; j<m.c; j++)
            fprintf(fout, "%6.1f", m.tab[i][j]);
        fprintf(fout, "\n");
    }
    fclose(fout);
}
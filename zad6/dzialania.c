#include "dzialania.h"

float norm(macierz m)
{
    float s=0;
    int i,j;

    for(i=0; i<m.r; i++)
        for(j=0; j<m.c; j++)
            s+=m.tab[i][j]*m.tab[i][j];
    zwolnij(&m);
    return sqrt(s);
}

macierz dodaj(macierz *a, macierz x)
{
    int i;
    if((a->r!=x.r)||(a->c!=x.c))
    {
        printf("Podanych macierzy nie mozna zsumowac.\n");
        exit(-1);
    }
    else
    {
        macierz b;
        b.tab = (float**) malloc(sizeof(float*) * a->r);
        for(i=0; i<a->r; i++)
            b.tab[i] = (float*) malloc(sizeof(float) * a->c);

        int i,j;
        b.c=a->c;
        b.r=a->r;
        for(i=0; i<a->r; i++)
            for(j=0; j<a->c; j++)
                b.tab[i][j]=a->tab[i][j]+x.tab[i][j];
        zwolnij(a);
        zwolnij(&x);
        return b;
    }
}

macierz odejmij(macierz *a, macierz x)
{
    if((a->r!=x.r)||(a->c!=x.c))
    {
        printf("Podanych macierzy nie mozna odjac.\n");
        exit(-2);
    }
    else
    {
        macierz b;
        int i,j;
        b.tab = (float**) malloc(sizeof(float*) * a->r);
        for(i=0; i<a->r; i++)
            b.tab[i] = (float*) malloc(sizeof(float) * a->c);
        b.c=a->c;
        b.r=a->r;
        for(i=0; i<a->r; i++)
            for(j=0; j<a->c; j++)
                b.tab[i][j]=a->tab[i][j]-x.tab[i][j];
        zwolnij(a);
        zwolnij(&x);
        return b;
    }
}

macierz prod(macierz *a, macierz *x)
{
    if(a->c!=x->r)
    {
        printf("Podanych macierzy nie mozna wymnozyc.\n");
        exit(-3);
    }
    else
    {
        macierz b;
        int i,j;
        b.r=a->r;
        b.c=x->c;
        b.tab = (float**) malloc(sizeof(float*) * a->r);
        for(i=0; i<a->r; i++)
            b.tab[i] = (float*) malloc(sizeof(float) * x->c);

        for(i=0;i<b.r;i++)
            for(j=0;j<b.c;j++)
            {
                b.tab[i][j]=0;
                for(int k=0;k<a->c;k++)
                    b.tab[i][j]+=a->tab[i][k]*x->tab[k][j];
            }
    zwolnij(a);
    zwolnij(x);
    return b;
    }
}

macierz multi(macierz *a, float x)
{
    macierz b;
    int i,j;
        b.tab = (float**) malloc(sizeof(float*) * a->r);
        for(i=0; i<a->r; i++)
            b.tab[i] = (float*) malloc(sizeof(float) * a->c);
    b.c=a->c;
    b.r=a->r;
    for(i=0; i<a->r; i++)
            for(j=0; j<a->c; j++)
                b.tab[i][j]=a->tab[i][j]*x;
    zwolnij(a);
    return b;
}
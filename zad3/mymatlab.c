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

float norm(struct macierz m)
{
    float s=0;
    int i,j;

    for(i=0; i<m.r; i++)
        for(j=0; j<m.c; j++)
            s+=m.tab[i][j]*m.tab[i][j];
    return sqrt(s);
}

struct macierz dodaj(struct macierz a, struct macierz x)
{
    if((a.r!=x.r)||(a.c!=x.c))
    {
        printf("Podanych macierzy nie mozna zsumowac.\n");
        exit(-1);
    }
    else
    {
        struct macierz b;
        int i,j;
        b.c=a.c;
        b.r=a.r;
        for(i=0; i<a.r; i++)
            for(j=0; j<a.c; j++)
                b.tab[i][j]=a.tab[i][j]+x.tab[i][j];
        return b;
    }
}

struct macierz odejmij(struct macierz a, struct macierz x)
{
    if((a.r!=x.r)||(a.c!=x.c))
    {
        printf("Podanych macierzy nie mozna odjac.\n");
        exit(-2);
    }
    else
    {
        struct macierz b;
        int i,j;
        b.c=a.c;
        b.r=a.r;
        for(i=0; i<a.r; i++)
            for(j=0; j<a.c; j++)
                b.tab[i][j]=a.tab[i][j]-x.tab[i][j];
        return b;
    }
}

struct macierz prod(struct macierz a, struct macierz x)
{
    if(a.c!=x.r)
    {
        printf("Podanych macierzy nie mozna wymnozyc.\n");
        exit(-3);
    }
    else
    {
        struct macierz b;
        int i,j;
        b.r=a.r;
        b.c=x.c;
        for(i=0;i<b.r;i++)
            for(j=0;j<b.c;j++)
            {
                b.tab[i][j]=0;
                for(int k=0;k<a.c;k++)
                    b.tab[i][j]+=a.tab[i][k]*x.tab[k][j];
            }
        return b;
    }
}

struct macierz multi(struct macierz a, float x)
{
    struct macierz b;
    int i,j;
    b.c=a.c;
    b.r=a.r;
    for(i=0; i<a.r; i++)
            for(j=0; j<a.c; j++)
                b.tab[i][j]=a.tab[i][j]*x;
    return b;
}

void zapisz(char nazwa[], struct macierz m)
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

int main(int argc, char *argv[])
{
    char s1[]="sum";
    char s2[]="subtract";
    char s3[]="prod";
    char s4[]="multiply";
    char s5[]="norm";

    if(strcmp(s1,argv[1])==0)
    {
        FILE *fin1;
        FILE *fin2;
        struct macierz A, x, b;
        fin1=fopen(argv[2], "r");
        fin2=fopen(argv[3], "r");
        wczytaj(fin1, &A);
        wczytaj(fin2, &x);
        b=dodaj(A,x);
        fclose(fin1);
        fclose(fin2);
        if(argc==5)
        {
            zapisz(argv[4], b);
        }
        else
        {
            wypisz(b);
        }
        
    }
    else if(strcmp(s2,argv[1])==0)
    {
        FILE *fin1;
        FILE *fin2;
        struct macierz A, x, b;
        fin1=fopen(argv[2], "r");
        fin2=fopen(argv[3], "r");
        wczytaj(fin1, &A);
        wczytaj(fin2, &x);
        b=odejmij(A,x);
        fclose(fin1);
        fclose(fin2);
        if(argc==5)
        {
            zapisz(argv[4], b);
        }
        else
        {
            wypisz(b);
        }
    }
    else if(strcmp(s3,argv[1])==0)
    {
        FILE *fin1;
        FILE *fin2;
        struct macierz A, x, b;
        fin1=fopen(argv[2], "r");
        fin2=fopen(argv[3], "r");
        wczytaj(fin1, &A);
        wczytaj(fin2, &x);
        b=prod(A,x);
        fclose(fin1);
        fclose(fin2);
        if(argc==5)
        {
            zapisz(argv[4], b);
        }
        else
        {
            wypisz(b);
        }
    }
    else if(strcmp(s4,argv[1])==0)
    {
        FILE *fin;
        struct macierz A, b;
        float x;
        fin=fopen(argv[2], "r");
        wczytaj(fin, &A);
        x=atof(argv[3]);
        b=multi(A,x);
        fclose(fin);
        if(argc==5)
        {
            zapisz(argv[4], b);
        }
        else
        {
            wypisz(b);
        }
    }
    else if(strcmp(s5,argv[1])==0)
    {
        FILE *fin;
        struct macierz A;
        float n;
        fin=fopen(argv[2], "r");
        wczytaj(fin, &A);
        n=norm(A);
        fclose(fin);
        if(argc==4)
        {
            FILE *fout = fopen(argv[3], "w");
            fprintf(fout, "%f\n", n);
            fclose(fout);
        }
        else
        {
            printf("Norma macierzy %s = %f\n", argv[1], n);
        }
    }
    else
    {
        printf("Nie rozpoznano komendy. Oczekiwalem: sum/subtract/prod/multiply/norm\n");
        exit(-99);
    }

    return 0;
}
#include "dzialania.h"

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
        macierz A, x, b;
        fin1=fopen(argv[2], "r");
        fin2=fopen(argv[3], "r");
        wczytaj(fin1, &A);
        wczytaj(fin2, &x);
        b=dodaj(&A,x);
        fclose(fin1);
        fclose(fin2);
        if(argc==5)
        {
            zapisz(argv[4], b);
            zwolnij(&b);
        }
        else
        {
            wypisz(b);
            zwolnij(&b);
        }
        
    }
    else if(strcmp(s2,argv[1])==0)
    {
        FILE *fin1;
        FILE *fin2;
        macierz A, x, b;
        fin1=fopen(argv[2], "r");
        fin2=fopen(argv[3], "r");
        wczytaj(fin1, &A);
        wczytaj(fin2, &x);
        b=odejmij(&A,x);
        fclose(fin1);
        fclose(fin2);
        if(argc==5)
        {
            zapisz(argv[4], b);
            zwolnij(&b);
        }
        else
        {
            wypisz(b);
            zwolnij(&b);
        }
    }
    else if(strcmp(s3,argv[1])==0)
    {
        FILE *fin1;
        FILE *fin2;
        macierz A, x, b;
        fin1=fopen(argv[2], "r");
        fin2=fopen(argv[3], "r");
        wczytaj(fin1, &A);
        wczytaj(fin2, &x);
        b=prod(&A,&x);
        fclose(fin1);
        fclose(fin2);
        if(argc==5)
        {
            zapisz(argv[4], b);
            zwolnij(&b);
        }
        else
        {
            wypisz(b);
            zwolnij(&b);
        }
    }
    else if(strcmp(s4,argv[1])==0)
    {
        FILE *fin;
        macierz A, b;
        float x;
        fin=fopen(argv[2], "r");
        wczytaj(fin, &A);
        x=atof(argv[3]);
        b=multi(&A,x);
        fclose(fin);
        if(argc==5)
        {
            zapisz(argv[4], b);
            zwolnij(&b);
        }
        else
        {
            wypisz(b);
            zwolnij(&b);
        }
    }
    else if(strcmp(s5,argv[1])==0)
    {
        FILE *fin;
        macierz A;
        float n;
        fin=fopen(argv[2], "r");
        wczytaj(fin, &A);
        n=norm(A);
        fclose(fin);
        if(argc==4)
        {
            FILE *fout = fopen(argv[3], "w");
            fprintf(fout, "Norma macierzy %s = %f\n", argv[2], n);
            fclose(fout);
        }
        else
        {
            printf("Norma macierzy %s = %f\n", argv[2], n);
        }
    }
    else
    {
        printf("Nie rozpoznano komendy. Oczekiwalem: sum/subtract/prod/multiply/norm\n");
        exit(-99);
    }

    return 0;
}
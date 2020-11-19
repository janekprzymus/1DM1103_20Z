#include "studenci.h"

int wczytaj(student dane[100], char *fnazwa) {
    FILE *fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].przedmiot[0], w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].przedmiot[1], w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        strncpy(dane[i].przedmiot[2], w, 1);
    }

    fclose(fin);
    return cnt;
}


void wypisz_stud(student dane[100], int n) {
    int i;
    for (i=0; i<n;i++) {
        printf("{ Student: %s - %s %s, z przedmiotu: [%s] %s za ECTS: %s otrzymał %.1f\n",
            dane[i].nr_albumu, dane[i].imie, dane[i].nazwisko,
            dane[i].przedmiot[0], dane[i].przedmiot[1],
            dane[i].przedmiot[2], dane[i].ocena
        );
    }
}

int znajdz(char *szukany_kod, char kody[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_kod, kody[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_przedmioty(char kody[100][10], char nazwy[100][255], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].przedmiot[0], kody, ile_znalazlem ) == -1) {
            strncpy(kody[ile_znalazlem], dane[i].przedmiot[0], 9);
            strncpy(nazwy[ile_znalazlem], dane[i].przedmiot[1], 254);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}

int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].nr_albumu, nr_albumow, ile_znalazlem ) == -1) {
            strncpy(nr_albumow[ile_znalazlem], dane[i].nr_albumu, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}
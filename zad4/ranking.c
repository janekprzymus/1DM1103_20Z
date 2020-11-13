/**
Mamy mini bazę studentów (tabelę z studentami, przedmiotami i ocenami)
Cel: obliczyć ranking przedmiotów pod względem średnich wyników.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char przedmiot[3][255];
    float ocena;
} student, *pstudent;

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

void wypisz(student dane[100], int n) {
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

void najlepszy_przedmiot(student dane[100], int ile_rekordow) {
    char kody[100][10];
    char nazwy[100][255];
    int sumy_ects[100];
    int ile_przedmiotow;
    float sumy_wazonych_ocen[100];
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;
    int najgorsza_pozycja;
    float najgorsza;

    ile_przedmiotow = znajdz_przedmioty(kody, nazwy, dane, ile_rekordow);

    for(i=0; i<100; i++){
        sumy_wazonych_ocen[i]=0;
        sumy_ects[i]=0;
    }

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz(dane[i].przedmiot[0], kody, ile_przedmiotow);
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * atoi(dane[i].przedmiot[2]);
        sumy_ects[pozycja] += atoi(dane[i].przedmiot[2]);
    }    

    for (i=0;i<ile_przedmiotow; i++) 
        printf("Przedmiot [%d]: %s (%s) - %f:%d - %f \n", i+1, kody[i], nazwy[i],
        sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    najgorsza=sumy_wazonych_ocen[0] / sumy_ects[0];
    for (i=0; i < ile_przedmiotow; i++) {
        if (najgorsza > sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najgorsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najgorsza_pozycja = i;
        }
    }
    printf("**********************************\n");
    printf("Najlepsza srednia: ");
    printf("Przedmiot [%d]: %s - %s: %f\n", 
        najlepsza_pozycja+1, kody[najlepsza_pozycja], nazwy[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );
    printf("Najgorsza srednia: ");
    printf("Przedmiot [%d]: %s - %s: %f\n", 
        najgorsza_pozycja+1, kody[najgorsza_pozycja], nazwy[najgorsza_pozycja],
        sumy_wazonych_ocen[najgorsza_pozycja] / sumy_ects[najgorsza_pozycja]
    );
}

int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    // dane == &dane[0]
    ile = wczytaj(dane, argv[1]);
    wypisz(dane, ile);
    char lel[100][10];
    char lol[100][255];
    int x=znajdz_przedmioty(lel, lol, dane, ile);
    printf("Znalazlem %d przedmiotow.\n", x);
    najlepszy_przedmiot(dane, ile);
    return 0;
}
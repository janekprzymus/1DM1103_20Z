#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *nast;
} Student;

// typedef struct _Przedmiot {
//     char * imie;
//     char * nazwisko;
//     char * nr_albumu;
//     char * email;

//     struct _Student *nast;
// } Przedmiot;

// typedef struct _Ocena {
//     char * nr_albumu;
//     char * kod_przedmiotu;

//     float ocena;
//     char * koentarz;

//     struct _Student *nast;
// } Ocena;


typedef struct _SBaza {
    Student *lista_studentow; /* Głowa listy! */
} SBaza;

SBaza * wczytaj_baze(char *nazwa_pliku);
SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza);
void listuj_studentow(SBaza *baza);
void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);

#endif
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

    struct _Student *poprz;
    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
     char * kod;
     char * nazwa;
     char * sem;

     struct _Przedmiot *poprz;
     struct _Przedmiot *nast;
} Przedmiot;

typedef struct _Ocena {
    char * nr_albumu;
    char * kod_przedmiotu;
    char * ocena;
    char * komentarz;

    struct _Ocena *poprz;
    struct _Ocena *nast;
} Ocena;


typedef struct _SBaza {
    Student *lista_studentow; /* Głowa listy! */
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} SBaza;

Student * wczytaj_studentow(FILE *fin);
Przedmiot * wczytaj_przedmioty(FILE *fin);
Ocena * wczytaj_oceny(FILE *fin);
SBaza * wczytaj_baze(char *nazwa_pliku);
SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza);
void dodaj_studenta(SBaza *baza, char *nimie, char *nnazwisko, char *nnr_albumu, char *nemail);
void dodaj_przedmiot(SBaza *baza, char *nkod, char *nnazwa, char *nsem);
void dodaj_ocene(SBaza *baza, char *nkod, char *nalbum, char *nocena, char *nkomentarz);
void listuj_studentow(SBaza *baza);
void listuj_przedmioty(SBaza *baza);
void listuj_oceny(SBaza *baza);
void listuj_studentow_od_konca(SBaza *baza);
int ile_studentow(SBaza *baza);
int ile_przedmiotow(SBaza *baza);
int ile_ocen(SBaza *baza);
void zwolnij_student(Student *s);
void zwolnij_przedmiot(Przedmiot *p);
void zwolnij_ocena(Ocena *o);
void zwolnij_liste_studentow(Student *s);
void zwolnij_liste_przedmiotow(Przedmiot *p);
void zwolnij_liste_ocen(Ocena *o);
void zwolnij(SBaza *baza);
Student * sortuj_malejaco(Student *glowa);
Student * sortuj_rosnaco(Student *glowa);
Przedmiot * sortuj_alfabetycznie_po_kodzie(Przedmiot *glowa);
Przedmiot * sortuj_alfabetycznie_po_nazwie(Przedmiot *glowa);
void wypisz_oceny_przedmiotu(SBaza * baza, char *kod_p);
void wypisz_oceny_studenta(SBaza * baza, char *nr);

#endif
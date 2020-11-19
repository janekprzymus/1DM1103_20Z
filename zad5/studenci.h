#ifndef STUDENCI_H
#define STUDENCI_H

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

int wczytaj(student dane[100], char *fnazwa);
void wypisz_stud(student dane[100], int n);
int znajdz(char *szukany_kod, char kody[100][10], int n);
int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);
int znajdz_przedmioty(char kody[100][10], char nazwy[100][255], student dane[100], int n);

#endif
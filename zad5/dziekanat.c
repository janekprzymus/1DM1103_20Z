#include "dziekanat.h"

void najlepszy_przedmiot(student dane[100], int ile_rekordow) {
    char kody[100][10];
    char nazwy[100][255];
    int sumy_ects[100];
    int ile_przedmiotow;
    float sumy_wazonych_ocen[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

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
    printf("\nNajlepsza srednia: ");
    printf("Przedmiot [%d]: %s - %s: %f\n", 
        najlepsza_pozycja+1, kody[najlepsza_pozycja], nazwy[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );
}

void najgorszy_przedmiot(student dane[100], int ile_rekordow) {
    char kody[100][10];
    char nazwy[100][255];
    int sumy_ects[100];
    int ile_przedmiotow;
    float sumy_wazonych_ocen[100];
    int i;
    int pozycja;
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

    najgorsza=sumy_wazonych_ocen[0] / sumy_ects[0];
    for (i=0; i < ile_przedmiotow; i++) {
        if (najgorsza > sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najgorsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najgorsza_pozycja = i;
        }
    }
    printf("\nNajgorsza srednia: ");
    printf("Przedmiot [%d]: %s - %s: %f\n", 
        najgorsza_pozycja+1, kody[najgorsza_pozycja], nazwy[najgorsza_pozycja],
        sumy_wazonych_ocen[najgorsza_pozycja] / sumy_ects[najgorsza_pozycja]
    );
}

void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for(i=0; i<100; i++){
        sumy_wazonych_ocen[i]=0;
        sumy_ects[i]=0;
    }
    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nr_albumu, nr_albumow, ile_studentow );
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * atoi(dane[i].przedmiot[2]);
        sumy_ects[pozycja] += atoi(dane[i].przedmiot[2]);
    }    

    for (i=0;i<ile_studentow; i++) 
        printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
        sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

}
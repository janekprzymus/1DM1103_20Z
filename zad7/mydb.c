#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

int main(int argc, char ** argv) {
    SBaza *baza;
    baza = wczytaj_baze(argv[1]);

    if (strcmp("count_students", argv[2]) == 0) {
        printf("Liczba studentów: %d\n", ile_studentow(baza));
    } else if (strcmp("list", argv[2]) == 0) {
        if(strcmp("students", argv[3])==0){
        listuj_studentow(baza);
        } else if(strcmp("courses", argv[3])==0){
            listuj_przedmioty(baza);
        } else if(strcmp("grades", argv[3])==0) {
            listuj_oceny(baza);
        }
    } else if (strcmp("add", argv[2]) == 0) {
        if(strcmp("student", argv[3]) == 0){
            dodaj_studenta(baza, argv[4], argv[5], argv[6], argv[7]);
        } else if(strcmp("course", argv[3]) == 0){
            dodaj_przedmiot(baza, argv[4], argv[5], argv[6]);
        } else if(strcmp("grade", argv[3]) == 0){
            dodaj_ocene(baza, argv[4], argv[5], argv[6], argv[7]);
        }    /*else if(strcmp("student_to_course", argv[3]) == 0){
            dodaj_studenta_do_przedmiotu(baza, argv[4], argv[5]);
        }  */
    }

    zapisz_baze(argv[1], baza);
    zwolnij(baza);
    return 0;
}
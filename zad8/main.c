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
        } else if(strcmp("students_from_end", argv[3])==0){
            listuj_studentow_od_konca(baza);
        } else if(strcmp("grades_by_course", argv[3])==0){
            wypisz_oceny_przedmiotu(baza, argv[4]);
        } else if(strcmp("grades_by_student", argv[3])==0){
            wypisz_oceny_studenta(baza, argv[4]);
        }
    } else if (strcmp("add", argv[2]) == 0) {
        if(strcmp("student", argv[3]) == 0){
            dodaj_studenta(baza, argv[4], argv[5], argv[6], argv[7]);
        } else if(strcmp("course", argv[3]) == 0){
            dodaj_przedmiot(baza, argv[4], argv[5], argv[6]);
        } else if(strcmp("grade", argv[3]) == 0){
            dodaj_ocene(baza, argv[4], argv[5], argv[6], argv[7]);
        }
    } else if (strcmp("sort", argv[2]) == 0) {
        if(strcmp("students", argv[3]) == 0){
            if(strcmp("descending", argv[4]) == 0){
                baza->lista_studentow = sortuj_malejaco(baza->lista_studentow); 
                listuj_studentow(baza);
            } else if(strcmp("ascending", argv[4]) == 0){
                baza->lista_studentow = sortuj_rosnaco(baza->lista_studentow);
                listuj_studentow(baza);
            }
        } else if(strcmp("courses", argv[3]) == 0){
            if(strcmp("by_code", argv[4]) == 0){
                baza->lista_przedmiotow = sortuj_alfabetycznie_po_kodzie(baza->lista_przedmiotow);
                listuj_przedmioty(baza);
            } else if(strcmp("by_name", argv[4]) == 0){
                baza->lista_przedmiotow = sortuj_alfabetycznie_po_nazwie(baza->lista_przedmiotow);
                listuj_przedmioty(baza);
            }
        }
    }

    zapisz_baze(argv[1], baza);
    zwolnij(baza);
    return 0;
}
#include "dziekanat.h"

int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);
    printf("Wczytano następujące dane:\n");
    wypisz_stud(dane, ile);
    printf("***************************\n");
    char *arg1="best_stud";
    char *arg2="best_przed";
    char *arg3="worst_przed";
    
    if(strcmp(argv[2], arg1)==0){
        najlepszy_student(dane, ile);
    }
    else if(strcmp(argv[2], arg2)==0){
        najlepszy_przedmiot(dane, ile);
    }
    else if(strcmp(argv[2], arg3)==0){
        najgorszy_przedmiot(dane, ile);
    }
    else
    {
        printf("Nie rozpoznano polecenia.\n");
        exit(-2);
    }
    return 0;
}
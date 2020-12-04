#include "baza.h"

Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}

Przedmiot * wczytaj_przedmioty(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Przedmiot *last_przedmiot = NULL;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Przedmiot *przedm = (Przedmiot*) malloc(sizeof(Przedmiot));
        przedm->nast = NULL;

        if (last_przedmiot == NULL)
            glowa = przedm;
        else
            last_przedmiot->nast = przedm;
        last_przedmiot = przedm;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przedm->kod = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedm->kod, s);

        s = strtok(NULL, ";");
        przedm->nazwa = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedm->nazwa, s);

        s = strtok(NULL, "\n");
        przedm->sem = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedm->sem, s);
    }

    return glowa;
}

Ocena * wczytaj_oceny(FILE *fin){
    char bufor[255];
    int n, i;
    char *s;
    Ocena *last_grade = NULL;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Ocena *grade = (Ocena*) malloc(sizeof(Ocena));
        grade->nast = NULL;

        if (last_grade == NULL)
            glowa = grade;
        else
            last_grade->nast = grade;
        last_grade = grade;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        grade->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(grade->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        grade->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(grade->nr_albumu, s);

        s = strtok(NULL, ";");
        grade->ocena = (char*) malloc(sizeof(char) * (strlen(s) +1));
        strcpy(grade->ocena, s);

        s = strtok(NULL, "\n");
        grade->komentarz = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(grade->komentarz, s);
    }

    return glowa;
}

SBaza * wczytaj_baze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);
    baza->lista_ocen = wczytaj_oceny(fin);

    fclose(fin);
    return baza;
}

int ile_studentow(SBaza *baza) {
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}
/*
int ile_studentow_w_kursie(Przedmiot *course){
    int n=0;
    Student *stud = course->lista_studentow;
    while(stud != NULL){
        n++;
        stud = stud->nast;
    }
    return n;
}*/

int ile_przedmiotow(SBaza *baza) {
    int n = 0;
    Przedmiot * przedm = baza->lista_przedmiotow;
    while (przedm != NULL) {
        n++;
        przedm = przedm->nast;
    }
    return n;
}

int ile_ocen(SBaza *baza) {
    int n = 0;
    Ocena * grade= baza->lista_ocen;
    while (grade != NULL) {
        n++;
        grade = grade->nast;
    }
    return n;
}

SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza) {
    FILE *fout = fopen(nazwa_pliku, "w");
    Student * stud = baza->lista_studentow;
    Przedmiot *przedm = baza->lista_przedmiotow;
    Ocena *grade = baza->lista_ocen;

    fprintf(fout, "%d\n", ile_studentow(baza));
    while (stud != NULL) {
        fprintf(fout, "%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
    fprintf(fout, "%d\n", ile_przedmiotow(baza));
    while (przedm != NULL){
        fprintf(fout, "%s;%s;%s\n", przedm->kod, przedm->nazwa, przedm->sem);
        przedm = przedm->nast;
    }
    fprintf(fout, "%d\n", ile_ocen(baza));
    while (grade != NULL){
        fprintf(fout, "%s;%s;%s;%s\n", grade->kod_przedmiotu, grade->nr_albumu, grade->ocena, grade->komentarz);
        grade = grade->nast;
    }
    fclose(fout);
    return NULL;
}

void dodaj_studenta(SBaza *baza, char *nimie, char *nnazwisko, char *nnr_albumu, char *nemail){
    Student *new_stud=(Student*) malloc(sizeof(Student));
    new_stud->nast=NULL;
    new_stud->imie = (char*) malloc( sizeof(char) * (strlen(nimie) + 1));
    strcpy(new_stud->imie, nimie);
    new_stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(nnazwisko) + 1));
    strcpy(new_stud->nazwisko, nnazwisko);
    new_stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(nnr_albumu) + 1));
    strcpy(new_stud->nr_albumu, nnr_albumu);
    new_stud->email = (char*) malloc( sizeof(char) * (strlen(nemail) + 1));
    strcpy(new_stud->email, nemail);

    if(ile_studentow(baza)==0)
        baza->lista_studentow=new_stud;
    else{
    Student *temp=NULL;
    temp=baza->lista_studentow->nast;
    for(int i=0;i<ile_studentow(baza)-2;i++)
        temp=temp->nast;
    
    temp->nast=new_stud;
    }
}

void dodaj_przedmiot(SBaza *baza, char *nkod, char *nnazwa, char *nsem){
    Przedmiot *new_course=(Przedmiot*) malloc(sizeof(Przedmiot));
    new_course->nast=NULL;
    new_course->kod = (char*) malloc(sizeof(char) * (strlen(nkod) + 1));
    strcpy(new_course->kod, nkod);
    new_course->nazwa = (char*) malloc(sizeof(char) * (strlen(nnazwa) + 1));
    strcpy(new_course->nazwa, nnazwa);
    new_course->sem = (char*) malloc(sizeof(char) * (strlen(nsem) + 1));
    strcpy(new_course->sem, nsem);

    if(ile_przedmiotow(baza)==0)
        baza->lista_przedmiotow=new_course;
    else{
    Przedmiot *temp=NULL;
    temp=baza->lista_przedmiotow->nast;
    for(int i=0;i<ile_przedmiotow(baza)-2;i++)
        temp=temp->nast;

    temp->nast=new_course;
    }
}

void dodaj_ocene(SBaza *baza, char *nkod, char *nalbum, char *nocena, char *nkomentarz){
    Ocena *nowa_ocena=(Ocena*) malloc(sizeof(Ocena));
    nowa_ocena->nast=NULL;
    nowa_ocena->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(nkod) + 1));
    strcpy(nowa_ocena->kod_przedmiotu, nkod);
    nowa_ocena->nr_albumu = (char*) malloc( sizeof(char) * (strlen(nalbum) + 1));
    strcpy(nowa_ocena->nr_albumu, nalbum);
    nowa_ocena->ocena = (char*) malloc( sizeof(char));
    strcpy(nowa_ocena->ocena, nocena);
    nowa_ocena->komentarz = (char*) malloc( sizeof(char) * (strlen(nkomentarz) + 1));
    strcpy(nowa_ocena->komentarz, nkomentarz);

    if(ile_ocen(baza)==0)
        baza->lista_ocen=nowa_ocena;
    else{
    Ocena *temp=NULL;
    temp=baza->lista_ocen->nast;
    for(int i=0;i<ile_ocen(baza)-2;i++)
        temp=temp->nast;
    
    temp->nast=nowa_ocena;
    }
}

/*
void dodaj_studenta_do_przedmiotu(SBaza *baza, char *albumstud, char *kodprz){
    int i, spr=0;

    if(ile_przedmiotow(baza)==0){
        printf("BŁĄD: lista przedmiotow jest pusta!\n");
        exit(-5);
    }

    Student *stud=NULL;
    stud=baza->lista_studentow;
    for(i=0;i<ile_studentow(baza);i++){
        if(strcmp(stud->nr_albumu, albumstud)==0){
            spr++;
            break;
        }
        else
        {
            stud=stud->nast;
        }
    }
    if(spr==0){
        printf("BŁĄD: nie znaleziono studenta o podanym nr albumu!\n");
        exit(-54);
    }
    
    spr=0;
    Przedmiot *course=NULL;
    course=baza->lista_przedmiotow;
    for(i=0;i<ile_przedmiotow(baza);i++){
        if(strcmp(course->kod, kodprz)==0){
            spr++;
            break;
        }
        else
        {
            course=course->nast;
        }
    }
    if(spr==0){
        printf("BŁĄD: nie znaleziono przedmiotu o podanym kodzie!\n");
        exit(-55);
    }

    if(course->lista_studentow==NULL){
        course->lista_studentow=stud;
    }
    else
    {
        Student *tempp=NULL;
        tempp=course->lista_studentow;
        for(i=0;i<ile_studentow_w_kursie(course)-1;i++){
            tempp=tempp->nast;
        }
        tempp->nast=stud;
    }

}
*/
void listuj_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void listuj_przedmioty(SBaza *baza) {
    Przedmiot * przedm = baza->lista_przedmiotow;
    while (przedm != NULL) {
        printf("%s %s %s\n", przedm->kod, przedm->nazwa, przedm->sem);
        przedm = przedm->nast;
    }
}

void listuj_oceny(SBaza *baza) {
    Ocena * grade = baza->lista_ocen;
    while (grade != NULL) {
        printf("%s %s %s %s\n", grade->kod_przedmiotu, grade->nr_albumu, grade->ocena, grade->komentarz);
        grade = grade->nast;
    }
}
/*
void listuj_studentow_na_kursie(SBaza *baza, char *kodprz){
    int i, spr=0;
    Przedmiot *course=NULL;
    course=baza->lista_przedmiotow;
    for(i=0;i<ile_przedmiotow(baza);i++){
        if(strcmp(course->kod, kodprz)==0){
            spr++;
            break;
        }
        else
        {
            course=course->nast;
        }
    }
    if(spr==0){
        printf("BŁĄD: nie znaleziono przedmiotu o podanym kodzie!\n");
        exit(-55);
    }

    Student *stud = course->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}*/

void zwolnij_student(Student *s) {
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_przedmiot(Przedmiot *p) {
    free(p->kod);
    free(p->nazwa);
    free(p->sem);
    free(p);
}

void zwolnij_ocena(Ocena *o) {
    free(o->kod_przedmiotu);
    free(o->nr_albumu);
    free(o->ocena);
    free(o->komentarz);
    free(o);
}

void zwolnij_liste_studentow(Student *s) {
    Student *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_liste_przedmiotow(Przedmiot *p) {
    Przedmiot *n;
    while (p != NULL) {
        n = p->nast;
        zwolnij_przedmiot(p);
        p = n;
    }
}

void zwolnij_liste_ocen(Ocena *o){
    Ocena *n;
    while (o != NULL) {
        n = o->nast;
        zwolnij_ocena(o);
        o = n;
    }
}

void zwolnij(SBaza *baza) {
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}

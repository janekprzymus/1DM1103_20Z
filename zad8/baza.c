#include "baza.h"
// rekurencja
void wypisz_rekurencyjnie(Student *el) {
    if (el != NULL) {
        printf("%s %s %s %s\n", el->imie, el->nazwisko, el->nr_albumu, el->email);        
        wypisz_rekurencyjnie( el->nast );
    }
}

Student * ostatni_student(Student *glowa) {
    Student *el = glowa;
    if (el != NULL) {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}

Student * usun_studenta(Student *glowa, Student *el) {
    Student *c = glowa;
    if (glowa == el) {
        glowa = glowa->nast;
    } else {
        while (c != NULL) {
            if (c == el) {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;

                break;
            }

            c = c->nast;
        }
    }
    c->nast = NULL;
    c->poprz = NULL;
    return glowa;
}

Student * najwiekszy_student(Student *el) {
    Student * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->nazwisko, max->nazwisko) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Student * najmniejszy_student(Student *el) {
    Student * min = NULL;
    while (el != NULL) {
        if (min == NULL) {
            min = el;
        } else {
            if ( strcmp(el->nazwisko, min->nazwisko) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

Student * sortuj_malejaco(Student *glowa) {
    Student * nglowa = NULL;
    Student * m;
    Student * o; // = NULL;

    while (glowa != NULL) {
        m = najwiekszy_student(glowa);
        glowa = usun_studenta(glowa, m);
        
        o = ostatni_student(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}

Student * sortuj_rosnaco(Student *glowa) {
    Student * nglowa = NULL;
    Student * m;
    Student * o; // = NULL;

    while (glowa != NULL) {
        m = najmniejszy_student(glowa);
        glowa = usun_studenta(glowa, m);
        
        o = ostatni_student(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}

Student * zwroc_stud(Student *glowa, int i) {
    while (glowa != NULL && i-- > 0) // i jest zmniejszany postfixowo - czyli po porownaniu z 0
        glowa = glowa->nast;    
    
    return glowa;
}

void listuj_studentow_od_konca(SBaza *b) {
     //Student *ogon = ostatni(b->lista_studentow);
    Student *c;/*
    while (c != NULL) {

        c = c->poprz;
    }

     for (c=ogon; c != NULL; c = c->poprz) {
         printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);        
     }*/

    int i;
    int n = ile_studentow(b);
    for (i=(n-1); i >= 0; i--) {
        c = zwroc_stud(b->lista_studentow, i);
        printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);        
    }
}




// rekurencja
void wypisz_rekurencyjnie_od_konca(Student *el) {
    if (el != NULL) {
        wypisz_rekurencyjnie( el->nast );
        printf("%s %s %s %s\n", el->imie, el->nazwisko, el->nr_albumu, el->email);        
    }
}

Przedmiot * ostatni_przedmiot(Przedmiot *glowa) {
    Przedmiot *el = glowa;
    if (el != NULL) {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}

Przedmiot * usun_przedmiot(Przedmiot *glowa, Przedmiot *el) {
    Przedmiot *c = glowa;
    if (glowa == el) {
        glowa = glowa->nast;
    } else {
        while (c != NULL) {
            if (c == el) {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;

                break;
            }

            c = c->nast;
        }
    }
    c->nast = NULL;
    c->poprz = NULL;
    return glowa;
}


Przedmiot * najmniejszy_przedmiot_po_kodzie(Przedmiot *el) {
    Przedmiot * min = NULL;
    while (el != NULL) {
        if (min == NULL) {
            min = el;
        } else {
            if ( strcmp(el->kod, min->kod) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

Przedmiot * najmniejszy_przedmiot_po_nazwie(Przedmiot *el) {
    Przedmiot * min = NULL;
    while (el != NULL) {
        if (min == NULL) {
            min = el;
        } else {
            if ( strcmp(el->nazwa, min->nazwa) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

Przedmiot * sortuj_alfabetycznie_po_kodzie(Przedmiot *glowa) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) {
        m = najmniejszy_przedmiot_po_kodzie(glowa);
        glowa = usun_przedmiot(glowa, m);
        
        o = ostatni_przedmiot(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
    }

    return nglowa;
}

Przedmiot * sortuj_alfabetycznie_po_nazwie(Przedmiot *glowa) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) {
        m = najmniejszy_przedmiot_po_nazwie(glowa);
        glowa = usun_przedmiot(glowa, m);
        
        o = ostatni_przedmiot(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
    }

    return nglowa;
}

Ocena * ostatnia_ocena(Ocena *glowa) {
    Ocena *el = glowa;
    if (el != NULL) {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}


Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    Student *c;

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;
        stud->poprz = NULL;

        if (glowa == NULL)
            glowa = stud;
        else {
            c = ostatni_student(glowa);
            c->nast = stud;
            stud->poprz = c;
        }

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
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    Przedmiot *c;

    for (i=0; i<n; i++) {
        Przedmiot *przedm = (Przedmiot*) malloc(sizeof(Przedmiot));
        przedm->nast = NULL;
        przedm->poprz = NULL;

        if (glowa == NULL)
            glowa = przedm;
        else {
            c = ostatni_przedmiot(glowa);
            c->nast = przedm;
            przedm->poprz = c;
        }

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
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    Ocena *c;

    for (i=0; i<n; i++) {
        Ocena *grade = (Ocena*) malloc(sizeof(Ocena));
        grade->nast = NULL;
        grade->poprz = NULL;

        if (glowa == NULL)
            glowa = grade;
        else {
            c = ostatnia_ocena(glowa);
            c->nast = grade;
            grade->poprz = c;
        }

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        grade->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(grade->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        grade->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(grade->nr_albumu, s);

        s = strtok(NULL, ";");
        grade->ocena = (char*) malloc(sizeof(char) * (strlen(s) + 1));
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

void wypisz_oceny_przedmiotu(SBaza * baza, char *kod_p){
    int i, n=ile_ocen(baza), ile=0;
    Ocena * glowa = baza->lista_ocen;

    for(i=0; i<n; i++){
        if(strcmp(glowa->kod_przedmiotu, kod_p) == 0){
            printf("%s %s %s %s\n", glowa->kod_przedmiotu, glowa->nr_albumu, glowa->ocena, glowa->komentarz);
            ile++;
        }
        glowa=glowa->nast;
    }
    if(ile==0){
        printf("Nie znaleziono ocen z przedmiotu o podanym kodzie. Brak ocen lub błędny kod.\n");
    }
}

void wypisz_oceny_studenta(SBaza * baza, char *nr){
    int i, n=ile_ocen(baza), ile=0;
    Ocena * glowa = baza->lista_ocen;

    for(i=0; i<n; i++){
        if(strcmp(glowa->nr_albumu, nr) == 0){
            printf("%s %s %s %s\n", glowa->kod_przedmiotu, glowa->nr_albumu, glowa->ocena, glowa->komentarz);
            ile++;
        }
        glowa=glowa->nast;
    }
    if(ile==0){
        printf("Nie znaleziono ocen studenta o podanym numerze. Brak ocen lub błędny identyfikator.\n");
    }
}

void listuj_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }

//    wypisz_rekurencyjnie(baza->lista_studentow);
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

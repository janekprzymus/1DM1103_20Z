
1. Podział na pliki nagłówkowe i źródłowe
2. Plik Makefile
3. Dynamiczna alokacja pamięci.
4. Valgrind (make test)


PLik z mainem powinien:
a) zawierac glowny scenariusz dzialania programu
b) powinien interpretowac komendy uzytkownika (argumenty linii komend)
c) przeksztalcac argumenty linii komend z postaci tekstowej do postaci meta danych (floaty, double, int, tablice struktury...)
d) powinien wyswietlac wyniki uzytkownikowi (nie musi formatowac!!!,
ale to main decyduje co ma zostac wyswietlone uzytkownikowi)

MAKRODYREKTYWY

#include <stdio.h>

#define MAX 200

#ifdef MAX
    printf("%d\n", 1+MAX);
#else
    printf("%d\n", 201);
#endif

extern - przy deklaracji zmiennej oznacza ze to jest deklaracja a nie definicja,
    wiec deinicje musimy zrobic  w jakims pliku *.c.


Podziel na trzy moduły:
1. main.c
2. studenci.c
3. dziekanat.c

Program ma mieć argument linii komend, za pomocą któego mozemy wybrać co 
chcemy policzyć (czy najlepszy student, czy najtrudniejszy przedmiot).

Utworz makefile
    * budowanie programu %.o:%.c
    * clean

Jako wynik załącz do ISODa archiwum repozytoirum ZIP.
Proszę zmodyfikować program do zarządzania bazą studentów tak aby:

1. Umożliwiał wyświetlanie posortowanej rosnąco i malejąco (alfabetycznie) po nazwisku wwszystkich studentów w bazie.
2. Umożliwiał wyświetlenie listy przedmiotów posortowanych alfabetycznie po kodzie przedmiotu.
3. Umożliwiał wyświetlenie listy przedmiotów posortowanych alfabetycznie po nazwie przedmiotu.
4. Umożliwiał wyświetlenie listy ocen z przedmiotu o zadanym kodzie.
5. Umożliwiał wyświetlenie listy wszystkich ocen danego studenta.

Proszę zaprojektować odpowiednie parametry przekazywane do programu main w momencie uruchomienia programu. Proszę samodzielnie wybrać metodę sortowania oraz wyświetlania.

Sugeruję, że przyda się, żebyście zaimplementowali sobie następujące funkcje:

Ad.1: to jest kalka z seminarium - powinno pójść łatwo, metodą Copiego i Pasty.
Ad.2: to jest kalka z seminarium - powinno pójść łatwo, metodą Copiego i Pasty tylko dla innych struktur danych.
Ad.3: to jest kalka z seminarium - powinno pójść łatwo, metodą Copiego i Pasty tylko dla innych struktur danych.
Ad.4. Sugeruję napisanie funkcji:

```c
Przedmiot * filtruj(Przedmiot * glowa, char *kod_przedmiotu) {
    // tutaj powinniście utworzyć nową listę i dodać do niej wszystkie elementy,
    // ktore pasuja do zadanego kodu....
    return nowa_glowa;
}
```

Ad.5. Sugeruję napisanie funkcji:

```c
Ocena * filtruj(Ocena * glowa, char *nr_albumu) {
    // tutaj powinniście utworzyć nową listę i dodać do niej wszystkie elementy,
    // ktore pasuja do zadanego numeru albumu....
    return nowa_glowa;
}
```

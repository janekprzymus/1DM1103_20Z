#ifndef DZIALANIA_H
#define DZIALANIA_H

#include "przetwarzanko.h"

float norm(macierz m);
macierz dodaj(macierz *a, macierz x);
macierz odejmij(macierz *a, macierz x);
macierz prod(macierz *a, macierz *x);
macierz multi(macierz *a, float x);

#endif
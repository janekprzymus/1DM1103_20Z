#include <stdio.h>

int main()
{
    int i,j;
    int *p;   /* a pointer to an integer */
    p = &i;
    *p=5;
    j=i;
    char * n = "Ala ma kota";
    int tab[4] = {3,4,5,6};
    int *t = tab;
    t = &tab[0];
    printf("%d %d %d %p %ld\n", i, j, *p, p, p);
    printf("%s\n", n);
    printf("%s\n", &(*(n+3)));
    printf("%d\n", *(t+3));
    
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 255

int main(int argc, char**argv) {
    //char n[MAX];
    char *n;
    int i;
    int rozmiar = 0;

    for (i=1; i<argc; i++) {
        rozmiar += strlen(argv[i]) + 1;
    }

    n = (char*) malloc( (rozmiar+1) * sizeof(char)); // jedynka ze wzgledu na zero na koncu napisu

    strcpy(n, argv[1]);
    for (i=2; i<argc; i++) {
        strcat(n, " ");
        strcat(n, argv[i]);
    }

    printf("%s %s %s\n", argv[1], argv[2], argv[3]);
    printf("%s\n", n);

    free(n);
    
    return 0;
}
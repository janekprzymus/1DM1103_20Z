#include <stdio.h>

int main(int argc, char**argv) {
    char *n = "ala ma kota";
    printf("%s\n", ((n+4))+1);
    printf("%c\n", *((((++n) +4))));

    return 0;
}
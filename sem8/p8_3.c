#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 255

typedef struct _mat {
    float **data;
    int r;
    int c;
} mat;

int main(int argc, char **argv) {
    int i,j;
    mat * ms; // moja struktura
    ms = (mat*) malloc(sizeof(mat));
    ms->r = 2;
    ms->c = 3;

    ms->data = (float**) malloc(sizeof(float*) * ms->r);
    for (i=0;i<ms->r;i++) {
        ms->data[i] = (float*) malloc(sizeof(float) * ms->c);
        for (j=0;j< ms->c; j++)
            ms->data[i][j] = j+1+i;
    }

    for (i=0;i<ms->r;i++) {
        for(j=0;j<ms->c;j++)
            printf("%f ", ms->data[i][j]);
        printf("\n");
    }

    for (i=0;i<ms->r;i++) 
        free( ms->data[i] );
    free(ms->data);
    free(ms);

    // printf("%p\n", data[1])
    return 0;
}
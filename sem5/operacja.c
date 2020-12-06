#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    float a=atof(argv[2]);
    float b=atof(argv[3]);
    char s1[]="dodaj";
    char s2[]="mnoz";
    if(strcmp(s1,argv[1])==0)
    {
        printf("%f\n",a+b);
    }
    if(strcmp(s2,argv[1])==0)
    {
        printf("%f\n",a*b);
    }
    if((strcmp(s1,argv[1])!=0)&&(strcmp(s2,argv[1])!=0))
    {
        printf("Niewlasciwa komenda\n");
        exit(-1);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string>

int main()
{

int *p = (int *) malloc(sizeof(int));

    *p = 1000;
    printf("%i \n", *p);
    return 0;

}
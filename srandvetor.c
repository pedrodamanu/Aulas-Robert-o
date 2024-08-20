#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main ()
{
    srand((unsigned)time(NULL));
    int vetA[N], i;
    
    for (i = 0; i < N; i++)
    {
        vetA[i] = rand() % 100 + 1;
    }
    for (i = 0; i < N; i++)
    {
        printf("%d\t", vetA[i]);
    }
}
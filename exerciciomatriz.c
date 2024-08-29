#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5

int main () 
{
    srand((unsigned)time(NULL));
    int mat[M][M], i, j;
    for (i = 0; i < M; i++)
    {
        for(j = 0; j < M; j++)
        {
            mat[i][j] = rand() % 100;
        }
    }
    for (i = 0; i < M; i++)
    {
        for(j = 0; j < M; j++)
        {
            if (j == i)
            {
                printf("%d\n", mat[i][j]);
            }
        }
    }
}
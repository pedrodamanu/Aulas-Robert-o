#include <stdio.h>
#define N 5

int main ()
{
    int vetA[N], vetB[N], vetC[N], i;
    
    for (i = 0; i < N; i++)
    {
        printf("Digite um valor para as posiçoes %d dos vetores: \n", i);
        scanf("%d%d", &vetA[i], &vetB[i]);
    }
    for (i = 0; i < N; i++)
    {
        vetC[i] = vetA[i] + vetB[i];
    }
    for (i = 0; i < N; i++)
    {
        printf("%d ", vetC[i]);
    }
}
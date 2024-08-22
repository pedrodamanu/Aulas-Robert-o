#include <stdio.h>
#define N 10

int main ()
{
    int vet[N], i, res = 0;
    printf("Digite 10 elementos: \n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &vet[i]);
        res += vet[i];
    }
    printf("A soma eh: %d\n", res);
}
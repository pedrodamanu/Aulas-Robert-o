#include <stdio.h>
#define N 15

int main ()
{
    int vet[N], i, aux1, aux2;
    printf("Digite 10 elementos: \n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &vet[i]);
        aux1 = vet[i];
    }
    printf("A media eh: %d\n");
}
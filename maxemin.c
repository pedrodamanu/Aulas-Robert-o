#include <stdio.h>
#define N 15

int main ()
{
    int vet[N], i, aux1 = -2147483648, aux2 = 2147483647;
    printf("Digite 10 elementos: \n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &vet[i]);
        if (aux1 < vet[i])
        {
            aux1 = vet[i];
        }
        if (aux2 > vet[i])
        {
            aux2 = vet[i];
        }
    }
    printf("O menor numero eh %d e o maior eh %d\n", aux2, aux1);
}
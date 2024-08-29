#include <stdio.h>
#define N 5
#define M 10

int main()
{
    int vet[N], vet2[N], vet3[M], i, j = 0;
    for (i = 0; i < N; i++)
    {
        printf("Digite dois numeros para a posicao %d dos vetores: \n", i);
        scanf("%d%d", &vet[i], &vet2[i]);
    }
    for (i = 0; i < M; i ++)
    {
        if (i % 2 == 0)
        {
            vet3[i] = vet[j];
        }
        else
        {
            vet3[i] = vet2[j];
            j++;
        }
    }
    for (i = 0; i < M; i++)
    {
        printf("%d ", vet3[i]);
    }
}
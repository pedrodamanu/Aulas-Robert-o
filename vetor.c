#include <stdio.h>
#define N 5

int main ()
{
    int vetA[N];
    int i, res = 0;
    printf("Digite um valor: ");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &vetA[i]);
    }
    for (i = 0; i < N; i++)
    {
        res += vetA[i];
    }
    printf("%d\n", res);
}
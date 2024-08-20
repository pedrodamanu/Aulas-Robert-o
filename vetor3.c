#include <stdio.h>
#define N 5

int main ()
{
    int vetA[N], i = 0;
    
    while(i < N)
    {
        printf("Digite um valor para a posiçao %d do vetor: \n", i);
        scanf("%d", &vetA[i]);
        if (vetA[i] >= 0)
        {
            i++;
        }
    }
}
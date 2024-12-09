#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K, aux = 0, res = 0;
    scanf("%d%d", &N, &K);
    int x[N], i, j = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &x[i]);
        if (x[i] > K)
        {
            i--;
        }
    }
    while (j < N)
    {
        for (i = 0; i < N; i++)
        {
            while (aux < K)
            {
                if (x[i] == aux)
                {
                    x[i] = 0;
                    j++;
                    aux++;
                    break;
                }
            }
        }
    }
}
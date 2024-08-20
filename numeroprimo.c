#include <stdio.h>

int main ()
{
    int num, div = 1, prim, aux = 0;
    printf("digite um numero: ");
    scanf("%d", &num);
    if(num > 0)
    {
        while (div <= num)
        {
            prim = num % div;
            div++;
            if (prim == 0)
            {
                aux++;
            }
        }
        if (aux == 2)
        {
            printf("o numero eh primo\n");
        }
        else
        {
             printf("o numero nao eh primo\n");
        }
    }
    else
    {
        printf("valor invalido\n");
    }
}
#include<stdio.h>

int main()
{
    int a, b, soma = 0, par1;
    printf("Digite dois valores:");
    scanf("%d%d", &a, &b);
    printf("\nOs pares são: ");
    while(b <= a)
    {
        if (b % 2 == 0)
        {
            par1 = b;
            printf("%d ", par1);
            soma += par1;
            b += 2;
        }
        else 
        {
            b++;
        }
    }
    while(a <= b)
    {
        if (a % 2 == 0)
        {
            par1 = a;
            printf("%d ", par1);
            soma += par1;
            a += 2;
        }
        else 
        {
            a++;
        }
    }
    printf("\nA soma eh %d\n", soma);
}
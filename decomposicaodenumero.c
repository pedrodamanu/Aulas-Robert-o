#include <stdio.h>
#include <math.h>

int main()
{
    int num, aux = 1;
    printf("digite um numero: ");
    scanf("%d", &num);
    num = num / 100;
    while (num > 0)
    {
        num = pow(num, aux);
        printf("%d", num);
    }
} 
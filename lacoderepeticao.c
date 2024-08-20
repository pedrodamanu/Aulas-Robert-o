#include <stdio.h>

int main ()
{
    float a = 1, soma = 0, b = 0, c = 1;
    while(b <= 0)
    {
        printf("Digite um valor: \n");
        scanf("%f", &b);
    }
    while (a <= b)
    {
        if((int)a % 2 == 0)
        {
            soma -= c/a;
            a++;
        }
        else
        {
            soma += c/a;
            a++;
        }
    }
    printf ("%.2f ", soma);
}
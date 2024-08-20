#include <stdio.h>

int main ()
{
    float a = 1, soma = 0, b = 0, c = 1, aux =-1;
    while(b <= 0)
    {
        printf("Digite um valor: \n");
        scanf("%f", &b);
    }
    while (a <= b)
    {
        c *= aux;
        soma -= c/a;
        a++;
    }
    printf ("%.2f ", soma);
}
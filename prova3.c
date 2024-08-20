#include <stdio.h>

int main()
{
    float raio, vol;
    printf("Digite o raio da esfera: \n");
    scanf("%f", &raio);
    if (raio > 0)
    {
        vol = (4/3.00) * 3.14 * (raio * raio * raio);
        printf ("O volume eh: %.2f", vol);
    }
    else
    {
        printf("valor invalido\n");
    }
}
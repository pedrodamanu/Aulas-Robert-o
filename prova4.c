#include <stdio.h>

int main()
{
    int num, cent, dez, uni;
    printf("Digite um numero: \n");
    scanf("%d", &num);
    if (num < 0 || num >= 1000)
    {
        printf("numero invalido\n");
    }
    else
    {
        if (num < 10)
        {
            uni = num;
            printf ("%d = %d unidades", num, uni);
        }
        else
        {
            if (num >= 10 && num < 100)
            {
                dez = num/10;
                uni = (num - (dez * 10));
                printf("%d = %d dezenas e %d unidades\n", num, dez, uni);
            }
            else
            {
                cent = num / 100;
                dez = (num - (cent * 100)) / 10;
                uni = (num - (dez * 10) - (cent * 100));
                printf("%d = %d centenas, %d dezenas, %d unidades\n", num, cent, dez, uni);
            }
        }
    }
}
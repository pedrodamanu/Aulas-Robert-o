#include <stdio.h>

int main()
{
    int seq, aux1 = 2, aux2 = 1, aux3 = 1, aux4 = 1;
    printf("digite um numero: ");
    scanf("%d", &seq);
    if (seq > 0)
    {
        printf("1 ");
        while (aux1 <= seq)
        {
            aux1++;
            printf("%d ", aux4);
            aux4 = aux2 + aux3;
            if (aux1 % 2 == 0)
            {
                aux3 = aux4;
            }
            else
            {
                aux2 = aux4;
            }
        }
    }
    else
    {
        printf("valor invalido \n");
    }
}
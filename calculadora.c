#include <stdio.h>

int main()
{
    int op;
    printf("Selecione a operaçao:\n 1)Adição\n 2)Subtração\n 3)Multiplicação\n 4)Divisao\n ");
    scanf("%d", &op);
    if (op > 0 && op <= 4)
    {
        if (op == 1)
        {
            float som1, som2, res1;
            printf("Digite dois valores: ");
            scanf("%f%f", &som1, &som2);
            res1 = som1 + som2;
            printf("O resultado eh %.2f\n", res1);
        }
        else if (op == 2)
        {
            float sub1, sub2, res2;
            printf("Digite dois valores: ");
            scanf("%f%f", &sub1, &sub2);
            res2 = sub1 - sub2;
            printf("O resultado eh %.2f\n", res2);
        }
        else if (op == 3)
        {
            float mul1, mul2, res3;
            printf("Digite dois valores: ");
            scanf("%f%f", &mul1, &mul2);
            res3 = mul1 * mul2;
            printf("O resultado eh %.2f\n", res3);
        }
        else if (op == 4)
        {
            float div1, div2, res4;
            printf("Digite dois valores: ");
            scanf("%f%f", &div1, &div2);
            if (div2 == 0)
            {
                printf("valor invalido\n");
            }
            else
            {
                res4 = div1 / div2;
                printf("O resultado eh %.2f\n", res4);
            }
        }
    }
    else
    {
        printf("numero invalido\n");
    }
}
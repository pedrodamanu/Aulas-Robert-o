#include <stdio.h>

int main()
{
    int menu;
    float saldo = 0, aux;
    printf("Seu saldo eh %.2f\n", saldo);
    printf("(1) Saque \n(2) Deposito \n(3) Sair");
    scanf("%d", &menu);
    if (menu < 3 && menu >= 0)
    {
        while (menu != 0)
        {
            if (menu == 1)
            {
                printf("Digite o valor que voce quer sacar: ");
                scanf("%f\n", &aux);
                saldo -= aux;
                printf("Seu saldo agora eh %.2f\n", saldo);
            }
            else
            {
                printf("Digite o valor que voce quer depositar: ");
                scanf("%f", &aux);
                saldo += aux;
                printf("Seu saldo agora eh %.2f\n", saldo);
            }
        }
        printf("Programa encerrado\n");
    }
    else 
    {
        printf("Valor invalido\n");
    }
}
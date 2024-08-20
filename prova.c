#include <stdio.h>

int main()
{
    int  idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    if (idade<=0)
    {
        printf("Valor invalido\n");
    }
    else
    {
        if(idade>=16)
        {
            printf("Voce pode votar\n");
        }
        else 
        {
            printf("Voce nao pode votar\n");
        }
    }
}
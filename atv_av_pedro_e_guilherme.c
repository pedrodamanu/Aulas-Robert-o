#include <stdio.h>

//Pedro Rodrigo Miranda dos Santos, Guilherme Dias Borille

void azul(int dias);
void verde(int dias);
void laranja(int dias);
void vermelho(int dias);

int main()
{
    int cor = 1, dias;
    printf("Digite a cor do seu cd: \n");
    printf("1) Azul \n");
    printf("2) Verde \n");
    printf("3) Laranja \n");
    printf("4) Vermelho \n");
    scanf("%d", &cor);
    while(cor <= 1 || cor >= 5)
    {
        printf("Valor invalido, tente novamente: ");
        scanf("%d", &cor);
    }
    printf("Digite o numero de dias: ");
    scanf("%d", &dias);
    while(dias <= 0)
    {
        printf("Valor invalido, tente novamente: ");
        scanf("%d", &dias);
    }
    switch (cor)
    {
        case 1:
            azul(dias);
            break;
        case 2:
            verde(dias);
            break;
        case 3:
            laranja(dias);
            break;
        case 4:
            vermelho(dias);
            break;
    }
}
void azul(int dias)
{

    int aux;
    aux = 10 * dias;
    if (dias > 15)
    {
        aux -= aux / 10;
    }
    else if (dias > 5)
    {
        aux -= aux / 20;
    }
    printf("O valor total eh R$%d\n", aux);

    
}
void verde(int dias)
{
    int aux;
    aux = 15 * dias;
    if (dias > 10)
    {
        printf("Numero de dias invalido\n");
    }
    else 
    {
        printf("O valor total eh R$%d\n", aux);
    }
}
void laranja(int dias)
{
    int aux;
    aux = 20 * dias;
    if (dias > 10)
    {
        aux += (aux / 10) * (dias - 10);
    }
    printf("O valor total eh R$%d\n", aux);
}
void vermelho(int dias)
{
    int aux;
    aux = 25 * dias;
    if (dias > 10)
    {
        aux = (25 * 10) + (7.5 * (dias - 10));
    }
    printf("O valor total eh R$%d\n", aux);
}
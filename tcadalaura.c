#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menuprincipal();
int menuamigo();
int adicionaramigo();
int excluiramigo();
int editaramigo();

typedef struct
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct
{
    char *nome;
    char *apelido;
    char *email;
    TData data;
} Tamigo;

int numAmigo = 0;
Tamigo *amigos;
char strAux[100];
int main()
{
    menuprincipal();
}
void menuprincipal()
{
    int op;
    printf("menu principal:\n 1-manter amigo\n 2-manter local\n 3-manter categoria\n 4-manter encontro\n 5-manter encontro\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        menuamigo();
        break;
    }
}
int menuamigo()
{
    int op1;
    printf("você escolheu manter amigo:\n 1-adicionar amigo\n 2-editar amigo\n 3-excluir amigo\n 4-listar amigos\n");
    scanf("%d", &op1);
    switch (op1)
    {
    case 1:
        adicionaramigo();
        break;
    case 2:
        editaramigo();
        break;
    case 3:
        excluiramigo();
        break;
    }
}
int adicionaramigo()
{
    int fov;
    printf("você escolheu adicionar amigo\n");
    if (numAmigo == 0)
    {
        amigos = (Tamigo *)malloc(1 * sizeof(Tamigo));
    }
    else
    {
        amigos = (Tamigo *)realloc(amigos, (numAmigo + 1) * sizeof(Tamigo));
    }
    printf("Qual o nome do amigo?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigos[numAmigo].nome, strAux);
    printf("%s\n", amigos[numAmigo].nome);
    printf("Qual o apelido do seu amigo:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigos[numAmigo].apelido, strAux);
    printf("%s\n", amigos[numAmigo].apelido);
    printf("Qual o email do seu amigo\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigos[numAmigo].email, strAux);
    printf("%s\n", amigos[numAmigo].email);
    printf("Digite a data de nascimento do seu amigo (dia mês ano):\n");
    scanf("%d %d %d", &amigos[numAmigo].data.dia, &amigos[numAmigo].data.mes, &amigos[numAmigo].data.ano);
    printf(" %02d/%02d/%04d\n", amigos[numAmigo].data.dia, amigos[numAmigo].data.mes, amigos[numAmigo].data.ano);
    numAmigo++;
    printf("Quer retornar pro menu principal(1) ou finalizar(0)?\n");
    scanf("%d", &fov);
    if (fov == 1)
    {
        menuprincipal();
    }
    else
    {
        printf("programa finalizado!");
        return 0;
    }
}
int editaramigo()
{
    int encontrado, dado;
    printf("Qual o nome do amigo que você quer editar?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    for (int i = 0; i < numAmigo; i++)
    {
        int aux = strcmp(amigos[i].nome, strAux);
        if (aux == 0)
        {
            encontrado = 1;
            printf("amigo %s encontrado\n", amigos[i].nome);
            printf("dados do amigo:\n nome(1):%s\n apelido(2):%s\n email(3):%s\n data de nascimento(4):\n", amigos[i].nome, amigos[i].apelido, amigos[i].email);
            printf("qual dado você quer editar?\n");
            scanf("%d", &dado);
            switch (dado)
            {
            case 1:
                printf("digite o novo nome:\n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                amigos[i].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(amigos[i].nome, strAux);
                printf("%s\n", amigos[i].nome);

            case 2:
                printf("digite o novo apelido:\n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                amigos[i].apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(amigos[i].apelido, strAux);
                printf("%s\n", amigos[i].apelido);
                break;

            case 3:
                printf("digite o novo email:\n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                amigos[i].email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(amigos[i].email, strAux);
                printf("%s\n", amigos[i].email);
                break;

            case 4:
                printf("digite a nova data e nascimento:\n");
                scanf("%d %d %d", &amigos[i].data.dia, &amigos[i].data.mes, &amigos[i].data.ano);

                printf(" %02d/%02d/%04d\n", amigos[i].data.dia, amigos[i].data.mes, amigos[i].data.ano);

                break;
            }
        }
    }
}

int excluiramigo()
{
    char nome[100];
    int i, j, fov;
    int encontrado = 0;

    printf("Qual o nome do amigo que você quer excluir?\n ");
    fflush(stdin);
    gets(nome);
    for (i = 0; i < numAmigo; i++)
    {
        int aux = strcmp(amigos[i].nome, nome);
        if (aux == 0)
        { // Encontrou o amigo
            encontrado = 1;
            printf("amigo %s encontrado, excluindo\n", amigos[i].nome);

            // Liberar a memória alocada para o amigo
            free(amigos[i].nome);
            free(amigos[i].apelido);
            free(amigos[i].email);

            // Deslocar os elementos à esquerda para "remover" o amigo
            for (j = i; j < numAmigo - 1; j++)
            {
                amigos[j] = amigos[j + 1];
            }
            amigos = (Tamigo *)realloc(amigos, (numAmigo - 1) * sizeof(Tamigo));
            numAmigo--;
            printf("amigo excluido!\n");
            break;
        }
    }

    if (!encontrado)
    {
        printf("amigo não encontrado!\n");
        return 0;
    }
    printf("Quer retornar pro menu principal(1) ou finalizar(0)?");
    scanf("%d", &fov);
    if (fov == 1)
    {
        menuprincipal();
    }
    else
    {
        printf("programa finalizado!");
        return 0;
    }
}
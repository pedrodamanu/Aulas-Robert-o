#include <stdio.h>
#define N 100
#define C 4
#define T 2

typedef struct 
{
    int dia;
    int mes;
    int ano;
} Tdata;

typedef struct 
{
    char nome[N];
    float coeficiente;
    char conceito[C];
    Tdata dtNas; 
} TAluno;

int main()
{
    TAluno turma23[C], turma24[C];
    int i, j;
    printf("BEM VINDO!\n");
    for (i = 0; i < C; i++)
    {
        printf("Digite o nome do aluno %d de info23:\n", i + 1);
        gets(turma23[i].nome);
    }
    for (i = 0; i < C; i++)
    {
        printf("Agora, digite o nome do aluno %d de info24:\n", i + 1);
        gets(turma24[i].nome);
        fflush(stdin);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    for (i = 0; i < C; i++)
    {
        j = 0;
        while(j < C)
        {
            printf("Digite o conceito %d do aluno ", j + 1);
            puts(turma23[i].nome);
            scanf(" %c", &turma23[i].conceito[j]);
            fflush(stdin);
            if(turma23[i].conceito[j] == 'A' || turma23[i].conceito[j] == 'B' || turma23[i].conceito[j] == 'C' || turma23[i].conceito[j] == 'D')
            {
                j++;
            }
            else
            {
                printf("Valor invalido!!\n");
            }
        }
    }
    for (i = 0; i < C; i++)
    {
        j = 0;
        while(j < C)
        {
            printf("Digite o conceito %d do aluno ", j + 1);
            puts(turma24[i].nome);
            scanf(" %c", &turma24[i].conceito[j]);
            fflush(stdin);
            if(turma24[i].conceito[j] == 'A' || turma24[i].conceito[j] == 'B' || turma24[i].conceito[j] == 'C' || turma24[i].conceito[j] == 'D')
            {
                j++;
            }
            else
            {
                printf("Valor invalido!!\n");
            }
        }
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(i = 0; i < C; i++)
    {
        printf("Digite o coeficiente do aluno ");
        puts(turma23[i].nome);
        scanf("%f", &turma23[i].coeficiente);
    }
    for(i = 0; i < C; i++)
    {
        printf("Digite o coeficiente do aluno ");
        puts(turma24[i].nome);
        scanf("%f", &turma24[i].coeficiente);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(i = 0; i < C; i++)
    {
        printf("Digite a data de nascimento do aluno ");
        puts(turma23[i].nome);
        scanf("%d%d%d", &turma23[i].dtNas.dia, &turma23[i].dtNas.mes, &turma23[i].dtNas.ano);
    }
    for(i = 0; i < C; i++)
    {
        printf("Digite a data de nascimento do aluno ");
        puts(turma24[i].nome);
        scanf("%d%d%d", &turma24[i].dtNas.dia, &turma24[i].dtNas.mes, &turma24[i].dtNas.ano);
    }
}
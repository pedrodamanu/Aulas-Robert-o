#include <stdio.h>
#define N 100
#define C 4
#define T 2

int valide_data(int dias, int mes, int ano);

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
    int i, j, aux;
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
    
    i = 0;
    while(i < C)
    {
        printf("Digite a data de nascimento do aluno ");
        puts(turma23[i].nome);
        scanf("%d%d%d", &turma23[i].dtNas.dia, &turma23[i].dtNas.mes, &turma23[i].dtNas.ano);
        aux = valide_data(turma23[i].dtNas.dia, turma23[i].dtNas.mes, turma23[i].dtNas.ano);
        if(aux == 1)
        {
            i++;
        }
        else
        {
            printf("Data invalida!!!\n");
        }
    }
    i = 0;
    for(i = 0; i < C; i++)
    {
        printf("Digite a data de nascimento do aluno ");
        puts(turma24[i].nome);
        scanf("%d%d%d", &turma24[i].dtNas.dia, &turma24[i].dtNas.mes, &turma24[i].dtNas.ano);
        aux = valide_data(turma24[i].dtNas.dia, turma24[i].dtNas.mes, turma24[i].dtNas.ano);
        if(aux == 1)
        {
            i++;
        }
        else
        {
            printf("Data invalida!!!\n");
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("")
}

int valide_data(int dias, int mes, int ano)
{
    if (mes > 12 || mes <= 0)
    {
        return 0;
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if (dias <= 0 || dias > 31)
        {
            return 0;
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dias <= 0 || dias > 30)
        {
            return 0;
        }
    }
    if (ano % 4 == 0 && mes == 2)
    {
        if (dias <= 0 || dias > 29)
        {
            return 0;
        }
    }
    else if (mes == 2)
    {
        if (dias <= 0 || dias > 28)
        {
            return 0;
        }
    }
    return 1;
}
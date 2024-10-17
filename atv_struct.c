#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NT 4


typedef struct
{
    char *nome_mat;
    float notas[NT];
} TMateria;
typedef struct 
{
    char *nome;    
    TMateria *grade;
    int numMat;
} TAluno;

TAluno criaAluno();
int criaTurma();
void printaAluno();

TAluno *info24;
int numAluno;

int main()
{
    if(criaTurma() == 0)
    {
        printf("VALOR INVALIDO!\n");
    }
    printf("\n\n");
    printaAluno();
    free(info24);
}

int criaTurma()
{
    int i;
    char strAux[100]; 
    printf("BEM VINDO!!!!\n");
    printf("Digite o numero de alunos: ");
    scanf("%d", &numAluno);
    if(numAluno <= 0)
    {
        return 0;
    }
    info24 = (TAluno *)malloc(numAluno * sizeof(TAluno));
    for(i = 0; i < numAluno; i++)
    {
        info24[i] = criaAluno();
    }
}
TAluno criaAluno()
{
    TAluno aluno;
    char strAux[100];
    int i, j, k;
    __fpurge(stdin);
    printf("Digite o nome do aluno\n");
    gets(strAux);
    __fpurge(stdin);
    aluno.nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(aluno.nome, strAux);
    printf("Digite o numero de disciplinas: ");
    scanf("%d", &aluno.numMat);
    aluno.grade = (TMateria *)malloc(aluno.numMat * sizeof(TMateria));
    for(j = 0; j < aluno.numMat; j++)
    {
        __fpurge(stdin);
        printf("Digite o nome da materia %d:", j + 1);
        gets(strAux);
        __fpurge(stdin);
        aluno.grade[j].nome_mat = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(aluno.grade[j].nome_mat, strAux);
        for(k = 0; k < NT; k++)
        {
            printf("Digite a nota %d ", k + 1);
            scanf("%f", &aluno.grade[j].notas[k]);
        }
    }
    return aluno;
}

void printaAluno()
{
    int i, j, k;
    for (i = 0; i < numAluno; i++)
    {
        printf("NOME DO ALUNO: ");
        puts(info24[i].nome);
        for(j = 0; j < info24[i].numMat; j++)
        {
            printf("DESEMPENHO EM :");
            puts(info24[i].grade[j].nome_mat);
            for(k = 0; k < NT; k++)
            {
                printf("NOTAS: ");
                printf("%.2f, ", info24[i].grade[j].notas[k]);
            }
        }
        printf("\n");
    }
}

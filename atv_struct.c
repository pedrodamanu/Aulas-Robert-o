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

int main()
{
    TAluno *info24;
    int i, j, k, numAluno;
    char strAux[100]; 
    printf("BEM VINDO!!!!\n");
    printf("Digite o numero de alunos: ");
    scanf("%d", &numAluno);
    if(numAluno > 0)
    {
        info24 = (TAluno *)malloc(numAluno * sizeof(TAluno));
        for(i = 0; i < numAluno; i++)
        {
            __fpurge(stdin);
            printf("Digite o nome do aluno %d\n", i + 1);
            gets(strAux);
            __fpurge(stdin);
            info24[i].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(info24[i].nome, strAux);
            printf("Digite o numero de disciplinas: ");
            scanf("%d", &info24[i].numMat);
            info24[i].grade = (TMateria *)malloc(info24[i].numMat * sizeof(TMateria));
            for(j = 0; j < info24[i].numMat; j++)
            {
                __fpurge(stdin);
                printf("Digite o nome da materia %d:", j + 1);
                gets(strAux);
                __fpurge(stdin);
                info24[i].grade[j].nome_mat = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(info24[i].grade[j].nome_mat, strAux);
                for(k = 0; k < NT; k++)
                {
                    printf("Digite a nota %d ", k + 1);
                    scanf("%f", &info24[i].grade[j].notas[k]);
                }
            }
        }
    }
}
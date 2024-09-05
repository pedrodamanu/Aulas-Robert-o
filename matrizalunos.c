#include <stdio.h>
#define L 5
#define N 4
#define C 100
#define M 5

int main()
{
    char nome[L][C];
    float nota[L][N], med[M], aux = 0;
    int i, j, k, n;
    printf("Digite o nome dos alunos: ");
    for (i = 0; i < L; i++)
    {
        gets(nome[i]);
        __fpurge(stdin);
    }
    for (i = 0; i < L; i++)
    {
        aux = 0;
        printf("Digite a nota do aluno ");
        puts(nome[i]);
        j = 0;
        while (j < N)
        {
            scanf("%f", &nota[i][j]);
            aux += nota[i][j];
            if (nota[i][j] >= 0 && nota[i][j] <= 10)
            {
                j++;
            }
            else
            {
                printf("Uma das notas eh invalida, reescreva elas\n");
            }
        }
        for (k = 1; k < N; k++)
        {
            for (j = 0; j < N - k; j++)
            {
                if (nota[i][j] > nota[i][j + 1])
                {
                    aux = nota[i][j];
                    nota[i][j] = nota[i][j + 1];
                    nota[i][j + 1] = aux;
                }
            }
        }
        med[i] = aux / 4;
    }
    for (i = 0; i < L; i++)
    {
        printf("ALUNO: ");
        puts(nome[i]);
        printf("NOTAS: ");
        for (j = 0; j < N; j++)
        {
            printf("%.1f, ", nota[i][j]);
        }
        printf("\nMEDIA: %.2f\n", med[i]);
        if (med[i] >= 7)
        {
            printf("APROVADO\n\n");
        }
        else if(med[i] >= 4 && med[i] < 7)
        {
            printf("RECUPERAÇÃO\n\n");
        }
        else
        {
            printf("REPROVADO\n\n");
        }
    }
}

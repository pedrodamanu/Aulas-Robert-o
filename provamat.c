#include <stdio.h>
#define A 4
#define B 3
#define C 2
#define L 100 
void leralunos24();
void leralunos23();
void lercoef(); 
void reler();
void nasc();
void lercon23(int bim);
void lercon24(int bim);
int validarconceito23(int i, int j);
int validarconceito24(int i, int j);        
int validecoef(int coef);
int valide_data(int dias, int mes, int ano);

char conc23[A][A], conc24[A][A];
int coef[C][A];

int main ()
{
    char alunos24[A][L], alunos23[A][L];
    int i, j = 0, aux, nasc23[A][B], nasc24[A][B], res, maior = 0;
    float med1 = 0, med2 = 0, med3 = 0;
    leralunos23();
    for (i = 0; i < A; i++)
    {
        gets(alunos23[i]);
        __fpurge(stdin);
    }
    leralunos24();
    for (i = 0; i < A; i++)
    {
        gets(alunos24[i]);
        __fpurge(stdin);
    }
    for(i = 0; i < A; i++)
    {
        j = 0;
        while(j < A)
        {
            lercon23(j);
            puts(alunos23[i]);
            scanf("%c", &conc23[i][j]);
            __fpurge(stdin);
            aux = validarconceito23(i, j);
            if (aux == 1)
            {
                j++;
            }
        }
    }
    for(i = 0; i < A; i++)
    {
        j = 0;coef[C][A];
        while(j < A)
        {
            lercon24(j);
            puts(alunos24[i]);
            scanf("%c", &conc24[i][j]);
            __fpurge(stdin);
            aux = validarconceito24(i, j);
            if (aux == 1)
            {
                j++;
            }
        }
    }
    for(i=0; i<A; i++)//info23
    {
        nasc();
        puts (alunos23[i]);
        scanf("%d%d%d", &nasc23[i][0], &nasc23[i][1], &nasc23[i][2]);
        res = valide_data(nasc23[i][0], nasc23[i][1], nasc23[i][2]);
        while (res == 0)
        {
            reler();
            scanf("%d%d%d", &nasc23[i][0], &nasc23[i][1], &nasc23[i][2]);
            res = valide_data(nasc23[i][0], nasc23[i][1], nasc23[i][2]);
        }
    }
    for(i=0; i<A; i++)//info24
    {
        nasc();
        puts (alunos24[i]);
        scanf("%d%d%d", &nasc24[i][0], &nasc24[i][1], &nasc24[i][2]);
        res = valide_data(nasc24[i][0], nasc24[i][1], nasc24[i][2]);
        while (res == 0)
        {
            reler();
            scanf("%d%d%d", &nasc24[i][0], &nasc24[i][1], &nasc24[i][2]);
            res = valide_data(nasc24[i][0], nasc24[i][1], nasc24[i][2]);
        }
    }
    for (i = 0; i < C; i++)
    {
        j = 0;
        med3 = 0;
        while (j < A)
        {
            lercoef();
            if (i == 0)
            {
                puts(alunos23[j]);
            }
            else
            {
                puts(alunos24[j]);
            }
            scanf("%d", &coef[C][A]);
            aux = validecoef(coef[C][A]);
            if (aux == 1)
            {
                j++;
            }
            med3 += coef[C][A];
            if (j == 3)
            {
                med1 = med3 / 4;
            }
            if (j == 7)
            {
                med2 = med3 / coef[A][C];
            }
        }
    }
    med1 /= 4;
    med2 /= 4;
    for (i = 0; i < C; i++)
    {
        for (j = 0; j < A; j++)
        {
            if (maior < coef[C][A])
            {
                maior = coef[C][A];
            }
        }
    }
    for (i = 0; i < A; i++)
    {
        puts(alunos23[i]);
        printf("NASCIDO EM (%d/%d/%d)\n", nasc23[i][0], nasc23[i][1], nasc23[i][2]);
        printf("OS CONCEITOS FORAM:");
        for (j = 0; j < A; j++)
        {
            printf("%c%c%c%c", conc23[i][j]);
        }
        printf("\nO COEFICIENTE FOI: %d\n\n", coef[0][i]);
    }
    for (i = 0; i < A; i++)
    {
        puts(alunos24[i]);
        printf("NASCIDO EM (%d/%d/%d)\n", nasc24[i][0], nasc24[i][1], nasc24[i][2]);
        printf("OS CONCEITOS FORAM:");
        for (j = 0; j < A; j++)
        {
            printf("%c %c %c %c", conc24[i][j]);
        }
        printf("\nO COEFICIENTE FOI: %d\n\n", coef[1][i]);
    }
    printf("A MEDIA DE INFO23 EH %d\n A MEDIA DE INFO24 EH %d\n\n", med1, med2);
    printf("A MEDIA GERAL FOI %d\n\n", med1 + med2 / 2);
    printf("O MAIOR COEFICIENTE FOI %d\n", maior);
}
void leralunos24()
{
    printf("Digite o nome dos alunos de info 24:\n");
}
void leralunos23()
{
    printf("Digite o nome dos alunos de info 23:\n");
}
void lercon23(int bim)
{
    printf ("Digite o conceito do bimestre %d do aluno ", bim + 1);
}
void lercon24(int bim)
{
    printf ("Digite o conceito do bimestre %d do aluno ", bim + 1);
}
void lercoef()
{
    printf("Digite o coeficiente do aluno ");
}
int validarconceito23(int i, int j)
{
    if(conc23[i][j] == 'A' || conc23[i][j] == 'B' || conc23[i][j] == 'C' || conc23[i][j] == 'D')
    {
        return 1;
    }
    return 0;
}
int validarconceito24(int i, int j)
{
    if(conc24[i][j] == 'A' || conc24[i][j] == 'B' || conc24[i][j] == 'C' || conc24[i][j] == 'D')
    {
        return 1;
    }
    return 0;
}
int validecoef(int coef)
{
    if(coef > 10 || coef < 0)
    {
        return 0;
    }
    return 1;
}
void nasc()
{
    printf("Digite o dia, mes e o ano para a data de nascimento do aluno:");
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
void reler()
{
    printf("Valor invalido, digite outro numero: ");
}
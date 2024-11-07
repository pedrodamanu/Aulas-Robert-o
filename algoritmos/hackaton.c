
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct
{
    char *nome;
    char *nomMat;
    char *conteudo;
    TData data;
    char *atv;
} TProfessor;

typedef struct
{
    char *nome;
    char *turma;
    TData data;
} TAluno;

typedef struct
{
    char *nome;
    char *local;
    char *periodo;
    int vagas;
    char *numero;
    TData data;
} TCarona;

int lerOpcao();
int lerProf();
int lerConteudo();
int lerAluno();
void justificaFalta();
void printarConteudo(int auxAluno);
void printarFaltas();
void lerCarona();
void cadastrarCarona();
void printarCarona();
void escolherAulaAlt();
void alterarAula(int opAula);
void escolherAulaExc();
void excluirAula(int opAula);
void salvarAluno();
void salvarProf();
void salvarCarona();
void recuperarAluno();
void recuperarProf();
void recuperarCarona();
int valide_data(int dias, int mes, int ano);
void liberarPonteiros();

TProfessor *cont;
TAluno *faltas;
TCarona *motorista;
int numProf = -1, numAluno = -1, numCar = -1;

int main()
{
    SetConsoleOutputCP(65001);
    recuperarAluno();
    recuperarProf();
    recuperarCarona();
    int op1 = 1, opProf = 1, opAluno = 1;

    while (op1 != 0)
    {
        op1 = lerOpcao();
        switch (op1)
        {
        case 1:
            opProf = 1;
            while (opProf != 0)
            {
                opProf = lerProf();
                switch (opProf)
                {
                case 1:
                    lerConteudo();
                    break;
                case 2:
                    printarFaltas();
                    break;
                case 3:
                    escolherAulaAlt();
                    break;
                case 4:
                    escolherAulaExc();
                    break;
                }
            }
            break;
        case 2:
            opAluno = 1;
            while (opAluno != 0)
            {
                opAluno = lerAluno();
                switch (opAluno)
                {
                case 1:
                    justificaFalta();
                    break;
                case 2:
                    lerCarona();
                    break;
                }
            }
            break;
        }
    }
    salvarAluno();
    salvarProf();
    salvarCarona();
    liberarPonteiros();
}

int lerOpcao()
{
    int aux;
    printf("Bem vindo!!\n");
    printf("Selecione a opção desejada: \n");
    printf("1) Sou professor\n");
    printf("2) Sou aluno\n");
    printf("0) Encerrar o programa\n");
    scanf("%d", &aux);
    system("cls");
    return aux;
}

int lerProf()
{
    int aux;
    printf("1) Cadastrar aula\n");
    printf("2) Ver faltas\n");
    printf("3) Alterar aula\n");
    printf("4) Excluir aula\n");
    printf("0) Voltar\n");
    scanf("%d", &aux);
    system("cls");
    return aux;
}

int lerConteudo()
{
    int auxDat = 0;
    char strAux[1000];
    numProf++;
    cont = (TProfessor *)realloc(cont, (numProf + 1) * sizeof(TProfessor));

    printf("Digite o seu nome: \n"); // leitura do nome do professor
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    cont[numProf].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(cont[numProf].nome, strAux);

    printf("Digite o nome da sua matéria :\n"); // leitura do nome da materia
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    cont[numProf].nomMat = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(cont[numProf].nomMat, strAux);

    printf("Digite a data da sua aula(DD MM AAAA, sem barras): \n");
    while (auxDat == 0)
    {
        scanf("%d%d%d", &cont[numProf].data.dia, &cont[numProf].data.mes, &cont[numProf].data.ano);
        auxDat = valide_data(cont[numProf].data.dia, cont[numProf].data.mes, cont[numProf].data.ano);
        if (auxDat == 0)
        {
            printf("Valor invalido!\n");
        }
    }
    printf("Digite resumidamente o conteudo que foi lecionado: \n"); // leitura do conteudo
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    cont[numProf].conteudo = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(cont[numProf].conteudo, strAux);

    printf("Digite a atividade pra suprir a falta: \n"); // leitura da atividade
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    cont[numProf].atv = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(cont[numProf].atv, strAux);

    system("cls");
}

int lerAluno()
{
    int aux;
    printf("1) Justificar falta\n");
    printf("2) Caronas\n");
    printf("0) Voltar\n");
    scanf("%d", &aux);
    system("cls");
    return aux;
}

void justificaFalta()
{
    char strAux[100];
    int auxDat = 0;
    numAluno++;
    faltas = (TAluno *)realloc(faltas, (numAluno + 1) * sizeof(TAluno));

    printf("Qual seu nome?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    faltas[numAluno].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(faltas[numAluno].nome, strAux);

    printf("Qual sua turma?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    faltas[numAluno].turma = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(faltas[numAluno].turma, strAux);

    while (auxDat == 0)
    {
        printf("Qual dia você que justificar? (DD MM AAAA, sem barras)\n");
        fflush(stdin);
        scanf("%d %d %d", &faltas[numAluno].data.dia, &faltas[numAluno].data.mes, &faltas[numAluno].data.ano);
        fflush(stdin);
        auxDat = valide_data(faltas[numAluno].data.dia, faltas[numAluno].data.mes, faltas[numAluno].data.ano);
        if (auxDat == 0)
        {
            printf("Valor invalido!\n");
        }
    }
    system("cls");
    printarConteudo(numAluno);
}

void printarConteudo(int auxAluno)
{
    int i = 0, j = 0;
    for (i = 0; i < numProf + 1; i++)
    {
        if (faltas[auxAluno].data.dia == cont[i].data.dia && faltas[auxAluno].data.mes == cont[i].data.mes && faltas[auxAluno].data.ano == cont[i].data.ano)
        {
            printf("Nome do professor: ");
            puts(cont[i].nome);
            printf("Nome da matéria: ");
            puts(cont[i].nomMat);
            printf("Data: %d/%d/%d\n", cont[i].data.dia, cont[i].data.mes, cont[i].data.ano);
            printf("Conteudo lecionado: ");
            puts(cont[i].conteudo);
            printf("Atividade de reposição: ");
            puts(cont[i].atv);
            printf("\n");
            j++;
        }
    }
    if (j == 0)
    {
        printf("Nenhum conteudo no dia selecionado!\n");
    }
}

void printarFaltas()
{
    int i;
    for (i = 0; i < numAluno + 1; i++)
    {
        printf("Nome do aluno: ");
        puts(faltas[i].nome);
        printf("Nome da turma: ");
        puts(faltas[i].turma);
        printf("Data: %d/%d/%d\n\n", faltas[i].data.dia, faltas[i].data.mes, faltas[i].data.ano);
    }
}

void lerCarona()
{
    int opCarona;
    opCarona = 3;
    printf("1) Cadastrar carona\n");
    printf("2) Ver caronas disponiveis\n");
    scanf("%d", &opCarona);
    system("cls");
    switch (opCarona)
    {
    case 1:
        cadastrarCarona();
        break;
    case 2:
        printarCarona();
        break;
    }
}

void cadastrarCarona()
{
    int auxDat = 0;
    char strAux[100];
    numCar++;
    motorista = (TCarona *)realloc(cont, (numCar + 1) * sizeof(TCarona));

    printf("Qual seu nome?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    motorista[numCar].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(motorista[numCar].nome, strAux);

    printf("Qual o local?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    motorista[numCar].local = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(motorista[numCar].local, strAux);

    printf("Qual o periodo/horario da carona?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    motorista[numCar].periodo = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(motorista[numCar].periodo, strAux);

    printf("Tem quantas vagas no carro?\n");
    scanf("%d", &motorista[numCar].vagas);

    while (auxDat == 0)
    {
        printf("Qual a data da carona? (DD MM AAAA, sem barras)\n");
        scanf("%d%d%d", &motorista[numCar].data.dia, &motorista[numCar].data.mes, &motorista[numCar].data.ano);
        auxDat = valide_data(motorista[numCar].data.dia, motorista[numCar].data.mes, motorista[numCar].data.ano);
        if (auxDat == 0)
        {
            printf("Valor invalido!\n");
        }
    }

    printf("Qual seu numero pra contato?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    motorista[numCar].numero = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(motorista[numCar].numero, strAux);

    system("cls");
}

void printarCarona()
{
    int i;
    for (i = 0; i < numCar + 1; i++)
    {
        printf("Nome do motorista: ");
        puts(motorista[i].nome);
        printf("Local da carona: ");
        puts(motorista[i].local);
        printf("Periodo/horario da carona: ");
        puts(motorista[i].periodo);
        printf("Numero de vagas: %d\n", motorista[i].vagas);
        printf("Data: %d/%d/%d\n", motorista[numCar].data.dia, motorista[numCar].data.mes, motorista[numCar].data.ano);
        printf("Numero pra contato: ");
        puts(motorista[numCar].numero);
        printf("\n");
    }
}

void escolherAulaAlt()
{
    int i, op;
    if(numProf >= 0)
    {
        printf("Qual aula voce deseja alterar? (0 = Voltar)\n");
        for(i = 0; i < numProf + 1; i++)
        {
            printf("%d) Nome do professor: ", i + 1);
            puts(cont[i].nome);
            printf("Materia: ");
            puts(cont[i].nomMat);
            printf("Data: %d/%d/%d\n", cont[i].data.dia, cont[i].data.mes, cont[i].data.ano);
            printf("Conteudo lecionado: ");
            puts(cont[i].conteudo);
            printf("Atividade: ");
            puts(cont[i].atv);
            printf("\n");
        }
        scanf("%d", &op);
        if(op < 0 || op > numAluno + 1)
        {
            printf("Valor invalido!\n");
            system("cls");
        }
        else if (op == 0)
        {
            system("cls");
            return;
        }
        else
        {
            system("cls");
            op--;
            alterarAula(op);
        }
    }
    else
    {
        printf("Ainda não existe nenhuma aula cadastrada\n");
    }
}

void alterarAula(int opAula)
{
    int i, opAlt = 6, auxDat = 0;
    char strAux[100];
    while(opAlt != 0)
    {
        printf("Voce deseja alterar:\n");
        printf("1) Nome do professor\n");
        printf("2) Nome da materia\n");
        printf("3) Data\n");
        printf("4) Conteudo lecionado\n");
        printf("5) Atividade\n");
        printf("0) Não desejo alterar mais nada na aula\n");
        scanf("%d", &opAlt);
        system("cls");
        switch(opAlt)
        {
            case 1:
                printf("Digite o novo nome: \n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                cont[opAula].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(cont[opAula].nome, strAux);
                system("cls");
                break;
            case 2:
                printf("Digite o novo nome: \n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                cont[opAula].nomMat = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(cont[opAula].nomMat, strAux);
                system("cls");
                break;
            case 3:
                printf("Digite a nova data: \n");
                auxDat = 0;
                while (auxDat == 0)
                {
                    scanf("%d%d%d", &cont[opAula].data.dia, &cont[opAula].data.mes, &cont[opAula].data.ano);
                    auxDat = valide_data(cont[opAula].data.dia, cont[opAula].data.mes, cont[opAula].data.ano);
                    if (auxDat == 0)
                    {
                        printf("Valor invalido!\n");
                    }
                }
                system("cls");
                break;
            case 4:
                printf("Digite o novo conteudo: \n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                cont[opAula].conteudo = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(cont[opAula].conteudo, strAux);
                system("cls");
                break;
            case 5:
                printf("Digite a nova atividade: \n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                cont[opAula].atv = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(cont[opAula].atv, strAux);
                system("cls");
                break;
        }
    }
}

void escolherAulaExc()
{
    int i, op;
    if(numProf >= 0)
    {
        printf("Qual aula voce deseja excluir? (0 = Voltar)\n");
        for(i = 0; i < numProf + 1; i++)
        {
            printf("%d) Nome do professor: ", i + 1);
            puts(cont[i].nome);
            printf("Materia: ");
            puts(cont[i].nomMat);
            printf("Data: %d/%d/%d\n", cont[i].data.dia, cont[i].data.mes, cont[i].data.ano);
            printf("Conteudo lecionado: ");
            puts(cont[i].conteudo);
            printf("Atividade: ");
            puts(cont[i].atv);
            printf("\n");
        }
        scanf("%d", &op);
        if(op < 0 || op > numAluno + 1)
        {
            printf("Valor invalido!\n");
            system("cls");
        }
        else if (op == 0)
        {
            system("cls");
            return;
        }
        else
        {
            system("cls");
            op--;
            excluirAula(op);
        }
    }
    else
    {
        printf("Ainda não existe nenhuma aula cadastrada\n");
    }
}

void excluirAula(int opAula)
{
    int i, j, conf;
    printf("Tem certeza que quer excluir a aula?\n");
    printf("1) Sim\n2) Não\n");
    scanf("%d", &conf);
    if (conf == 1)
    {
        for(i = opAula; i < numProf; i++)
        {
            cont[i].nome = (char *)malloc((strlen(cont[i + 1].nome) + 1) * sizeof(char));
            strcpy(cont[i].nome, cont[i + 1].nome);

            cont[i].nomMat = (char *)malloc((strlen(cont[i + 1].nomMat) + 1) * sizeof(char));
            strcpy(cont[i].nomMat, cont[i + 1].nomMat);

            cont[i].data.dia == cont[i + 1].data.dia;
            cont[i].data.mes == cont[i + 1].data.mes;
            cont[i].data.ano == cont[i + 1].data.ano;

            cont[i].conteudo = (char *)malloc((strlen(cont[i + 1].conteudo) + 1) * sizeof(char));
            strcpy(cont[i].conteudo, cont[i + 1].conteudo);

            cont[i].atv = (char *)malloc((strlen(cont[i + 1].atv) + 1) * sizeof(char));
            strcpy(cont[i].atv, cont[i + 1].atv);
        }
        numProf--;
        cont = (TProfessor *)realloc(cont, (numProf + 1) * sizeof(TProfessor));
        system("cls");
    }
    else
    {
        system("cls");
        return;
    }
}

void salvarAluno()
{
    int i, j;
    FILE *pArq;

    pArq = fopen("alunosBD.txt", "w");
    for (i = 0; i < numAluno + 1; i++)
    {
        fprintf(pArq, "%s;", faltas[i].nome);
        fprintf(pArq, "%s;", faltas[i].turma);
        fprintf(pArq, "%d;", faltas[i].data.dia);
        fprintf(pArq, "%d;", faltas[i].data.mes);
        fprintf(pArq, "%d;", faltas[i].data.ano);
        fprintf(pArq, "%c", '\n');
    }
    fclose(pArq);
}

void salvarProf()
{
    int i, j;
    FILE *pArq1;

    pArq1 = fopen("profBD.txt", "w");
    for (i = 0; i < numProf + 1; i++)
    {
        fprintf(pArq1, "%s;", cont[i].nome);
        fprintf(pArq1, "%s;", cont[i].nomMat);
        fprintf(pArq1, "%d;", cont[i].data.dia);
        fprintf(pArq1, "%d;", cont[i].data.mes);
        fprintf(pArq1, "%d;", cont[i].data.ano);
        fprintf(pArq1, "%s;", cont[i].conteudo);
        fprintf(pArq1, "%s;", cont[i].atv);
        fprintf(pArq1, "%c", '\n');
    }
    fclose(pArq1);
}

void salvarCarona()
{
    int i, j;
    FILE *pArq2;

    pArq2 = fopen("caronasBD.txt", "w");
    for (i = 0; i <  1; i++)
    {
        fprintf(pArq2, "%s;", motorista[i].nome);
        fprintf(pArq2, "%s;", motorista[i].local);
        fprintf(pArq2, "%s;", motorista[i].periodo);
        fprintf(pArq2, "%d;", motorista[i].vagas);
        fprintf(pArq2, "%d;", motorista[i].data.dia);
        fprintf(pArq2, "%d;", motorista[i].data.mes);
        fprintf(pArq2, "%d;", motorista[i].data.ano);
        fprintf(pArq2, "%s;", motorista[i].numero);
        fprintf(pArq2, "%c", '\n');
    }
    fclose(pArq2);
}

void recuperarAluno()
{
    int i = 0, sep = 0;
    char c, str[100];
    FILE *pArq;

    pArq = fopen("alunosBD.txt", "r");
    if (pArq)
    {
        numAluno++;
        while (!feof(pArq))
        {
            c = fgetc(pArq);

            if (c != ';' && c != '\n' && c != EOF)
            {
                str[i++] = c;
            }
            else if (c == ';' || c == '\n')
            {
                str[i] = '\0';
                i = 0;
                if (c == ';')
                {
                    if (sep == 0)
                    {
                        if (numAluno == 0)
                        {
                            faltas = (TAluno *)malloc(1 * sizeof(TAluno));
                        }
                        else
                        {
                            faltas = (TAluno *)realloc(faltas, (numAluno + 1) * sizeof(TAluno));
                        }
                        faltas[numAluno].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(faltas[numAluno].nome, str);
                        sep++;
                    }
                    else if (sep == 1)
                    {
                        faltas[numAluno].turma = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(faltas[numAluno].turma, str);
                        sep++;
                    }
                    else if (sep == 2)
                    {
                        faltas[numAluno].data.dia = atoi(str);
                        sep++;
                    }
                    else if (sep == 3)
                    {
                        faltas[numAluno].data.mes = atoi(str);
                        sep++;
                    }
                    else if (sep == 4)
                    {
                        faltas[numAluno].data.ano = atoi(str);
                        sep++;
                    }
                }
                else
                {
                    numAluno++;
                    sep = 0;
                }
            }
        }
    numAluno--;
    }
    fclose(pArq);
}

void recuperarProf()
{
    int i = 0, sep = 0;
    char c, str[100];
    FILE *pArq;

    pArq = fopen("profBD.txt", "r");
    if (pArq)
    {
        numProf++;
        while (!feof(pArq))
        {
            c = fgetc(pArq);

            if (c != ';' && c != '\n' && c != EOF)
            {
                str[i++] = c;
            }
            else if (c == ';' || c == '\n')
            {
                str[i] = '\0';
                i = 0;
                if (c == ';')
                {
                    if (sep == 0)
                    {
                        if (numProf == 0)
                        {
                            cont = (TProfessor *)malloc(1 * sizeof(TProfessor));
                        }
                        else
                        {
                            cont = (TProfessor *)realloc(cont, (numProf + 1) * sizeof(TProfessor));
                        }
                        cont[numProf].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(cont[numProf].nome, str);
                        sep++;
                    }
                    else if (sep == 1)
                    {
                        cont[numProf].nomMat = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(cont[numProf].nomMat, str);
                        sep++;
                    }
                    else if (sep == 2)
                    {
                        cont[numProf].data.dia = atoi(str);
                        sep++;
                    }
                    else if (sep == 3)
                    {
                        cont[numProf].data.mes = atoi(str);
                        sep++;
                    }
                    else if (sep == 4)
                    {
                        cont[numProf].data.ano = atoi(str);
                        sep++;
                    }
                    else if (sep == 5)
                    {
                        cont[numProf].conteudo = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(cont[numProf].conteudo, str);
                        sep++;
                    }
                    else if (sep == 6)
                    {
                        cont[numProf].atv = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(cont[numProf].atv, str);
                        sep++;
                    }
                }
                else
                {
                    numProf++;
                    sep = 0;
                }
            }
        }
    numProf--;
    }
    fclose(pArq);
}

void recuperarCarona()
{
    int i = 0, sep = 0;
    char c, str[100];
    FILE *pArq;

    pArq = fopen("caronasBD.txt", "r");
    if (pArq)
    {
        numCar++;
        while (!feof(pArq))
        {
            c = fgetc(pArq);

            if (c != ';' && c != '\n' && c != EOF)
            {
                str[i++] = c;
            }
            else if (c == ';' || c == '\n')
            {
                str[i] = '\0';
                i = 0;
                if (c == ';')
                {
                    if (sep == 0)
                    {
                        if (numCar == 0)
                        {
                            motorista = (TCarona *)malloc(1 * sizeof(TCarona));
                        }
                        else
                        {
                            motorista = (TCarona *)realloc(motorista, (numCar + 1) * sizeof(TCarona));
                        }
                        motorista[numCar].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(motorista[numCar].nome, str);
                        sep++;
                    }
                    else if (sep == 1)
                    {
                        motorista[numCar].local = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(motorista[numCar].local, str);
                        sep++;
                    }
                    else if (sep == 2)
                    {
                        motorista[numCar].periodo = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(motorista[numCar].periodo, str);
                        sep++;
                    }
                    else if (sep == 3)
                    {
                        motorista[numCar].vagas = atoi(str);
                        sep++;
                    }
                    else if (sep == 4)
                    {
                        motorista[numCar].data.dia = atoi(str);
                        sep++;                   
                    }
                    else if (sep == 5)
                    {
                        motorista[numCar].data.mes = atoi(str);
                        sep++;
                    }
                    else if (sep == 6)
                    {
                        motorista[numCar].data.ano = atoi(str);
                        sep++;
                    }
                    else if (sep == 7)
                    {
                        motorista[numCar].numero = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(motorista[numCar].numero, str);
                        sep++;
                    }
                }
                else
                {
                    numCar++;
                    sep = 0;
                }
            }
        }
    numCar--;
    }
    fclose(pArq);
}

void liberarPonteiros()
{
    int i;
    for (i = 0; i < numAluno + 1; i++)
    {
        free(faltas[i].nome);
        free(faltas[i].turma);
    }
    for (i = 0; i < numProf + 1; i++)
    {
        free(cont[i].nome);
        free(cont[i].nomMat);
        free(cont[i].conteudo);
        free(cont[i].atv);
    }
    for (i = 0; i < numCar + 1; i++)
    {
        free(motorista[i].nome);
        free(motorista[i].periodo);
        free(motorista[i].local);
        free(motorista[i].numero);
    }
    free(faltas);
    free(cont);
    free(motorista);
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
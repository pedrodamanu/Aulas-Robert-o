
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct
{
    int hora;
    int minuto;
} THora;

typedef struct
{
    char *nome;
    char *apelido;
    char *email;
    TData data_nas;
    char *telefone;
} TAmigo;

typedef struct
{
    char *logradouro;
    int numero;
    char *bairro;
    char *cidade;
    char *estado;
} TEndereco;

typedef struct
{
    char *nome_encontro;
    TEndereco endereco;
} TLocal;


typedef struct
{
    char *nome;
} TCategoria;

typedef struct
{
    TAmigo *amigos;
    TCategoria *categoria;
    TData data;
    THora horario;
    char *desc;
} TEncontro;

void lerMenu();
void manterAmigo();
void manterLocal();
void manterCategoria();
void manterEncontro();
void Relatorios();
void adicionarAmigo();
void escolherAulaAlt();
void alterarAula(int opAula);
void escolherAulaExc();
void excluirAula(int opAula);
void salvarAluno();
void recuperarAluno();
int valide_data(int dias, int mes, int ano);
void liberarPonteiros();

TAmigo *amigos;
int numAmigo = 0;

int main()
{
    lerMenu();
}

void lerMenu()
{
    int op1 = 1;
    while (op1 != 0)
    {
        printf("Bem vindo!!\n");
        printf("Selecione a opção desejada: \n");
        printf("1) Manter amigo\n");
        printf("2) Manter local\n");
        printf("3) Manter categoria\n");
        printf("4) Manter encontro\n");
        printf("5) Relatorios\n");
        printf("0) Sair\n");
        scanf("%d", &op1);
        switch (op1)
        {
        case 1:
            manterAmigo();
            break;
        case 2:
            //manterLocal();
            break;
        case 3:
            //manterCategoria();
            break;
        case 4:
            //manterEncontro();
            break;
        case 5:
            //Relatorios();
            break;
        }
    }
    system("cls");
}

void manterAmigo()
{
    int opAmigo = 1;
    while(opAmigo != 0)
    {
        printf("1) Adicionar amigo\n");
        printf("2) Alterar amigo\n");
        printf("3) Excluir amigo\n");
        printf("0) Voltar\n");
        scanf("%d", &opAmigo);
        switch(opAmigo)
        {
            case 1:
                adicionarAmigo();
                break;
            case 2:
                //alterarAmigo();
                break;
            case 3:
                //excluirAmigo();
                break;
        }
    }
}

void adicionarAmigo()
{
    char strAux[100];
    if(numAmigo == 0)
    {
        amigos = (TAmigo *)malloc(1 * sizeof(TAmigo));
    }
    else
    {
        amigos = (TAmigo *)realloc(amigos, (numAmigo + 1) * sizeof(TAmigo));
    }

    printf("Qual o nome do amigo?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigos[numAmigo].nome, strAux);

    printf("Qual o apelido do amigo?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigos[numAmigo].apelido, strAux);

    printf("Qual o email do amigo?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigos[numAmigo].email, strAux);

    printf("Digite sua data de nascimento: (DD MM AAAA, sem barras)\n");
    scanf("%d%d%d", &amigos[numAmigo].data_nas.dia, &amigos[numAmigo].data_nas.mes, &amigos[numAmigo].data_nas.ano);

    printf("Qual o seu telefone?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].telefone = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigos[numAmigo].telefone, strAux);

    numAmigo++;
    system("cls");
}

/*void escolherAulaAlt()
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
                    }#include <windows.h>
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
}*/
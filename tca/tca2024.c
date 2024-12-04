
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
    TLocal local;
    char *desc;
} TEncontro;

void lerMenu();
void manterAmigo();
void manterLocal();
void manterCategoria();
void manterEncontro();
void Relatorios();
void adicionarAmigo();
void pesquisarAmigo(int OpFun);
void alterarAmigo(int amg);
void excluirAmigo(int amg);
void salvarAmigo();
void recuperarAmigo();
int valide_data(int dias, int mes, int ano);
int validarValor(int num, int param1, int param2);
void liberarPonteiros();

TAmigo *amigos;

int numAmigo = 0;

int main()
{
    recuperarAmigo();
    lerMenu();
    salvarAmigo();
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

        if(validarValor(op1, 0, 5) == 0)
        {
            lerMenu();
        }

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

        if(validarValor(opAmigo, 0, 3) == 0)
        {
            manterAmigo();
        }

        switch(opAmigo)
        {
            case 1:
                adicionarAmigo();
                break;
            case 2:
                pesquisarAmigo(1);
                break;
            case 3:
                pesquisarAmigo(2);
                break;
        }
    }
}

void adicionarAmigo()
{
    char strAux[100];
    int auxDat = 0;
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

    while(auxDat == 0)
    {
        printf("Digite sua data de nascimento: (DD MM AAAA, sem barras)\n");
        scanf("%d%d%d", &amigos[numAmigo].data_nas.dia, &amigos[numAmigo].data_nas.mes, &amigos[numAmigo].data_nas.ano);
        auxDat = valide_data(amigos[numAmigo].data_nas.dia, amigos[numAmigo].data_nas.mes, amigos[numAmigo].data_nas.ano);
        if (auxDat == 0)
        {
            printf("Valor invalido!\n");
        }
    }

    printf("Qual o seu telefone?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].telefone = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigos[numAmigo].telefone, strAux);
    
    numAmigo++;
    system("cls");
}

void pesquisarAmigo(int OpFun)
{
    int i, opAmigo;
    printf("Você deseja selecionar qual amigo?\n");
    for (i = 0; i < numAmigo; i++)
    {
        printf("%d) ", i + 1);
        puts(amigos[i].nome);
    }
    scanf("%d", &opAmigo);

    if(validarValor(opAmigo, 1, numAmigo) == 0)
    {
        pesquisarAmigo(OpFun);
    }

    if (OpFun == 1)
    {
        alterarAmigo(opAmigo - 1);
    }
    else
    {
        excluirAmigo(opAmigo - 1);
    }
}

void alterarAmigo(int amg)
{
    int opAlt, auxDat = 0;
    char strAux[100];
    printf("Você deseja alterar:\n");
    printf("1) Nome (%s)\n", amigos[amg].nome);
    printf("2) Apelido (%s)\n", amigos[amg].apelido);
    printf("3) Email (%s)\n", amigos[amg].email); 
    printf("4) Alterar data (%d/%d/%d)\n", &amigos[amg].data_nas.dia, &amigos[amg].data_nas.mes, &amigos[amg].data_nas.ano);
    printf("5) Telefone (%s)\n", amigos[amg].telefone); 
    scanf("%d", &opAlt);
    switch(opAlt)
    {
        case 1:
            printf("Digite o novo nome:\n");
            fflush(stdin);
            gets(strAux);
            fflush(stdin);
            amigos[amg].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(amigos[amg].nome, strAux);
            break;
        case 2:
            printf("Digite o novo apelido:\n");
            fflush(stdin);
            gets(strAux);
            fflush(stdin);
            amigos[amg].apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(amigos[amg].apelido, strAux);
            break;
        case 3:
            printf("Digite o novo email:\n");
            fflush(stdin);
            gets(strAux);
            fflush(stdin);
            amigos[amg].email= (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(amigos[amg].email, strAux);
            break;
        case 4:
            while(auxDat == 0)
            {
                printf("Digite sua data de nascimento: (DD MM AAAA, sem barras)\n");
                scanf("%d%d%d", &amigos[amg].data_nas.dia, &amigos[amg].data_nas.mes, &amigos[amg].data_nas.ano);
                auxDat = valide_data(amigos[amg].data_nas.dia, amigos[amg].data_nas.mes, amigos[amg].data_nas.ano);
                if (auxDat == 0)
                {
                    printf("Valor invalido!\n");
                }
            }
        case 5:
            printf("Digite o novo telefone:\n");
            fflush(stdin);
            gets(strAux);
            fflush(stdin);
            amigos[amg].telefone = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(amigos[amg].telefone, strAux);
            break;
        
    }
    system("cls");
}

void excluirAmigo(int amg)
{
    int i, conf;
    printf("Tem certeza que quer excluir o amigo?\n");
    printf("1) Sim\n2) Não\n");
    
    scanf("%d", &conf);
    if (conf == 1)
    {
        for(i = amg; i < numAmigo - 1; i++)
        {
            amigos[i] = amigos[i + 1];
        }
        numAmigo--;
        amigos = (TAmigo *)realloc(amigos, numAmigo * sizeof(TAmigo));
        system("cls");
    }
    else
    {
        system("cls");
        return;
    }
}

void manterLocal()
{
    int opLocal = 1;
    while(opLocal != 0)
    {
        printf("1) Adicionar local\n");
        printf("2) Alterar local\n");
        printf("3) Excluir local\n");
        printf("0) Voltar\n");
        scanf("%d", &opLocal);
        switch(opLocal)
        {
            case 1:
                //adicionarLocal();
                break;
            case 2:
                //alterarLocal();
                break;
            case 3:
                //excluirLocal();
                break;
        }
    }
}



void salvarAmigo()
{
    int i;
    FILE *pArq;

    pArq = fopen("amigosBD.txt", "w");
    for (i = 0; i < numAmigo; i++)
    {
        fprintf(pArq, "%s;", amigos[i].nome);
        fprintf(pArq, "%s;", amigos[i].apelido);
        fprintf(pArq, "%s;", amigos[i].email);
        fprintf(pArq, "%d;", amigos[i].data_nas.dia);
        fprintf(pArq, "%d;", amigos[i].data_nas.mes);
        fprintf(pArq, "%d;", amigos[i].data_nas.ano);
        fprintf(pArq, "%s;", amigos[i].telefone);
        fprintf(pArq, "%c", '\n');
    }
    fclose(pArq);
}

void recuperarAmigo()
{
    int i = 0, sep = 0;
    char c, str[100];
    FILE *pArq;

    pArq = fopen("amigosBD.txt", "r");
    if (pArq)
    {
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
                        if (numAmigo == 0)
                        {
                            amigos = (TAmigo *)malloc(1 * sizeof(TAmigo));
                        }
                        else
                        {
                            amigos = (TAmigo *)realloc(amigos, (numAmigo + 1) * sizeof(TAmigo));
                        }
                        amigos[numAmigo].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(amigos[numAmigo].nome, str);
                        sep++;
                    }
                    else if (sep == 1)
                    {
                        amigos[numAmigo].apelido = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(amigos[numAmigo].apelido, str);
                        sep++;
                    }
                    else if (sep == 2)
                    {
                        amigos[numAmigo].email = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(amigos[numAmigo].email, str);
                        sep++;
                    }
                    else if (sep == 3)
                    {
                        amigos[numAmigo].data_nas.dia = atoi(str);
                        sep++;
                    }
                    else if (sep == 4)
                    {
                        amigos[numAmigo].data_nas.mes = atoi(str);
                        sep++;
                    }
                    else if (sep == 5)
                    {
                        amigos[numAmigo].data_nas.ano = atoi(str);
                        sep++;
                    }
                    else if (sep == 6)
                    {
                        amigos[numAmigo].telefone = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(amigos[numAmigo].telefone, str);
                        sep++;
                    }
                }
                else
                {
                    numAmigo++;
                    sep = 0;
                }
            }
        }
    }
    fclose(pArq);
}
/*
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
    for (i = 0; i < numAmigo + 1; i++)
    {
        free(amigos[i].nome);
        free(amigos[i].turma);
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
    free(amigos);
    free(cont);
    free(motorista);
}*/

int validarValor(int num, int param1, int param2)
{
    if(num < param1 || num > param2)
    {
        printf("Valor digitado eh invalido!\n");
        return 0;
    }
    return 1;
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
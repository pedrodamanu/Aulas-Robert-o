
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>         //LEMBRAR DE REVISAR VERIFICAÇÃO DE VALOR DIGITADO PELO USUARIO
#include <windows.h>

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
void adicionarLocal();
void adicionarCategoria();
void pesquisarAmigo(int OpFun);
void pesquisarLocal(int OpFun);
void pesquisarCategoria(int OpFun);
void alterarAmigo(int amg);
void alterarLocal(int loc);
void alterarCategoria(int cat);
void excluirAmigo(int amg);
void excluirLocal(int loc);
void excluirCategoria(int cat);
void salvarAmigo();
void salvarLocal();
void salvarCategoria();
void recuperarAmigo();
void recuperarLocal();
void recuperarCategoria();
int valide_data(int dias, int mes, int ano);
int validarValor(int num, int param1, int param2);
void liberarPonteiros();

TAmigo *amigos;
TLocal *locais;
TCategoria *categorias;

int numAmigo = 0;
int numLocal = 0;
int numCategoria = 0;

int main()
{
    SetConsoleOutputCP(65001);
    recuperarAmigo();
    recuperarLocal();
    recuperarCategoria();
    lerMenu();
    salvarAmigo();
    salvarLocal();
    salvarCategoria();
    liberarPonteiros();
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
            manterLocal();
            break;
        case 3:
            manterCategoria();
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
        if(validarValor(opLocal, 0, 3) == 0)
        {
            manterLocal();
        }

        switch(opLocal)
        {
            case 1:
                adicionarLocal();
                break;
            case 2:
                pesquisarLocal(1);
                break;
            case 3:
                pesquisarLocal(2);
                break;
        }
    }
}

void adicionarLocal()
{
    char strAux[100];
    if(numLocal == 0)
    {
        locais = (TLocal *)malloc(1 * sizeof(TLocal));
    }
    else
    {
        locais = (TLocal *)realloc(locais, (numLocal + 1) * sizeof(TLocal));
    }

    printf("Onde será o encontro?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    locais[numLocal].nome_encontro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(locais[numLocal].nome_encontro, strAux);

    printf("Qual o logradouro?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    locais[numLocal].endereco.logradouro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(locais[numLocal].endereco.logradouro, strAux);

    printf("Qual o numero do endereço?\n");
    scanf("%d", &locais[numLocal].endereco.numero);

    printf("Qual o bairro?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    locais[numLocal].endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(locais[numLocal].endereco.bairro, strAux);

    printf("Qual a cidade?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    locais[numLocal].endereco.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(locais[numLocal].endereco.cidade, strAux);

    printf("Qual o estado?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    locais[numLocal].endereco.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(locais[numLocal].endereco.estado, strAux);
    
    numLocal++;
    system("cls");
}

void pesquisarLocal(int OpFun)
{
    int i, opLocal;
    printf("Você deseja selecionar qual local?\n");
    for (i = 0; i < numLocal; i++)
    {
        printf("%d) ", i + 1);
        puts(locais[i].nome_encontro);
    }
    scanf("%d", &opLocal);

    if(validarValor(opLocal, 1, numLocal) == 0)
    {
        pesquisarLocal(OpFun);
    }

    if (OpFun == 1)
    {
        alterarLocal(opLocal - 1);
    }
    else
    {
        excluirLocal(opLocal - 1);
    }
}

void alterarLocal(int loc)
{
    int opAlt, auxDat = 0;
    char strAux[100];
    printf("Você deseja alterar:\n");
    printf("1) Local do encontro (%s)\n", locais[loc].nome_encontro);
    printf("2) Logradouro (%s)\n", locais[loc].endereco.logradouro);
    printf("3) Numero (%d)\n", locais[loc].endereco.numero); 
    printf("4) Bairro (%s)\n", locais[loc].endereco.bairro);
    printf("5) Cidade (%s)\n", locais[loc].endereco.cidade); 
    printf("6) Estado (%s)\n", locais[loc].endereco.estado); 
    scanf("%d", &opAlt);

    if(validarValor(opAlt, 1, 6) == 0)
    {
        alterarLocal(loc);
    }

    switch(opAlt)
    {
        case 1:
            printf("Digite o novo local:\n");
            fflush(stdin);
            gets(strAux);
            fflush(stdin);
            locais[loc].nome_encontro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(locais[loc].nome_encontro, strAux);
            break;
        case 2:
            printf("Digite o novo logradouro:\n");
            fflush(stdin);
            gets(strAux);
            fflush(stdin);
            locais[loc].endereco.logradouro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(locais[loc].endereco.logradouro, strAux);
            break;
        case 3:
            printf("Digite o novo numero:\n");
            scanf("%d", &locais[loc].endereco.numero);
            break;
        case 4:
            printf("Digite o novo bairro:\n");
            fflush(stdin);
            gets(strAux);
            fflush(stdin);
            locais[loc].endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(locais[loc].endereco.bairro, strAux);
            break;
        case 5:
            printf("Digite a nova cidade:\n");
            fflush(stdin);
            gets(strAux);
            fflush(stdin);
            locais[loc].endereco.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(locais[loc].endereco.cidade, strAux);
            break;
        case 6:
            printf("Digite o novo estado:\n");
            fflush(stdin);
            gets(strAux);
            fflush(stdin);
            locais[loc].endereco.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(locais[loc].endereco.estado, strAux);
            break;
    }
    system("cls");
}

void excluirLocal(int loc)
{
    int i, conf;
    printf("Tem certeza que quer excluir o local?\n");
    printf("1) Sim\n2) Não\n");
    
    scanf("%d", &conf);
    if (conf == 1)
    {
        for(i = loc; i < numLocal - 1; i++)
        {
            locais[i] = locais[i + 1];
        }
        numLocal--;
        locais = (TLocal *)realloc(locais, numLocal * sizeof(TLocal));
        system("cls");
    }
    else
    {
        system("cls");
        return;
    }
}

void manterCategoria()
{
    int opCategoria = 1;
    while(opCategoria != 0)
    {
        printf("1) Adicionar categoria\n");
        printf("2) Alterar categoria\n");
        printf("3) Excluir categoria\n");
        printf("0) Voltar\n");
        scanf("%d", &opCategoria);

        if(validarValor(opCategoria, 0, 3) == 0)
        {
            manterCategoria();
        }

        switch(opCategoria)
        {
            case 1:
                adicionarCategoria();
                break;
            case 2:
                pesquisarCategoria(1);
                break;
            case 3:
                pesquisarCategoria(2);
                break;
        }
    }
}

void adicionarCategoria()
{
    char strAux[100];
    if(numCategoria == 0)
    {
        categorias = (TCategoria *)malloc(1 * sizeof(TCategoria));
    }
    else
    {
        categorias = (TCategoria *)realloc(categorias, (numCategoria + 1) * sizeof(TCategoria));
    }

    printf("Qual a categoria?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    categorias[numCategoria].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(categorias[numCategoria].nome, strAux);

    numCategoria++;
    system("cls");
}

void pesquisarCategoria(int OpFun)
{
    int i, opCategoria;
    printf("Você deseja selecionar qual categoria?\n");
    for (i = 0; i < numCategoria; i++)
    {
        printf("%d) ", i + 1);
        puts(categorias[i].nome);
    }
    scanf("%d", &opCategoria);

    if(validarValor(opCategoria, 1, numCategoria) == 0)
    {
        pesquisarCategoria(OpFun);
    }

    if (OpFun == 1)
    {
        alterarCategoria(opCategoria - 1);
    }
    else
    {
        excluirCategoria(opCategoria - 1);
    }
}

void alterarCategoria(int cat)
{
    char strAux[100];
    printf("Qual o novo nome da categoria?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    categorias[cat].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(categorias[cat].nome, strAux);  
    system("cls");
}

void excluirCategoria(int cat)
{
    int i, conf;
    printf("Tem certeza que quer excluir a categoria?\n");
    printf("1) Sim\n2) Não\n");
    
    scanf("%d", &conf);
    if (conf == 1)
    {
        for(i = cat; i < numCategoria - 1; i++)
        {
            categorias[i] = categorias[i + 1];
        }
        numCategoria--;
        categorias = (TCategoria *)realloc(categorias, numCategoria * sizeof(TCategoria));
        system("cls");
    }
    else
    {
        system("cls");
        return;
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

void salvarLocal()
{
    int i;
    FILE *pArq;

    pArq = fopen("locaisBD.txt", "w");
    for (i = 0; i < numLocal; i++)
    {
        fprintf(pArq, "%s;", locais[i].nome_encontro);
        fprintf(pArq, "%s;", locais[i].endereco.logradouro);
        fprintf(pArq, "%i;", locais[i].endereco.numero);
        fprintf(pArq, "%s;", locais[i].endereco.bairro);
        fprintf(pArq, "%s;", locais[i].endereco.cidade);
        fprintf(pArq, "%s;", locais[i].endereco.estado);
        fprintf(pArq, "%c", '\n');
    }
    fclose(pArq);
}

void salvarCategoria()
{
    int i;
    FILE *pArq;

    pArq = fopen("categoriasBD.txt", "w");
    for (i = 0; i < numCategoria; i++)
    {
        fprintf(pArq, "%s;", categorias[i].nome);
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

void recuperarLocal()
{
    int i = 0, sep = 0;
    char c, str[100];
    FILE *pArq;

    pArq = fopen("locaisBD.txt", "r");
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
                        if (numLocal == 0)
                        {
                            locais = (TLocal *)malloc(1 * sizeof(TLocal));
                        }
                        else
                        {
                            locais = (TLocal *)realloc(locais, (numLocal + 1) * sizeof(TLocal));
                        }
                        locais[numLocal].nome_encontro = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(locais[numLocal].nome_encontro, str);
                        sep++;
                    }
                    else if (sep == 1)
                    {
                        locais[numLocal].endereco.logradouro = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(locais[numLocal].endereco.logradouro, str);
                        sep++;
                    }
                    else if (sep == 2)
                    {
                        locais[numLocal].endereco.numero = atoi(str);
                        sep++;
                    }
                    else if (sep == 3)
                    {
                        locais[numLocal].endereco.bairro = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(locais[numLocal].endereco.bairro, str);
                        sep++;
                    }
                    else if (sep == 4)
                    {
                        locais[numLocal].endereco.cidade = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(locais[numLocal].endereco.cidade, str);
                        sep++;
                    }
                    else if (sep == 5)
                    {
                        locais[numLocal].endereco.estado = (char *)malloc((strlen(str) + 1) * sizeof(char));
                        strcpy(locais[numLocal].endereco.estado, str);
                        sep++;
                    }
                }
                else
                {
                    numLocal++;
                    sep = 0;
                }
            }
        }
    }
    fclose(pArq);
}

void recuperarCategoria()
{
    int i = 0;
    char c, str[100];
    FILE *pArq;

    pArq = fopen("categoriasBD.txt", "r");
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
                    if (numCategoria == 0)
                    {
                        categorias = (TCategoria *)malloc(1 * sizeof(TCategoria));
                    }
                    else
                    {
                        categorias = (TCategoria *)realloc(categorias, (numCategoria + 1) * sizeof(TCategoria));
                    }
                    categorias[numCategoria].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
                    strcpy(categorias[numCategoria].nome, str);
                }
                else
                {
                    numCategoria++;
                }
            }
        }
    }
    fclose(pArq);
}

void liberarPonteiros()
{
    int i;
    for (i = 0; i < numAmigo; i++)
    {
        free(amigos[i].nome);
        free(amigos[i].apelido);
        free(amigos[i].email);
        free(amigos[i].telefone);
    }
    for (i = 0; i < numLocal; i++)
    {
        free(locais[i].nome_encontro);
        free(locais[i].endereco.logradouro);
        free(locais[i].endereco.bairro);
        free(locais[i].endereco.cidade);
        free(locais[i].endereco.estado);
    }
    free(amigos);
    free(locais);
}

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
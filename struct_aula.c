#include <stdio.h>
#define C 100

typedef struct //Cria uma STRUCT pra armazenar os dados de uma pessoa
{
    int dia;    //Define o campo peso
    int mes;     //Define o campo idade
    int ano;  //Define o campo Altura
} Tdata;

typedef struct //Cria uma STRUCT pra armazenar os dados de uma pessoa
{
    char nome[C];    //Define o campo peso
    float coeficiente;     //Define o campo idade
    char conceito[4];  //Define o campo Altura
    TData dtNas;
    TData dtMat; // A ESTRUTURA QUE FOR USADA POR OUTRA ESTRUTURA DEVE SER DEFINIDA ANTES
} TAluno;

int main()
{

    TAluno matheus;
    matheus.dtNas.dia = 10;
    matheus.dtMat.ano = 2024;
    scanf("%f", &a.Altura);

    TAluno turma23[4], turma24[4];
    turma[0].conceito[0] = 'a';

}
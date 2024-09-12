#include <stdio.h>
#include <string.h>
#define N 50

int soma(int a, int b);


int main() // TODA FUNÇÃO TEM UMA RESPONSABILIDADE UNICA
{
    int x, y, z, t, ss;
    int vet[N];
    char nome[100], sobreno[100];


    ss = strlen(nome); //conta a quantidade de caracteres na string
    strcpy(nome, sobreno); //o conteudo de b vai para a
    strcat(nome, sobreno); //concatena a string b em a
    t = strcmp(nome, sobreno); //se t for 0, as duas strings sao iguais, se t for positivo a string a vem antes de b na ordem alfabetica, se for negativo eh o contrario







    x = soma(3, 2);
    y = soma(5, 10);
    z = soma(x, y);
    t = soma(x, y + 1); // t em main eh diferente de t em soma
    x = somavet(vet); //ATENÇÃO AO MODO DE CHAMAR
    printf("%d %d %d %d", x, y, z, t);
    s(nome);
}

// tipo_retorno nome_funcao(parametros)
// {
//
// }

void s(char *v)
{
    int i, soma = 0;
    for (i = 0; v[i] != '\0'; i++);
    {
        QUALQUER COISA;
    }
}

int soma(int a, int b)
{
    int t = a + b;
    return t;
}

int vetsoma(int v[])
{
    int i, soma = 0;
    for (i = 0; i < N; i++)
    {
        soma += v[i];
    }
    return soma;
}
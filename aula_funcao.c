#include <stdio.h>

int soma(int a, int b);


int main() // TODA FUNÇÃO TEM UMA RESPONSABILIDADE UNICA
{
    int x, y, z, t;
    x = soma(3, 2);
    y = soma(5, 10);
    z = soma(x, y);
    t = soma(x, y + 1); // t em main eh diferente de t em soma
    printf("%d %d %d %d", x, y, z, t);
}

// tipo_retorno nome_funcao(parametros)
// {
//
// }

int soma(int a, int b)
{
    int t = a + b;
    return t;
}
#include <stdio.h>
//ALUNOS: PEDRO RODRIGO MIRANDA DOS SANTOS, GUILHERME DIAS BORILLE

void soma(int aux, int b);
int main()
{
    int aux, a, b;
    printf("Digite 2 valores:");
    scanf("%d%d", &a, &b);
    aux = a;
    soma (aux, b);
}
void soma (int aux, int  b)
{
    printf("%d ", aux);
    aux += 1;
    if (aux <= b)
    {
        soma (aux, b);
    }
}

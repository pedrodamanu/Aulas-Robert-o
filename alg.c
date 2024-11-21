#include <stdio.h>
int somar(int n);
int buscar(int vet[]);
int tamanho, loc;

int main()
{
    printf("digite o tamanho do seu vetor\n");
    scanf("%d", &tamanho);
    int vet[tamanho];
    int resultado = 0;
    for (int i = 0; i < tamanho; i++)
    {
        printf("digite o número para a posição %d do seu vetor(menor que 10)\n", i);
        scanf("%d", &vet[i]);
        resultado += somar(vet[i]);
    }
    printf("%d\n", resultado);

    buscar(vet);
}

int buscar(int vet[])
{
    printf("digite um numero para procurar\n");
    scanf("%d", &loc);
    for (int i = 0; i <= tamanho; i++)
    {
        if (vet[i] == loc)
        {
            printf("o número existe no vetor, na posição %d\n", i);
            return 0;
        }
    }
    printf("não existe no vetor\n");
}
int somar(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (n % 10) + somar(n / 10);
    }
}
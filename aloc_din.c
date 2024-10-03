#include <stdio.h>
#define C 100

int main()
{

    int *vet;
    vet = (int *)malloc(10 * sizeof(int)); // esta definindo um vetor de tamanho 10 que pode ser mudado dinamicamente, quando o tamanho for mudado os vetores se perdem
    vet = (int *)realloc(vet, 15*sizeof(int)); // esta definindo um vetor de tamanho 10 que pode ser mudado dinamicamente, realoca os valores quando o tamanho muda

    char *str, aux[200];   

    str = (char *)malloc((strlen(aux)+1) * sizeof(char));
    strcpy(str, aux);
} 
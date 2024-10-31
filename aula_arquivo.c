#include <stdio.h>

void salvarArquivo();
void recuperaArquivo();

int main()
{
    printf("Hello world\n");
}

void salvarArquivo()
{
    int i, j;
    FILE *pArq;

    // abrir arquivo
    pArq = fopen("testeBD.txt", "w");
    for(i = 0; i < 2; i++) 
    {
        fprintf(pArq, "%d\n", 2);
        fprintf(pArq, "%d\n", 3);    
    }

    fclose(pArq);
}

void recuperaArquivo()
{
    int i, sep, j;
    char str[100], c;

    FILE *pArq;

    pArq = fopen("musicaBD.txt", "r");
    if (pArq)
    {
        i = 0; //i usado para indexar str
        sep = 0; // usada pra contar os separador

        //percorre o arquivo ate o fim
        while(!feof(pArq))
        {
            c = fgetc(pArq);
        }
    }
}
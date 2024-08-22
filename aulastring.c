#include <stdio.h>
#define N 100

int main ()
{
    // vc nao vai percorrer uma string ate o fim dela, somente ate encontrar o \0
    char aula[N], aula2[N]; //'' eh caracter, "" eh string 
    int i;

    scanf("%s%s", &aula, &aula2); // nao le depois do primeiro espaço
    gets(aula); // nao le duas strings ao mesmo tempo
    gets(aula2);
    __fpurge(stdin); // sempre colocar depois de gets ou scanf("%c")

    printf("%s", aula);
    puts(aula); 


    for (i = 0; aula[i] != '\0'; i++)
    {

    }
}
#include <stdio.h>
#define N 100

int main ()
{
    char str1[N], str2[N];
    int i, cont = -1;
    printf("Digite algo: ");
    scanf("%s%s", &str1, &str2);
    __fpurge(stdin);
    for (i = 0; str1[i] != '\0'; i++)
    {
        cont++;
    }
    str1[cont + 1] = ' ';
    for (i = 0; str2[i] != '\0'; i++)
    {
        str1[cont + 2] = str2[i];
        cont++;
    }
    puts(str1);
}
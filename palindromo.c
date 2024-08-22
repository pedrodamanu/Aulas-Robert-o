#include <stdio.h>
#define N 100

int main ()
{
    char pal[N];
    int i, let = -1;
    printf("Digite algo: ");
    gets(pal);
    __fpurge(stdin);
    for (i = 0; pal[i] != '\0'; i++)
    {
        let++;
    }
    for (i = 0; i <= let; i++)
    {
        if (pal[i] != pal[let - i])
        {
            printf("Nao eh palindromo\n");
            break;
        }
    }
    if (i == let)
    {
        printf("eh palindromo");
    }
}
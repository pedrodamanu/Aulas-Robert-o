#include <stdio.h>
#define N 100

int main ()
{
    char a[N];
    int esp = 0, i;
    printf("Digite algo ai: ");
    gets(a);
    __fpurge(stdin);
    for (i = 0; a[i] != '\0'; i++)
    {
        if(a[i] == ' ')
        {
            esp++;
        }
    }
    printf("Ha %d espacos brancos\n", esp);
}
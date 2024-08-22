#include <stdio.h>
#define N 100

int main ()
{
    char a[N];
    int vog = 0, i;
    printf("Digite algo ai: ");
    gets(a);
    __fpurge(stdin);
    for (i = 0; a[i] != '\0'; i++)
    {
        if(a[i] == 'a' || a[i] == 'A' || a[i] == 'e' || a[i] == 'E' || a[i] == 'i' || a[i] == 'I' || a[i] == 'o' || a[i] == 'O' || a[i] == 'u' || a[i] == 'U')
        {
            vog++;
        }
    }
    printf("Ha %d vogais\n", vog);
}
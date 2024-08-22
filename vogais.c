#include <stdio.h>
#define N 100

int main()
{
    char a[N];
    int vog = 0, i;
    printf("Digite algo ai: ");
    gets(a);
    __fpurge(stdin);
    for (i = 0; a[i] != '\0'; i++)
    {
        switch (a[N])
        {
        case 'a':
            vog++;
            break;
        case 'A':
            vog++;
            break;
        case 'e':
            vog++;
            break;
        case 'E':
            vog++;
            break;
        case 'o':
            vog++;
            break;
        case 'O':
            vog++;
            break;
        case 'i':
            vog++;
            break;
        case 'I':
            vog++;
            break;
        case 'u':
            vog++;
            break;
        case 'U':
            vog++;
            break;
        }
    }
    printf("Ha %d vogais\n", vog);
}
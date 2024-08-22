#include <stdio.h>
#define N 100

int main()
{
    char str1[N], str2[N];
    int i, cont1 = 0, cont2 = 0;
    printf("Digite algo: ");
    scanf("%s%s", &str1, &str2);
    __fpurge(stdin);
    for (i = 0; str1[i] == '\0' && str2[i] == '\0'; i++)
    {

        if (str1[i] != str2[i])
        {
            printf("nao eh igual");
            break;
        }
        
    }
}
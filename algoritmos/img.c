#include <stdio.h>
#include <string.h>

testarLimiar();

int **img;
int main()
{
    int l, c, lim;
    printf("Digite as dimensões da matriz: \n");
    scanf("%d%d", &l, &c);
    img = (int *)malloc(l * sizeof(int));
    for(i = 0; i < l; i++)
    { 
        img[i] = (int *)malloc(c * sizeof(int));
    }
    printf("Digite o limiar:\n");
    scanf("%d", &lim);
    for (i = 0; i < l; i++)
    {
        for(j = 0; j < c; j++)
        {
            img[i][j] = rand()%256;
        }
    }
    testarLimiar(lim);
} 

void testarLimiar(int lim)
{
    for (i = 0; i < l; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(img[i][j] >= lim)
            {
                img[i][j] = 255;
            }
            else
            {
                img[i][j] = 0;
            }
        }
    }
}
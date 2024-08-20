#include <stdio.h>

int main()
{
    float count = 0, voto = 0, aux1, aux2, aux3, aux4;
    int c1 = 0, c2 = 0, b = 0, null = 0;
    while (voto != 5)
    {
        printf("(1) Candidato A \n(2) Candidato B \n(3) Branco \n(4) Nulo \n(5) Terminar a votacao \nDeposite seu voto:");
        scanf("%f", &voto);
        if (voto > 5 || voto < 1)
        {
            printf("Valor invalido\n");
        }
        else
        {
            if (voto == 1)
            {
                c1++;
            }
            else if (voto == 2)
            {
                c2++;
            }
            else if (voto == 3)
            {
                b++;
            }
            else if (voto == 4)
            {
                null++;
            }
            count++;
            system("clear");
        }
    }
    if (count < 2)
    {
        printf("Nao houve votos\n");
    }
    else
    {
        count -= 1;
        aux1 = c1 / count * 100;
        aux2 = c2 / count * 100;
        aux3 = b / count * 100;
        aux4 = null / count * 100;
        if (c1 > c2)
        {
            printf("Candidato A ganhou\n");
        }
        else if (c2 > c1)
        {
            printf("Candidato B ganhou\n");
        }
        else
        {
            printf("Houve empate\n");
        }
        printf("Candidato A: %d [%.2f%%] \nCandidato B: %d [%.2f%%] \nBranco: %d [%.2f%%] \nNulo: %d [%.2f%%] \nTotal de votos: %.1f \n ", c1, aux1, c2, aux2, b, aux3, null, aux4, count);
    }
}
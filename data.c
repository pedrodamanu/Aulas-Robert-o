#include <stdio.h>

int valide_data(int dias, int mes, int ano);
void reler();
int main()
{
    int d, m, a, res;
    printf("Digite o dia, mes e o ano: ");
    scanf("%d%d%d", &d, &m, &a);
    res = valide_data(d, m, a);
    while (res == 0)
    {
        reler();
        scanf("%d%d%d", &d, &m, &a);
        res = valide_data(d, m, a);
    }
    printf("Valor valido\n");
}
int valide_data(int dias, int mes, int ano)
{
    if (mes > 12 || mes <= 0)
    {
        return 0;
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if (dias <= 0 || dias > 31)
        {
            return 0;
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dias <= 0 || dias > 30)
        {
            return 0;
        }
    }
    if (ano % 4 == 0 && mes == 2)
    {
        if (dias <= 0 || dias > 29)
        {
            return 0;
        }
    }
    else if (mes == 2)
    {
        return 0;
    }
    return 1;
}
void reler()
{
    printf("Valor invalido, digite outro numero: ");
}
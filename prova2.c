#include <stdio.h>

int main(){
    float porc, preco, res;
    printf("Digite o valor do produto e a porcentagem que voce deseja calcular: \n");
    scanf("%f%f", &preco, &porc);
    if (preco > 0 && porc > 0 && porc <= 100)
    {
        res = preco - (preco * (porc/100));
        printf("O valor eh: %.2f\n", res);
    }
    else
    {
        printf("valor invalido\n");
    }
}
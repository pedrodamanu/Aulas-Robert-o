#include <stdio.h>

int main(){
    int quant, fabri = 0 , i , j, ctr = 0;
    printf("quantos pedidos");
    scanf("%i", &quant );
    int tacos[quant];
    for(int i = 0; i<quant; i++){
        scanf("%i",tacos);
    }
    for(int i = 0; i < quant; i++){

        for(int j = 0; j < quant; j++){
            if(tacos[i] == tacos[j] && i != j){
                
            }
        }
    }


}
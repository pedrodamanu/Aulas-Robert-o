#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
void menuprincipal();
int menuamigo();
int adicionaramigo();
int excluiramigo();
int editaramigo();
int menulocal();
int adicionarlocal();
int editarlocal();
int excluirlocal();
void menucat();
int adicionarcategoria();
int editarcategoria();
int excluircategoria();
int horario();
void menuencontro();
int adicionarencontro();
int editarencontro();
int excluirencontro();

typedef struct
{
    int dia;
    int mes;
    int ano;
} TData; 

typedef struct{
    char *nome;
    char *apelido;
    char *email;
    char *numtelefone;
    TData data;
}Tamigo;

typedef struct{
    char *logradouro;
    int num;
    char *bairro;
    char *cidade;
    char *estado;
} Tendereco;

typedef struct{
    char *nomeEncontro;
    Tendereco lugar;
} Tlocal;

typedef struct{
    char *nome;
}Tcategoria;

typedef struct{
    int hora;
    int minutos;
}Thorario;

typedef struct{
    TData data1;
    Thorario horas;
    Tamigo amigo;
    Tcategoria categoria;
    char *desc;
}Tencontro;

int numAmigo=0;
Tamigo *amigos;
char strAux[100];
Tlocal *lug;
int numLugar=0;
int numCategoria=0;
Tencontro *encontro;
Tcategoria *categorias;
Thorario horas;
int numHora=0;
int numEncontro;
int main(){
    SetConsoleOutputCP(65001);
    menuprincipal();
}
void menuprincipal(){
    int op;
    printf("menu principal:\n 1-manter amigo\n 2-manter local\n 3-manter categoria\n 4-manter encontro\n 5-relatórios\n 6-sair\n");
    scanf("%d", &op);
    system("cls");

    while(op<1 || op>6){
        printf("você escolheu uma opção inválida, tente novamente!!");
        scanf("%d",&op);
    }
    system("cls");
    switch(op){
        case 1:
        menuamigo();
        break;
        case 2:
        menulocal();
        break;
        case 3:
        menucat();
        break;
        case 4:
        menuencontro();

    }
    }
int menuamigo(){
    int op1;
    printf("você escolheu manter amigo:\n 1-adicionar amigo\n 2-editar amigo\n 3-excluir amigo\n 4-listar amigos\n");
    scanf("%d", &op1);
    system("cls");
    switch(op1){
        case 1:
        adicionaramigo();
        break;
        case 2:
        editaramigo();
        break;
        case 3:
        excluiramigo();
        break;
    }
}
int adicionaramigo(){
    int fov;
    printf("você escolheu adicionar amigo\n");
     if(numAmigo == 0)
    {
        amigos = (Tamigo *)malloc(1 * sizeof(Tamigo));
    }
    else
    {
        amigos = (Tamigo *)realloc(amigos, (numAmigo + 1) * sizeof(Tamigo));
    }
    printf("Qual o nome do amigo?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigos[numAmigo].nome, strAux);
    printf("%s\n",amigos[numAmigo].nome);
    system("cls");
    printf("Qual o apelido do seu amigo:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].apelido = (char *)malloc((strlen(strAux)+1)*sizeof(char));
    strcpy(amigos[numAmigo].apelido, strAux);
    printf("%s\n", amigos[numAmigo].apelido);
    system("cls");
    printf("Qual o email do seu amigo");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].email= (char *)malloc((strlen(strAux)+1)*sizeof(char));
    strcpy(amigos[numAmigo].email, strAux);
    printf("%s\n", amigos[numAmigo].email);
    system("cls");
    printf("Digite a data de nascimento do seu amigo (dia mês ano):\n");
    scanf("%d %d %d", &amigos[numAmigo].data.dia, &amigos[numAmigo].data.mes, &amigos[numAmigo].data.ano);
    printf(" %02d/%02d/%04d\n", amigos[numAmigo].data.dia, amigos[numAmigo].data.mes, amigos[numAmigo].data.ano);
    system("cls");
    printf("Qual o número de telefone do seu amigo");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    amigos[numAmigo].numtelefone= (char *)malloc((strlen(strAux)+1)*sizeof(char));
    strcpy(amigos[numAmigo].numtelefone, strAux);
    printf("%s\n", amigos[numAmigo].numtelefone);
    numAmigo++;
    system("cls");
    printf("Quer retornar pro menu principal(1) ou finalizar(0)?");
    scanf("%d",&fov);
    system("cls");
    if(fov==1){
        menuprincipal();
    }
    else{
        printf("programa finalizado!");
        return 0;
    }
}
int editaramigo(){
    int encontrado, dado,fov;
    printf("Qual o nome do amigo que você quer editar?");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    for(int i = 0; i < numAmigo; i++){
        int  aux=strcmp(amigos[i].nome, strAux);
        if(aux == 0)
        {
            encontrado = 1;
            printf("amigo %s encontrado\n", amigos[i].nome);
            printf("dados do amigo:\n nome(1):%s\n apelido(2):%s\n email(3):%s\n data de nascimento(4):%02d/%02d/%04d\n", amigos[i].nome, amigos[i].apelido, amigos[i].email,amigos[i].data.dia,amigos[i].data.mes,amigos[i].data.ano);
            printf("qual dado você quer editar?");
            scanf("%d", &dado);
            system("cls");
            switch(dado)
            {
                case 1:
                printf("digite o novo nome:\n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                amigos[i].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(amigos[i].nome, strAux);
                printf("%s\n",amigos[i].nome);
                printf("nome adicionado! digite 1 para voltar para o menu ou 0 para finalizar");
                scanf("%d", &fov);
                system("cls");
                if(fov==1){
                    menuprincipal();
                }
                else{
                    return 0;
                }

                case 2:
                printf("digite o novo apelido:\n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                amigos[i].apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(amigos[i].apelido, strAux);
                printf("%s\n",amigos[i].apelido);
                 printf("nome adicionado! digite 1 para voltar para o menu ou 0 para finalizar");
                scanf("%d", &fov);
                system("cls");
                if(fov==1){
                    menuprincipal();
                }
                else{
                    return 0;
                }

                break;

                case 3:
                printf("digite o novo email:\n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                amigos[i].email= (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(amigos[i].email, strAux);
                printf("%s\n",amigos[i].email);
                printf("nome adicionado! digite 1 para voltar para o menu ou 0 para finalizar");
                scanf("%d", &fov);
                system("cls");
                if(fov==1){
                    menuprincipal();
                }
                else{
                    return 0;
                }

                break;
                case 4:
                printf("Digite a data de nascimento do seu amigo (dia mês ano):\n");
                scanf("%d %d %d", &amigos[numAmigo].data.dia, &amigos[numAmigo].data.mes, &amigos[numAmigo].data.ano);
                printf(" %02d/%02d/%04d\n", amigos[numAmigo].data.dia, amigos[numAmigo].data.mes, amigos[numAmigo].data.ano);
                printf("nome adicionado! digite 1 para voltar para o menu ou 0 para finalizar");
                scanf("%d", &fov);
                system("cls");
                if(fov==1){
                    menuprincipal();
                }
                else{
                    return 0;
                }



            }
        }
    }
}

int excluiramigo(){
    char nome[100];
    int i, j,fov;
    int encontrado = 0;

    printf("Qual o nome do amigo que você quer excluir?\n ");
    fflush(stdin);
    gets(nome);
    for(i = 0; i < numAmigo; i++){
        int  aux=strcmp(amigos[i].nome, nome);
        if(aux == 0){  // Encontrou o amigo
            encontrado = 1;
            printf("amigo %s encontrado, excluindo\n", amigos[i].nome);
            
            // Liberar a memória alocada para o amigo
            free(amigos[i].nome);
            free(amigos[i].apelido);
            free(amigos[i].email);
            
            // Deslocar os elementos à esquerda para "remover" o amigo
            for(j = i; j < numAmigo - 1; j++){
                amigos[j] = amigos[j + 1];
            }
            amigos = (Tamigo *)realloc(amigos, (numAmigo - 1) * sizeof(Tamigo));
            numAmigo--;
            printf("amigo excluido!\n");
            break;
        }
    }

    if(!encontrado){
    printf("amigo não encontrado!\n");
    return 0;}
    printf("Quer retornar pro menu principal(1) ou finalizar(0)?");
    scanf("%d",&fov);
    if(fov==1){
    menuprincipal();
    }
    else{
    printf("programa finalizado!");
    return 0;
}}
int menulocal(){
    int op;
    printf("menu local\n 1-adicionar local\n 2-editar local\n 3-excluir local\n");
    scanf("%d", &op);
    system("cls");

    switch(op){
        case 1:
        adicionarlocal();
        break;
        case 2:
        editarlocal();
        break;
        case 3:
        excluirlocal();
        break;
        default:
        printf("opção inválida!, tente novamente");
        system("cls");
        menulocal();
       
    }
}
int adicionarlocal(){
    int fov;
    printf("você escolheu adicionar local\n");
     if(numLugar == 0)
    {
        lug = (Tlocal *)malloc(1 * sizeof(Tlocal));
    }
    else
    {
        lug = (Tlocal *)realloc(lug, (numLugar + 1) * sizeof(Tlocal));
    }
    printf("Qual o nome do lugar/encontro\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    lug[numLugar].nomeEncontro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(lug[numLugar].nomeEncontro, strAux);
    printf("%s\n",lug[numLugar].nomeEncontro);
    system("cls");
    printf("qual o logradouro(nome da rua)?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    lug[numLugar].lugar.logradouro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(lug[numLugar].lugar.logradouro, strAux);
    printf("%s\n",lug[numLugar].lugar.logradouro);
    system("cls");
    printf("digite o número do local\n");
    scanf("%d", &lug[numLugar].lugar.num);
    system("cls");
    printf("qual o bairro?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    lug[numLugar].lugar.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(lug[numLugar].lugar.bairro, strAux);
    printf("%s\n",lug[numLugar].lugar.bairro);
    system("cls");
    printf("qual a cidade?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    lug[numLugar].lugar.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(lug[numLugar].lugar.cidade, strAux);
    printf("%s\n",lug[numLugar].lugar.cidade);
    system("cls");
    printf("qual o estado?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    lug[numLugar].lugar.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(lug[numLugar].lugar.estado, strAux);
    printf("%s\n",lug[numLugar].lugar.estado);
    numLugar++;
    system("cls");
    printf("local adicionado! digite 1 para voltar para o menu e 0 para finalizar o programa");
    scanf("%d", &fov);
    system("cls");

    if(fov==1){
        menuprincipal();
    }
    else{
        return 0;
    }
    

}
int editarlocal(){
    int encontrado, dado;
    int fov;
    printf("Qual o nome do local que você quer editar?");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    for(int i = 0; i < numLugar; i++){
        int  aux=strcmp(lug[i].nomeEncontro,strAux);
        if(aux == 0)
        {
            encontrado = 1;
            printf("local %s encontrado\n", lug[i].nomeEncontro);
            printf("dados do local:\n nome(1):%s\n logradouro(2):%s\n numero(3):%i\n bairro(4):%s\n cidade(5):%s\n estado(6):%s\n", lug[i].nomeEncontro, lug[i].lugar.logradouro, lug[i].lugar.num,lug[i].lugar.bairro,lug[i].lugar.cidade,lug[i].lugar.estado);
            printf("qual dado você quer editar?\n");
            scanf("%d", &dado);
            system("cls");
            switch(dado)
            {
                case 1:
                printf("digite o novo nome do local:\n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                lug[i].nomeEncontro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(lug[i].nomeEncontro, strAux);
                printf("%s\n",lug[i].nomeEncontro);
                printf("editado! digite 1 para voltar pro  menu principal ou 0 para finalizar\n");
                scanf("%d", &fov);
                system("cls");
                if(fov==1){
                    menuprincipal();
                }
                else{
                    return 0;
                }
               break;

                case 2:
                printf("digite o novo logradouro:\n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                lug[i].lugar.logradouro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(lug[i].lugar.logradouro, strAux);
                printf("%s\n",lug[i].lugar.logradouro);
                system("cls");
                printf("editado! digite 1 para voltar pro  menu principal ou 0 para finalizar\n");
                scanf("%d", &fov);
                system("cls");
                if(fov==1){
                    menuprincipal();
                }
                else{
                    return 0;
                }
                break;

                case 3:
                printf("digite o novo numero:\n");
                scanf("%d", &lug[numLugar].lugar.num);
                system("cls");
                printf("digite 1 para voltar pro  menu principal ou 0 para finalizar");
                scanf("%d", &fov);
                system("cls");
                if(fov==1){
                    menuprincipal();
                }
                else{
                    return 0;
                }
                break;

                case 4:
                printf("digite o novo bairro:\n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                lug[i].lugar.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(lug[i].lugar.bairro, strAux);
                printf("%s\n",lug[i].lugar.bairro);
                system("cls");
                printf("editado! digite 1 para voltar pro  menu principal ou 0 para finalizar\n");
                scanf("%d", &fov);
                system("cls");
                if(fov==1){
                    menuprincipal();
                }
                else{
                    return 0;
                }
                break;

                case 5:
                printf("digite a nova cidade:\n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                lug[i].lugar.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(lug[i].lugar.cidade, strAux);
                printf("%s\n",lug[i].lugar.cidade);
                printf("digite 1 para voltar pro  menu principal ou 0 para finalizar");
                scanf("%d", &fov);
                if(fov==1){
                    menuprincipal();
                }
                else{
                    return 0;
                }
                break;

                case 6:
                printf("digite o novo estado:\n");
                fflush(stdin);
                gets(strAux);
                fflush(stdin);
                lug[i].lugar.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(lug[i].lugar.estado, strAux);
                printf("%s\n",lug[i].lugar.estado);
                system("cls");
                printf(" editado! digite 1 para voltar pro  menu principal ou 0 para finalizar\n");
                scanf("%d", &fov);
                system("cls");
                if(fov==1){
                    menuprincipal();
                }
                else{
                    return 0;
                }
                break;



                

            }
        }
    }

}
int excluirlocal(){
    char nome[100];
    int i, j,fov;
    int encontrado = 0;

    printf("Qual o nome do local que você quer excluir?\n ");
    fflush(stdin);
    gets(nome);
    for(i = 0; i < numLugar; i++){
        int  aux=strcmp(lug[i].nomeEncontro, nome);
        if(aux == 0){  
            encontrado = 1;
            printf("local %s encontrado, excluindo\n", amigos[i].nome);
            
            free(lug[i].nomeEncontro);
            free(lug[i].lugar.logradouro);
            free(lug[i].lugar.bairro);
            free(lug[i].lugar.cidade);
             free(lug[i].lugar.estado);
            // Deslocar os elementos à esquerda para "remover" o amigo
            for(j = i; j < numLugar - 1; j++){
                lug[j] = lug[j + 1];
            }
            lug = (Tlocal *)realloc(lug, (numLugar - 1) * sizeof(Tlocal));
            numAmigo--;
            printf("local excluido!\n");
            printf("quer voltar pro menu principal(1) ou finalizar o programa(0)");
            scanf("%d", &fov);
            system("cls");
            if(fov==1){
                menuprincipal();
            }
            else{
                return 0;
            
            break;
        }
    }

    if(!encontrado){
    printf("local não encontrado!\n");
    return 0;}
    printf("Quer retornar pro menu principal(1) ou finalizar(0)?");
    scanf("%d",&fov);
    system("cls");
    if(fov==1){
    menuprincipal();
    }
    else{
    printf("programa finalizado!");
    return 0;
}}}
void menucat(){
    int op;
    printf("menu categoria\n 1-adicionar categoria\n 2-editar categoria\n 3-excluir categoria\n");
    scanf("%d", &op);
    system("cls");
    switch(op){
        case 1:
        adicionarcategoria();
        break;
        case 2:
        editarcategoria();
        break;
        case 3:
        excluircategoria();
        break;
        default:
        printf("você escolheu uma opção inválida, tente novamente\n");
        menucat();
    }

}
int adicionarcategoria(){
     int fov;
    printf("você escolheu adicionar categoria");
     if(numCategoria == 0)
    {
        categorias = (Tcategoria *)malloc(1 * sizeof(Tcategoria));
    }
    else
    {
        categorias = (Tcategoria *)realloc(categorias, (numCategoria + 1) * sizeof(Tcategoria));
    }
    printf("Qual o nome da categoria?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    categorias[numCategoria].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(categorias[numCategoria].nome, strAux);
    printf("%s\n",categorias[numCategoria].nome);
    numCategoria++;
    system("cls");
    printf("adicionado! digite 1 para voltar ou 0 para finalizar\n");
    scanf("%d", &fov);
    system("cls");
    if(fov==1){
        menuprincipal();
    }
    else{
        return 0;
    }
    

}
int editarcategoria(){
    char categoria[100];
    int encontrado = 0, i,aux, fov;
    printf("digite o nome da categoria que você quer editar");
    gets(categoria);
    fflush(stdin);
    for(i=0;i<=numCategoria;i++){
    aux=strcmp(categoria, categorias[i].nome);
    if(aux==0){
        encontrado=1;
         printf("digite a nova categoria:\n");
                fflush(stdin);
                gets(categoria);
                fflush(stdin);
                categorias[i].nome = (char *)malloc((strlen(categoria) + 1) * sizeof(char));
                strcpy(categorias[i].nome, categoria);
                printf("%s\n",categorias[i].nome);
                system("cls");
                printf(" editado! digite 1 para voltar pro  menu principal ou 0 para finalizar\n");
                scanf("%d", &fov);
                system("cls");
                if(fov==1){
                    menuprincipal();
                }
                else{
                    return 0;
                }
                
    }
}
    
}

int excluircategoria(){
     char nome[100];
    int i, j,fov;
    int encontrado = 0;


    printf("Qual o nome da categoria que você quer excluir?\n ");
    fflush(stdin);
    gets(nome);
    for(i = 0; i <= numCategoria; i++){
        int  aux=strcmp(categorias[i].nome, nome);
        if(aux == 0){  
            encontrado = 1;
            printf("categoria  %s encontrado, excluindo\n", categorias[i].nome);
            
            free(categorias[i].nome);
            for(j = i; j < numCategoria - 1; j++){
                categorias[j] = categorias[j + 1];
            }
            categorias = (Tcategoria *)realloc(categorias, (numCategoria - 1) * sizeof(Tcategoria));
            numAmigo--;
            printf("categoria excluida!\n");
            printf("quer voltar pro menu principal(1) ou finalizar o programa(0)");
            scanf("%d", &fov);
            system("cls");
            if(fov==1){
                menuprincipal();
            }
            else{
               
                return 0;
            
            break;
        }
    }

    if(!encontrado){
    printf("categoria não encontrada!\n");
    return 0;}
    printf("Quer retornar pro menu principal(1) ou finalizar(0)?");
    scanf("%d",&fov);
    system("cls");
    if(fov==1){
    menuprincipal();
    }
    else{
    printf("programa finalizado!");
  
    return 0;
}}}
int horario(){
    
    printf("digite a hora do seu encontro(hora e minuto)");
    scanf("%d %d", &horas.hora, &horas.minutos);
    printf("%d:%d", horas.hora, horas.minutos);

}
void menuencontro(){
    int op;
    printf("menu encontro:\n");
    printf("1-adicionar encontro\n");
    printf("2-editar encontro\n");
    printf("3-excluir encontro\n");
    scanf("%d", &op);
    system("cls");
    switch(op){
        case 1:
        adicionarencontro();
        break;
    }
}
int adicionarencontro(){
    int op, i;
    for( i=0;i<=numEncontro;i++){
    printf("encontro %d\n", i+1);
    printf("primeiro adicione amigo(s) a esse encontro, digite 1 para adicionar\n");
    scanf("%d", &op);
    while(op==1){
    adicionaramigo();
    printf("quer adicionar mais algum amigo(1)?(digite 0 caso não)\n");
    scanf("%d", &op);
    }
    fflush(op);
    printf("agora adicione um local para o encontro, digite 1 para adicionar\n");
    scanf("%d", &op);
    while(op==1){
    adicionarlocal();
    printf("quer adicionar mais algum local(1)?(digite 0 caso não)\n");
    scanf("%d", &op);
    }
    fflush(op);
    printf("adicione uma categooria para esse encontro, digite 1 para adicionar");
    scanf("%d", &op);
    while(op==1){
    adicionarcategoria();
    printf("quer adicionar  mais alguma categoria(1)?(caso não digite 0)");
    scanf("%d", &op);
    }
    fflush(op);
    numEncontro++;

    
}}

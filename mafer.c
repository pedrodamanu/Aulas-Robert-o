#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// data
typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

// hora
typedef struct {
  int hora;
  int minuto;
} Hora;

// endereço
typedef struct {
  char *logradouro;
  int numero;
  char *bairro;
  char *cidade;
  char *estado;
} Endereco;

// local de encontro
typedef struct {
  char *nome_encontro;
  Endereco endereco;
} Local;

// categoria de encontro

typedef struct {
  char *nome;
} Categoria;

// amigo
typedef struct {
  char *nome;
  Data nascimento;
  char *apelido;
  char *email;
  char *telefone;
} Amigo;

//  encontro
typedef struct {
  Data data;
  Hora hora;
  Amigo *amigos;
  Categoria categoria;
  Local *local;
  char *descricao;
} Encontro;

// variaveisL globais
Local *locais;
int numlocais = 0;
Categoria *categorias;
int numcategorias = 0;
Encontro *encontros;
int numencontros = 0;
Amigo *amigos;
int numamigos = 0;
// funções
int excluiramigo();
int alteraramigo();
int validardata(Data d);
int cadastraramigo();
void menuprincipal();
void menu_amigo();
void menu_local();

int main() { 
  menuprincipal(); 
}
// coisas pós funções
int validardata(Data d) {
 
  if (d.mes < 1 || d.mes > 12)
    return 0; // Mês inválido

  
  if (d.dia < 1)
    return 0; // Dia inválido

 
  int ano_atual = 2024; // Substitua este valor pelo ano atual caso precise
                       
  if (d.ano < 1900 || d.ano > ano_atual) {
    return 0; // Ano inválido
  }

  // Verificar se o dia é válido para o mês
  if (d.mes == 2) {
    // Verificar fevereiro (ano bissexto)
    if ((d.ano % 4 == 0 && d.dia > 29) || (d.ano % 4 != 0 && d.dia > 28))
      return 0; // Dia inválido em fevereiro
  } else if (d.mes == 4 || d.mes == 6 || d.mes == 9 || d.mes == 11) {
    // Meses com 30 dias
    if (d.dia > 30)
      return 0; // Dia inválido para o mês
  } else {
    // Meses com 31 dias
    if (d.dia > 31)
      return 0; // Dia inválido para o mês
  }

  return 1; // Data válida
}
int excluiramigo() {
  char nome[100]; 
  int i, j, h, encontrado = 0; 

  
  printf("Digite o nome do amigo que deseja excluir: ");

  
  __fpurge(stdin);

 
  gets(nome);
  __fpurge(stdin);

 
  for (i = 0; i <= numamigos; i++) {
    
    int aux = strcmp(amigos[i].nome, nome); // Compara o nome do amigo da lista com o nome que o usuário inseriu
    if (aux == 0) { // Se a comparação retornar 0, significa que os nomes são iguais (encontrou o amigo)
      encontrado = 1; 
      printf("Amigo %s encontrado, excluindo\n", amigos[i].nome); 

      // Liberar a memória alocada para o amigo
      free(amigos[i].nome);
      free(amigos[i].apelido); 
      free(amigos[i].email); 
      free(amigos[i].telefone); 

      // Deslocar os elementos à esquerda para "remover" o amigo da lista
      for (j = i; j < numamigos - 1; j++) {
        amigos[j] = amigos[j + 1]; // Move o próximo amigo para a posição atual, efetivamente "apagando" o amigo que foi excluído
      }

      // Redimensiona o array para remover o espaço extra
      amigos = (Amigo *)realloc(amigos, (numamigos - 1) * sizeof(Amigo)); // Redefine o tamanho do array para um a menos, removendo o amigo da memória
      numamigos--; // Decrementa a quantidade de amigos, já que um foi excluído
      printf("Amigo excluido!\n"); 
      break;
    }
  }

  if (!encontrado) {
    printf("Amigo não encontrado!\n"); 
  }

  printf("Quer retornar pro menu principal(1) ou finalizar(0)?");
  scanf("%d", &h); 
  if (h == 1) {
    menuprincipal(); 
  } else {
    printf("programa finalizado!\n"); 
    return 0; 
  }

  return 0; 
}



int alteraramigo() {

    char aux[100];
    int dado, encontrado = 0, h;

    printf("Qual o nome do amigo que você quer alterar? ");
    __fpurge(stdin);  
    gets(aux);       

    __fpurge(stdin);

    for (int i = 0; i <= numamigos; i++) {  
        int aux2 = strcmp(amigos[i].nome, aux);  // Comparar o nome do amigo
        if (aux2 == 0) {
            encontrado = 1;
            printf("Amigo %s encontrado!\n", amigos[i].nome);
            printf("Dados do amigo:\n");
            printf("1. Nome: %s\n", amigos[i].nome);
            printf("2. Apelido: %s\n", amigos[i].apelido);
            printf("3. Email: %s\n", amigos[i].email);
            printf("4. Data de Nascimento: %02d/%02d/%d\n", amigos[i].nascimento.dia,
                   amigos[i].nascimento.mes, amigos[i].nascimento.ano);
            printf("5. Telefone: %s\n", amigos[i].telefone);  // Exibir o telefone

            printf("Qual dado você quer editar? (1 - Nome, 2 - Apelido, 3 - Email, 4 - Data de Nascimento, 5 - Telefone): ");
            scanf("%d", &dado);
            __fpurge(stdin);  // Limpar o buffer após scanf

            switch (dado) {
            case 1:
                printf("Digite o novo nome:\n");
                __fpurge(stdin); 
                gets(aux);        
                // Liberar memória antiga e alocar nova para o nome
                free(amigos[i].nome);
                amigos[i].nome = (char *)malloc((strlen(aux) + 1) * sizeof(char));
                strcpy(amigos[i].nome, aux);
                printf("Novo nome: %s\n", amigos[i].nome);
                break;

            case 2:
                printf("Digite o novo apelido:\n");
                __fpurge(stdin);  
                gets(aux);       

                // Liberar memória antiga e alocar nova para o apelido
                free(amigos[i].apelido);
                amigos[i].apelido = (char *)malloc((strlen(aux) + 1) * sizeof(char));
                strcpy(amigos[i].apelido, aux);
                printf("Novo apelido: %s\n", amigos[i].apelido);
                break;

            case 3:
                printf("Digite o novo email:\n");
                __fpurge(stdin); 
                gets(aux);        

                // Liberar memória antiga e alocar nova para o email
                free(amigos[i].email);
                amigos[i].email = (char *)malloc((strlen(aux) + 1) * sizeof(char));
                strcpy(amigos[i].email, aux);
                printf("Novo email: %s\n", amigos[i].email);
                break;

            case 4:
                printf("Digite a nova data de nascimento (dia mês ano): ");
                scanf("%d %d %d", &amigos[i].nascimento.dia, &amigos[i].nascimento.mes, &amigos[i].nascimento.ano);

                if (!validardata(amigos[i].nascimento)) {
                    printf("Data inválida! A data não foi alterada.\n");
                } else {
                    printf("Nova data de nascimento: %02d/%02d/%d\n",
                           amigos[i].nascimento.dia, amigos[i].nascimento.mes, amigos[i].nascimento.ano);
                }
                break;

            case 5:
                printf("Digite o novo telefone (DD XXXX XXXX):\n");
                __fpurge(stdin); 
                gets(aux);       

                // Liberar memória antiga e alocar nova para o telefone
                free(amigos[i].telefone);
                amigos[i].telefone = (char *)malloc((strlen(aux) + 1) * sizeof(char));
                strcpy(amigos[i].telefone, aux);
                printf("Novo telefone: %s\n", amigos[i].telefone);
                break;

            default:
                printf("Opção inválida!\n");
                break;
            }
            break;  // Sai do loop após encontrar o amigo
        }
    }

    if (!encontrado) {
        printf("Amigo não encontrado!\n");
    }
  printf("Quer retornar pro menu principal(1) ou finalizar(0)?");
  scanf("%d",&h);
  if(h==1){
      menuprincipal();
  }
  else{
      printf("programa finalizado!");
      return 0;
  }
    return 0;
}


  
int cadastraramigo() {
  char aux[100];
  int h;
  if (numamigos == 0) {
    amigos = (Amigo *)malloc(sizeof(Amigo));
  } else {
    amigos = (Amigo *)realloc(amigos, (numamigos + 1) * sizeof(Amigo));
  }
  // pegar nome

  printf("qual o nome do amigo\n ");
  __fpurge(stdin);
  gets(aux);
  __fpurge(stdin);
  amigos[numamigos].nome = (char *)malloc((strlen(aux) + 1) * sizeof(char));
  strcpy(amigos[numamigos].nome, aux);
  // pegar apelido

  printf("qual o apelido do amigo\n ");
  __fpurge(stdin);
  gets(aux);
  __fpurge(stdin);
  amigos[numamigos].apelido = (char *)malloc((strlen(aux) + 1) * sizeof(char));
  strcpy(amigos[numamigos].apelido, aux);
  // pegar email

  printf("Qual o email do seu amigo\n");
 __fpurge;
  gets(aux);
 __fpurge;
  amigos[numamigos].email = (char *)malloc((strlen(aux) + 1) * sizeof(char));
  strcpy(amigos[numamigos].email, aux);
  // pegar telefone

  printf("Qual o telefone do amigo: DD XXXX XXXX\n");
 __fpurge;
  gets(aux);
 __fpurge;
  amigos[numamigos].telefone = (char *)malloc((strlen(aux) + 1) * sizeof(char));
  strcpy(amigos[numamigos].telefone, aux);

  // pegar data de nascimento

  int data_valida = 0;
  while (!data_valida) {
    printf("Digite a data de nascimento do seu amigo (dia mês ano): ");
    scanf("%d %d %d", &amigos[numamigos].nascimento.dia,
          &amigos[numamigos].nascimento.mes, &amigos[numamigos].nascimento.ano);

    // Validar a data
    data_valida = validardata(amigos[numamigos].nascimento);
    if (!data_valida) {
      printf("Data inválida. Tente novamente.\n");
    }
  }
  printf("Quer retornar pro menu principal(1) ou finalizar(0)?");
    scanf("%d",&h);
    if(h==1){
        menuprincipal();
    }
    else{
        printf("programa finalizado!");
        return 0;
    }
  numamigos++;
}
void menu_amigo() {
  int opcao = 0;
  printf("1 - cadastrar amigo\n");
  printf("2 - alterar amigo\n");
  printf("3 - excluir amigo\n");
  scanf("%d", &opcao);
  switch (opcao) {
  case 1:
    cadastraramigo();
    break;

  case 2:
    alteraramigo();
    break;
  case 3:
    excluiramigo();
    break;
    printf("opção inválida!, tente novamente");
        system("cls");
        menu_amigo();
  }
}

void  menuprincipal() {
  int opcao = 0;
  printf("1 - manter amigo\n");
  printf("2 - manter local \n");
  printf("3 - manter categoria\n");
  printf("4 - manter encontro\n");
  printf("5 - relatórios\n");
  printf("6 - sair\n");
  printf("escolha uma opção: ");
  scanf("%d", &opcao);

  switch (opcao) {
  case 1:
    menu_amigo();
    break;
  
  case 2:
    menu_local();
    break;
    printf("opção inválida!, tente novamente");
        system("cls");
        menuprincipal();

  }
}

void menu_local(){
  int opcao = 0;
  printf("1 - cadastrar local\n");
  printf("2 - alterar local\n");
  printf("3 - excluir local\n");
  scanf("%d", &opcao);
  switch (opcao){
    case 1:
      // funcao cadastrar local
    break;
    case 2:
      // funcao alterar local
    break;
    case 3:
      // funcao excluir local
    break;
    default:
        printf("opção inválida!, tente novamente");
        system("cls");
        menulocal();
  }
}

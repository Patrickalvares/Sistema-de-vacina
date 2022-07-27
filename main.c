#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct {
  int codigo;
  char nome[50];
  char cpf[15];
  char vacina[30];
  char data[12];
  long int lote;
}
pessoa;

//Variaveis Globais
int numMenu = 0;
int contCod = 0;
int comp = 0;
pessoa vacinado[50];
//
void clrscr() {
  fprintf(stdout, "\033[2J\033[0;0f");
  fflush(stdout);
}

void cadastrar() {
  clrscr();
  __fpurge(stdin);
  printf("====================================================================\n");
  printf("Menu de Cadastro:\n");
  vacinado[contCod].codigo = contCod;

  printf("\n\nDigite o nome do Vacinado: ");
  fgets(vacinado[contCod].nome, 50, stdin);
  __fpurge(stdin);

  printf("\n\nDigite o CPF do Vacinado (SOMENTE NÚMEROS): ");
  fgets(vacinado[contCod].cpf, 15, stdin);
  __fpurge(stdin);

  printf("\n\nDigite o nome da Vacina aplicada: ");
  scanf("%s", & vacinado[contCod].vacina);
  __fpurge(stdin);

  printf("\n\nDigite a data de aplicação (dd/mm/aaaa): ");
  scanf("%s", & vacinado[contCod].data);
  __fpurge(stdin);

  printf("\n\nDigite o número do lote da vacina: ");
  scanf("%ld", & vacinado[contCod].lote);
  __fpurge(stdin);

  contCod++;

}
void listar() {
  clrscr();
  printf("Vacinado(s) em nosso banco de dados");
  for (int i = 0; i < contCod; i++) {
    printf("\n\nCódigo: %d\n", vacinado[i].codigo);
    printf("Nome: %s\n", vacinado[i].nome);
    printf("Cpf: %s\n", vacinado[i].cpf);
    printf("Vacina: %s\n", vacinado[i].vacina);
    printf("Data: %s\n", vacinado[i].data);
    printf("Numero do Lote: %ld\n\n", vacinado[i].lote);
    printf("====================================================================");
  }

}
void comparar() {
  clrscr();
  char cpf2[15];
  printf("Digite o CPF a ser buscado no banco de dados (SOMENTE NÚMEROS): \n");
  printf("-> ");
  fgets(cpf2, 15, stdin);
  __fpurge(stdin);
  while (comp < contCod) {
    if (strcmp(cpf2, vacinado[comp].cpf) == 0) {
      clrscr();
      printf("====================================================================\n\n");
      printf("CPF encontrado!\n\n");
      printf("====================================================================");
      printf("\n\nCódigo: %d\n", vacinado[comp].codigo);
      printf("Nome: %s\n", vacinado[comp].nome);
      printf("Cpf: %s\n", vacinado[comp].cpf);
      printf("Vacina: %s\n", vacinado[comp].vacina);
      printf("Data: %s\n", vacinado[comp].data);
      printf("Numero do Lote: %ld\n\n", vacinado[comp].lote);
      printf("====================================================================");
      break;
    } else {
      clrscr();
      printf("CPF não encontrado");
      comp++;
    }
  }
}
void menu() {
  printf("Digite 1 para: Cadastrar Vacina\n");
  printf("Digite 2 para: Listar Aplicações\n");
  printf("Digite 3 para: Consultar por CPF\n");
  printf("Digite 4 para: Sair\n");
  printf("-> ");
  scanf("%d", & numMenu);
  __fpurge(stdin);

  switch (numMenu) {
  case 1:
    cadastrar();
    clrscr();
    printf("====================================================================\n\n");
    printf("Cadastro Feito com Sucesso!!\n\nO que deseja fazer agora?\n\n");
    printf("====================================================================\n\n");
    menu();
    break;

  case 2:
    listar();
    printf("\n\nO que deseja fazer agora?\n\n");
    menu();
    break;

  case 3:
    comp = 0;
    comparar();
    printf("\n\nO que deseja fazer agora?\n\n");
    menu();
    break;

  case 4:
    clrscr();
    printf("====================================================================\n\n");
    printf("Tem certeza? todos os cadastros serão perdidos ao encerrar o programa.\n\n");
    printf("Digite 1 para voltar ao menu.\nDigite 2 para encerrar.\n");
    int saida = 0;
    scanf("%d", & saida);
    __fpurge(stdin);
    switch (saida) {
    case 1:
      clrscr();
      printf("====================================================================");
      printf("\n\nO que deseja fazer agora?\n\n");
      menu();
      break;

    case 2:
      clrscr();
      printf("\n\nAté a Proxima!\n\n");
      break;
    default:
      clrscr();
      printf("Opção Invalida\n\n");
      menu();
      break;
    }
    break;

  default:
    clrscr();
    printf("Opção Invalida\n\n");
    menu();
    break;

  }
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  printf("***Bem vindo ao registro de dados de aplicação de vacina***\n\n");

  menu();

  return 0;
}
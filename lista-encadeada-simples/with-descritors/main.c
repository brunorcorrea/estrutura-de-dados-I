#include "les-descritor.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int info;
  int pos;
  int erro;
  Tdescritorno_ls desc;
  int q;
  erro = Inicializar_LS(&desc);
  do {
    clearConsole();
    printf("1 -> Inserir no inicio\n");
    printf("2 -> Inserir no final\n");
    printf("3 -> Remover no inicio\n");
    printf("4 -> Mostrar toda a lista \n");
    printf("5 -> Inicializar a lista (versao 2)\n");
    printf("6 -> Sair \n");
    printf("7 -> Copiar Lista\n");
    printf("8 -> Inserir no meio\n");
    printf("9 -> Obter dado na lista\n");
    printf(":");
    scanf("%d", &q); /* Ler a opcao do usuario */
    switch (q) {
    case 1:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);
      erro = Inserir_inicio_LS(&desc, info);
      if (erro == 0)
        printf("Insercao realizada com sucesso\n");
      awaitUserInput();
      break;
    case 2:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);
      Inserir_fim_LS(&desc, info);
      if (erro == 0)
        printf("Insercao realizada com sucesso\n");
      awaitUserInput();
      break;
    case 3:
      erro = Remover_inicio_LS(&desc);
      if (erro == 0) {
        printf("Remocao realizada com sucesso \n");
      } else if (erro == 1) {
        printf("\nLista vazia. Impossivel remover\n");
      }
      awaitUserInput();
      break;
    case 4:
      erro = Listar_LS(desc);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel listar\n");
      }
      awaitUserInput();
      break;
    case 5:
      erro = Inicializar2_LS(&desc);
      printf("\nInicializacao realizada com sucesso !\n");
      printf("\nLISTA VAZIA !\n");
      awaitUserInput();
      break;
    case 6:
      break;
    case 7:
      //   erro = Copia_lista(&desc);
      break;
    case 8:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);

      printf("Posicao para insercao na lista: ");
      scanf("%d", &pos);

      erro = Inserir_meio_LS(&desc, info, pos);

      if (erro == 0)
        printf("Insercao realizada com sucesso! \n");
      else if (erro == 1)
        printf("Lista vazia !\n");
      else if (erro == 2)
        printf("A posicao solicitada e maior que o tamanho da lista !\n");

      awaitUserInput();
      break;
    case 9:
      printf("Posicao do dado na lista: ");
      scanf("%d", &pos);

      erro = Obter_dado_LS(desc, pos, &info);
      if (erro == 1) {
        printf("Lista vazia !\n");
      } else if (erro == 2) {
        printf("A posicao solicitada e maior que o tamanho da lista !\n");
      } else {
        printf("Dado na posicao solicitada: | %d |\n", info);
      }

      awaitUserInput();
      break;
    default:
      printf("\n\n Opcao nao valida");
    }
    getchar(); /* Limpa o buffer de entrada */
  } while ((q != 6));
}

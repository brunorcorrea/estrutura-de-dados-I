#include "les-methods.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int info;
  int resp, pos;
  ListNode *inicio;
  int chosenOption;
  int erro = initializeEmptyList(&inicio);

  printf("Tamanho do no: %d\n\n", sizeof(ListNode));
  awaitUserInput();

  do {
    clearConsole();
    printf("LISTA ENCADEADA SIMPLES - LES");

    printOptions();
    scanf("%d", &chosenOption);

    switch (chosenOption) {
    case 1:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);

      erro = insertNodeInListStart(&inicio, info);
      if (erro == 0)
        printf("Insercao realizada com sucesso\n");

      awaitUserInput();
      break;
    case 2:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);

      insertNodeInListEnd(&inicio, info);

      break;
    case 3:
      erro = removeNodeInListStart(&inicio);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel remover");
      }

      awaitUserInput();
      break;
    case 4:
      erro = getAllListNodes(inicio);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel listar !\n");
      }

      awaitUserInput();
      break;
    case 5:
      erro = cleanAllListNodes(&inicio);

      printf("\nInicializacao realizada com sucesso !\n");
      printf("\nLISTA VAZIA !\n");

      awaitUserInput();
      break;
    case 6:
      erro = invertList_2(&inicio);
      if (erro == 1)
        printf("\nLista vazia. Inversao nao realizada !\n");
      else
        printf("\nInversao realizada !\n");

      awaitUserInput();
      break;
    case 7:
      printf("Posicao para remocao: ");
      scanf("%d", &pos);

      erro = removeNodeInListGivenPosition(&inicio, pos);
      if (erro == 1)
        printf("Lista vazia. Remocao nao realizada !\n");
      else if (erro == 2)
        printf("Posicao nao existe. Remocao nao realizada !\n");

      awaitUserInput();
      break;
    case 8:
      erro = removeNodeInListEnd(&inicio);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel remover ! \n");
      }

      awaitUserInput();
      break;
    case 9:
      break;
    case 10:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);

      printf("Posicao de insercao: ");
      scanf("%d", &pos);

      erro = insertNodeInListGivenPosition(&inicio, info, pos);
      if (erro == 0)
        printf("Insercao realizada com sucesso\n");

      awaitUserInput();
      break;
    case 11:
      printf("Dado para verificar repeticao na lista: ");
      scanf("%d", &info);

      int resp;
      erro = VerifyRepeatedValueInList(inicio, info, &resp);
      if (erro == 0) {
        if (resp == 1)
          printf("O dado esta repetido na estrutura !\n");
        else
          printf("O dado nao esta repetido na estrutura !\n");
      } else {
        printf("\nLista vazia. Verificacao nao realizada !\n");
      }

      awaitUserInput();
      break;
    case 12:
      printf(
          "Dado para contar quantidade de elementos maior que ele na lista: ");
      scanf("%d", &info);

      int quant;
      erro = countElementsAboveValue(inicio, info, &quant);
      if (erro == 0) {
        printf("\nQuantidade de elementos maior que o dado valor: %d\n", quant);
      } else {
        printf("\nLista vazia. Busca nao realizada !\n");
      }

      awaitUserInput();
      break;
    default:
      printf("\n\n Opcao invalida !\n");
    }

    getchar();
  } while ((chosenOption != 9));
}

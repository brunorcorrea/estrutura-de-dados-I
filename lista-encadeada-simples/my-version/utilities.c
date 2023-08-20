#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
void clearConsole() { system("cls"); }

void awaitUserInput() { system("pause"); }
#endif

#ifdef linux
void clearConsole() { system("clear"); }

void awaitUserInput() {
  printf("\nPressione qualquer tecla para continuar...\n");
  getchar();
}
#endif

void printOptions() {
  printf("\n\nOpcoes: \n\n");
  printf("1 -> Inserir no inicio \n");
  printf("2 -> Inserir no final\n");
  printf("3 -> Remover no inicio\n");
  printf("4 -> Mostrar toda a lista \n");
  printf("5 -> Inicializar a lista (versao 2)\n");
  printf("6 -> Inverter a lista\n");
  printf("7 -> Remover no meio\n");
  printf("8 -> Remover no fim\n");
  printf("9 -> Sair\n");
  printf("10 -> Inserir no meio\n");
  printf("11 -> Verificar se dado repete na lista\n");
  printf("12 -> Obter quantidade de dados maior que o valor inserido\n");
  printf(":");
}

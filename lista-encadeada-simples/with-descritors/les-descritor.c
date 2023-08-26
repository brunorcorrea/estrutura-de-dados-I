#include "les-descritor.h"
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

int Inicializar_LS(Tdescritorno_ls *pdesc) {
  pdesc->prim = NULL;
  pdesc->ult = NULL;
  pdesc->tam = 0;

  return 0;
}

int Inicializar2_LS(Tdescritorno_ls *pdesc) {
  if (pdesc == NULL)
    return 1;

  while (pdesc->prim != NULL)
    Remover_inicio_LS(pdesc);

  return 0;
}

int Inserir_inicio_LS(Tdescritorno_ls *pdesc, int info) {
  Tno_ls *no_novo, *aux;

  no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
  no_novo->dado = info;

  if (pdesc->tam == 0) {
    pdesc->prim = no_novo;
    pdesc->ult = no_novo;
    no_novo->prox = NULL;
    pdesc->tam = 1;
  } else {
    aux = pdesc->prim;
    pdesc->prim = no_novo;
    no_novo->prox = aux;
    pdesc->tam++;
  }
  return 0;
}

int Inserir_fim_LS(Tdescritorno_ls *pdesc, int info) {
  Tno_ls *no_novo, *aux;
  no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
  no_novo->dado = info;
  no_novo->prox = NULL;

  if (pdesc->tam == 0) {
    pdesc->prim = no_novo;
    pdesc->ult = no_novo;
    pdesc->tam = 1;
  } else {
    aux = pdesc->ult;
    pdesc->ult = no_novo;
    aux->prox = no_novo;
    pdesc->tam++;
  }

  return 0;
}

int Inserir_meio_LS(Tdescritorno_ls *pdesc, int info, int pos) {
  if (pdesc == NULL)
    return 1;
  if (pos > pdesc->tam)
    return 2;

  if (pos == 0)
    return Inserir_inicio_LS(pdesc, info);

  if (pdesc->tam == pos)
    return Inserir_fim_LS(pdesc, info);

  Tno_ls *percorre = pdesc->prim;
  for (int contador = 0; pos - 1 > contador; contador++) {
    percorre = percorre->prox;
  }

  Tno_ls *no_novo, *aux;
  no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
  no_novo->dado = info;

  aux = percorre->prox;
  percorre->prox = no_novo;
  no_novo->prox = aux;

  pdesc->tam++;

  return 0;
}

int Remover_inicio_LS(Tdescritorno_ls *pdesc) {
  if (pdesc == NULL || pdesc->prim == NULL)
    return 1;

  if (pdesc->tam == 1)
    pdesc->ult = NULL;

  Tno_ls *remover = pdesc->prim;
  pdesc->prim = remover->prox;
  pdesc->tam--;
  free(remover);
  return 0;
}

int Listar_LS(Tdescritorno_ls cdesc) {
  if (cdesc.prim == NULL || cdesc.ult == NULL) {
    return 1;
  }

  Tno_ls *percorre = cdesc.prim;
  printf("LISTA :: ");
  while (percorre != NULL) {
    printf(" | %d", percorre->dado);
    percorre = percorre->prox;
  }
  printf(" |\n");
}

int Obter_dado_LS(Tdescritorno_ls cdesc, int pos, int *dado) {
  if (cdesc.prim == NULL)
    return 1;
  if (pos >= cdesc.tam)
    return 2;

  for (int posicao = 0; posicao < pos; posicao++)
    cdesc.prim = cdesc.prim->prox;

  *dado = cdesc.prim->dado;
  return 0;
}

// int Copia_lista(Tdescritorno_ls *l1, Tdescritorno_ls *l2) {
//   Tno_ls *aux;
//   aux = l1->prim;
// }
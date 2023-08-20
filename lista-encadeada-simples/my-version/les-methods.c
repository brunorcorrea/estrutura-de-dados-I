#include "les-methods.h"
#include <stdio.h>
#include <stdlib.h>

int initializeEmptyList(Tno_ls **p_inicio) {
  *p_inicio = NULL;
  return 0;
}

int cleanAllListNodes(Tno_ls **p_inicio) {
  Tno_ls *percorre, *aux;
  if (*p_inicio != NULL) {
    percorre = *p_inicio;
    while (percorre != NULL) {
      aux = percorre;
      percorre = percorre->prox;
      free(aux);
    }
    *p_inicio = NULL;
    return 1;
  }
}

int insertNodeInListStart(Tno_ls **p_inicio, int info) {
  Tno_ls *no_novo;

  no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
  no_novo->dado = info;

  if (*p_inicio == NULL) {
    no_novo->prox = NULL;
    *p_inicio = no_novo;
  } else {
    no_novo->prox = *p_inicio;
    *p_inicio = no_novo;
  }
  return 0;
}

int Inserir_meio_LS(Tno_ls **p_inicio, int info, int pos) {
  int tam;
  Tno_ls *no_novo, *percorre;

  if (pos <= 0)
    return 1; /*) posicao invalida para insercao */

  Obter_Tamanho_LS(*p_inicio, &tam);
  if (pos > tam + 1)
    return 2; /* posicao invalida. Acima do tamanho da lista */

  no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
  no_novo->dado = info;

  if (pos == 1) {
    insertNodeInListStart(p_inicio, info);
  } else {
    if (pos == tam + 1) {
      insertNodeInListEnd(p_inicio, info);
    } else {
      int pos_aux = 1;
      percorre = *p_inicio;
      while (pos_aux != pos - 1) /* parar uma posicao antes */
      {
        percorre = percorre->prox;
        pos_aux++;
      }
      no_novo->prox = percorre->prox;
      percorre->prox = no_novo;
    }
  }
  return 0;
}

int insertNodeInListEnd(Tno_ls **p_inicio, int info) {
  Tno_ls *no_novo, *percorre;

  no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
  no_novo->dado = info;
  no_novo->prox = NULL;

  if (*p_inicio == NULL) { /* lista vazia. */
    *p_inicio = no_novo;
  } else { /* lista nao vazia */
    percorre = *p_inicio;
    while (percorre->prox != NULL) {
      percorre = percorre->prox;
    }
    percorre->prox = no_novo;
  }
  return 0;
}

int Listar_LS(Tno_ls *c_inicio) {
  int i;
  if (c_inicio == NULL) {
    return 1; /* lista vazia */
  }
  printf("LISTA ::  ");
  while (c_inicio != NULL) {
    printf("%d  ", c_inicio->dado);
    c_inicio = c_inicio->prox;
  }
  printf("\n");
  return 0; /* sem erro */
}

int Obter_Tamanho_LS(Tno_ls *c_inicio, int *tam) {
  Tno_ls *percorre;
  *tam = 0;
  if (c_inicio != NULL) {
    percorre = c_inicio;
    while (percorre != NULL) {
      (*tam)++;
      percorre = percorre->prox;
    }
  } else {
    *tam = 0;
  }
}

int Obter_Pos_LS(Tno_ls *c_inicio, int valor, int *pos) {
  *pos = 0;
  while (c_inicio != NULL) {
    (*pos)++;
    if (valor == c_inicio->dado)
      return 0; /* dado encontrado */
    c_inicio = c_inicio->prox;
  }
  if (c_inicio != NULL)
    *pos = 0;
  return 1; /* dado nao encontrado */
}

int Remover_inicio_LS(Tno_ls **p_inicio) {
  Tno_ls *aux;
  if (*p_inicio == NULL) {
    return 1;
  } else {
    aux = *p_inicio;
    *p_inicio = (*p_inicio)->prox;
    free(aux);
    return 0;
  }
}

int Remover_meio_LS(Tno_ls **p_inicio, int pos) {
  if (*p_inicio == NULL)
    return 1;

  int tam;
  Obter_Tamanho_LS(*p_inicio, &tam);
  if (pos >= tam)
    return 2;

  if (tam == 1) {
    *p_inicio = NULL;
    free(*p_inicio);
    return 0;
  }

  Tno_ls *aux, *aux2, *remover;
  aux = *p_inicio;
  for (int contador = 0; contador < pos; contador++) {
    aux = aux->prox;
  }

  remover = aux->prox;
  aux2 = remover->prox;
  aux->prox = aux2;
  free(remover);

  return 0;
}

int Remover_fim_LS(Tno_ls **p_inicio) {
  if (*p_inicio == NULL)
    return 1;
  else if ((*p_inicio)->prox == NULL) {
    *p_inicio = NULL;
    free(*p_inicio);
    return 0;
  }

  Tno_ls *aux, *remover;
  aux = *p_inicio;
  while (aux->prox->prox != NULL)
    aux = aux->prox;

  remover = aux->prox;
  aux->prox = NULL;
  free(remover);

  return 0;
}

int Inverter_LS(Tno_ls **p_inicio) {
  Tno_ls *percorre, *aux_1, *aux_2, *aux_3;
  percorre = *p_inicio;
  if (percorre == NULL) {
    return 1; /*Caso a lista esteja vazia. */
  } else if (percorre->prox == NULL) {
    return 0; /*Caso a lista tenha apenas um n�. */
  } else {
    aux_1 = *p_inicio; /*O ponteiro aux_a aponta para o primeiro n�, uma vez que
                          o ponteiro "ini" passar� a apontar para o �ltimo. */
    aux_2 = aux_1->prox; /*O ponteiro aux_p passa a apontar para o segundo n� da
                            lista.*/
    aux_3 = aux_2->prox; /*O ponteiro aux_v passa a apontar para o terceiro n�
                            da lista.*/
    aux_1->prox = NULL; /*O primeiro n� da lista passa a ser o �ltimo, apontando
                           para NULL.*/
    aux_2->prox = aux_1; /*O segundo n� da lista passa a apontar para o
                            primeiro, come�ando a invers�o da lista.*/
                         /*In�cio - Processo de invers�o.*/
    while (aux_3 != NULL) {
      aux_1 =
          aux_2; /*O ponteiro aux_a pega o valor do n� a sua frente na lista.*/
      aux_2 =
          aux_3; /*O ponteiro aux_p pega o valor do n� a sua frente na lista.*/
      aux_3 = aux_3->prox; /*O ponteiro aux_v pega o valor do n� a sua frente na
                              lista.*/
      aux_2->prox = aux_1; /*O n� para o qual aux_p est� apontado passa a
                              apontar para o n� anterior a ele na lista.*/
    }
    *p_inicio = aux_2;
  }

  return 0;
}

int Inverter_LS_2(Tno_ls **p_inicio) {
  int i, erro, tam, info;
  Tno_ls *inicio_lista_aux; /* lista auxiliar */

  erro = Obter_Tamanho_LS(*p_inicio, &tam);
  if (tam == 0) {
    return 1; /*Caso a lista esteja vazia.*/
  } else if (tam == 1) {
    return 0; /*Caso a lista tenha apenas um n�.*/
  } else {
    initializeEmptyList(&inicio_lista_aux);
    for (i = 1; i <= tam; i++) {
      info = (*p_inicio)->dado; /* obtendo o dado do 1o. n� */
      // Obter_Dado_LS (p_inicio, 1, &info);
      Remover_inicio_LS(p_inicio);
      insertNodeInListStart(&inicio_lista_aux, info);
    }
    *p_inicio = inicio_lista_aux;
  }
  return 0;
}

int Ver_Repete_Dado_LS(Tno_ls *c_inicio, int info, int *resp) {
  if (c_inicio == NULL)
    return 1;

  *resp = 0;
  Tno_ls *aux = c_inicio;
  while (aux->prox != NULL) {
    if (aux->dado == info) {
      Tno_ls *aux2 = aux->prox;
      while (aux2 != NULL) {
        if (aux2->dado == info) {
          (*resp)++;
          return 0;
        }
        aux2 = aux2->prox;
      }
    }

    aux = aux->prox;
  }

  return 0;
}

int Maiorque_Dado_LS(Tno_ls *c_inicio, int info, int *quant) {
  *quant = 0;
  if (c_inicio == NULL)
    return 1;

  Tno_ls *aux = c_inicio;
  while (aux != NULL) {
    if (aux->dado > info)
      (*quant)++;
    aux = aux->prox;
  }

  return 0;
}
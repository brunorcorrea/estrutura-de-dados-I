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

struct no_ls {
  int dado;
  struct no_ls *prox;
};

typedef struct no_ls Tno_ls;

/* Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...
*/

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
  printf(":");
}

int Inicializar_LS(Tno_ls **p_inicio);
int Inicializar2_LS(Tno_ls **p_inicio);
int Inserir_inicio_LS(Tno_ls **p_inicio, int info);
int Inserir_fim_LS(Tno_ls **p_inicio, int info);
int Inserir_meio_LS(Tno_ls **p_inicio, int info, int pos);
int Remover_inicio_LS(Tno_ls **p_inicio);
int Remover_meio_LS(Tno_ls **p_inicio, int pos);
int Remover_fim_LS(Tno_ls **p_inicio);
int Listar_LS(Tno_ls *c_inicio);
int Obter_pos_LS(Tno_ls *c_inicio, int dado, int *pos);
int Obter_Tamanho_LS(Tno_ls *c_inicio, int *tam);
int Inverter_LS(Tno_ls **p_inicio);
int Inverter_LS_2(Tno_ls **p_inicio);

int main(void) {

  int info;
  int resp, pos;
  Tno_ls *inicio;
  int chosenOption;
  int erro = Inicializar_LS(&inicio);

  printf("Tamanho do no: %d\n\n", sizeof(Tno_ls));
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

      erro = Inserir_inicio_LS(&inicio, info);
      if (erro == 0)
        printf("Insercao realizada com sucesso\n");

      awaitUserInput();
      break;
    case 2:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);

      Inserir_fim_LS(&inicio, info);

      break;
    case 3:
      erro = Remover_inicio_LS(&inicio);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel remover");
      }

      awaitUserInput();
      break;
    case 4:
      erro = Listar_LS(inicio);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel listar !\n");
      }

      awaitUserInput();
      break;
    case 5:
      erro = Inicializar2_LS(&inicio);

      printf("\nInicializacao realizada com sucesso !\n");
      printf("\nLISTA VAZIA !\n");

      awaitUserInput();
      break;
    case 6:
      erro = Inverter_LS_2(&inicio);
      if (erro == 1)
        printf("\nLista vazia. Inversao nao realizada !\n");
      else
        printf("\nInversao realizada !\n");

      awaitUserInput();
      break;
    case 7:
      printf("Posicao para remocao: ");
      scanf("%d", &pos);

      erro = Remover_meio_LS(&inicio, pos);
      if (erro == 1)
        printf("Lista vazia. Remocao nao realizada !\n");
      else if (erro == 2)
        printf("Posicao nao existe. Remocao nao realizada !\n");

      awaitUserInput();
      break;
    case 8:
      erro = Remover_fim_LS(&inicio);
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

      erro = Inserir_meio_LS(&inicio, info, pos);
      if (erro == 0)
        printf("Insercao realizada com sucesso\n");

      awaitUserInput();
      break;
    default:
      printf("\n\n Opcao invalida !\n");
    }

    getchar();
  } while ((chosenOption != 9));
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

int Inicializar_LS(Tno_ls **p_inicio) {
  *p_inicio = NULL;
  return 0; /* sem erro */
}

int Inicializar2_LS(Tno_ls **p_inicio) {
  Tno_ls *percorre, *aux;
  if (*p_inicio != NULL) {
    percorre = *p_inicio;
    while (percorre != NULL) {
      aux = percorre;
      percorre = percorre->prox;
      free(aux);
    }
    *p_inicio = NULL;
    return 1; /* inicializa apagando tudo da listsa */
  }
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

int Inserir_inicio_LS(Tno_ls **p_inicio, int info) {
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
    Inserir_inicio_LS(p_inicio, info);
  } else {
    if (pos == tam + 1) {
      Inserir_fim_LS(p_inicio, info);
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

int Inserir_fim_LS(Tno_ls **p_inicio, int info) {
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
    Inicializar_LS(&inicio_lista_aux);
    for (i = 1; i <= tam; i++) {
      info = (*p_inicio)->dado; /* obtendo o dado do 1o. n� */
      // Obter_Dado_LS (p_inicio, 1, &info);
      Remover_inicio_LS(p_inicio);
      Inserir_inicio_LS(&inicio_lista_aux, info);
    }
    *p_inicio = inicio_lista_aux;
  }
  return 0;
}

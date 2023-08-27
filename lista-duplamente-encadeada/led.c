//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//---------------------------------------------------------------------------

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA DUPLA
------------------------------------------------------------------------------*/

typedef struct no_ld {
  int dado;
  struct no_ld *prox, *ant;
} Tno_ld;

// Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LD(Tno_ld **inicio);

int Inicializar2_LD(Tno_ld **p_inicio);                    //
int Inserir_inicio_LD(Tno_ld **p_inicio, int info);        //
int Inserir_fim_LD(Tno_ld **p_inicio, int info);           //
int Inserir_meio_LD(Tno_ld **p_inicio, int info, int pos); //-
int Remover_inicio_LD(Tno_ld **p_inicio);                  //
int Remover_meio_LD(Tno_ld **p_inicio, int pos);           //-
int Remover_fim_LD(Tno_ld **p_inicio);                     //-
int Listar_LD(Tno_ld *c_inicio);                           //
int Listar_Invertido_LD(Tno_ld *c_inicio);                 //-
int Obter_Tamanho_LD(Tno_ld *c_inicio, int *tam);          //-
int Obter_pos_LD(Tno_ld *c_inicio, int dado, int *pos);    //-
int Inverter_LD(Tno_ld **p_inicio);                        //

/* ----------------------------------------------------------------------------
Fun��es de apoio
-----------------------------------------------------------------------------*/

// Gerador aleatorio de dados
int gera_dado(int min, int max) {
  int k;
  double d;
  d = (double)rand() / ((double)RAND_MAX + 1);
  k = d * (max - min + 1);
  return min + k;
}

/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void) {
  int min, max, i;
  clock_t t_ini, t_fim;
  int info, pos;
  int erro; /* valor de erro retornado pelas funcoes */
  Tno_ld *ini;
  int q; /* receber a opcao do usuario */
  erro = Inicializar_LD(&ini);
  do {
    system("cls");
    printf("LISTA ENCADEADA DUPLA - LED");
    printf("\n\nOpcoes: \n\n");
    printf("1 -> Inserir no inicio \n");
    printf("2 -> Inserir no final\n");
    printf("3 -> Remover no inicio\n");
    printf("4 -> Mostrar toda a lista \n");
    printf("5 -> Inicializar a lista (versao 2)\n");
    printf("6 -> Inverter a lista\n");
    printf("7 -> Remover no meio\n");
    printf("8 -> Remover no final\n");
    printf("9 -> Sair\n");
    printf("10 -> Mostrar toda a lista invertida\n");
    printf("11-> Inserir muitos dados\n");
    printf("12 -> Obter tamanho\n");
    printf("13 -> Obter posicao\n");
    printf("14 -> Inserir no meio\n");
    printf("\n:");
    scanf("%d", &q); /* Ler a opcao do usuario */
    switch (q) {
    case 1:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);
      erro = Inserir_inicio_LD(&ini, info);
      if (erro == 0)
        printf("Insercao realizada com sucesso\n");
      system("pause");
      break;
    case 2:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);
      Inserir_fim_LD(&ini, info);
      break;
    case 3:
      erro = Remover_inicio_LD(&ini);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel remover");
      }
      system("pause");
      break;
    case 4:
      erro = Listar_LD(ini);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel listar");
      }
      system("pause");
      break;
    case 5:
      erro = Inicializar2_LD(&ini);
      printf("\nInicializacao realizada com sucesso !\n");
      printf("\nLISTA VAZIA !\n");
      system("pause");
      break;
    case 6:
      erro = Inverter_LD(&ini);
      printf("\nInversao realizada !\n");
      system("pause");
      break;
    case 7:
      printf("Posicao para remocao na lista: ");
      scanf("%d", &pos);
      erro = Remover_meio_LD(&ini, pos);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel remover\n");
      } else if (erro == 2) {
        printf("\nPosicao invalida para remocao\n");
      } else if (erro == 3) {
        printf("\nPosicao maior que o tamanho da lsita\n");
      }
      system("pause");
      break;
    case 8:
      erro = Remover_fim_LD(&ini);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel remover\n");
      }
      system("pause");
      break;
    case 10:
      erro = Listar_Invertido_LD(ini);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel listar");
      }
      system("pause");
      break;
    case 11:
      min = 1;
      max = 100;
      t_ini = clock();
      for (i = 1; i <= 100000; i++) {
        // info = gera_dado(min, max);
        Inserir_inicio_LD(&ini, i);
        if ((i % 1000) == 0) {

          t_fim = clock() - t_ini;
          printf("Tempo de execucao: %0.3lf\n",
                 ((double)t_fim) / ((CLOCKS_PER_SEC / 1000)));
        }
      }
      system("pause");
      break;
    case 12:
      Obter_Tamanho_LD(ini, &info);
      printf("\nA lista possui tamanho: %d\n", info);
      system("pause");
      break;
    case 13:
      printf("Dado para procurar na lista: ");
      scanf("%d", &info);
      Obter_pos_LD(ini, info, &pos);
      if (erro == 0) {
        printf("\nA posicao do dado na lista eh: %d\n", pos);
      } else if (erro == 1) {
        printf("\nO dado nao esta presente na lista\n");
      }
      system("pause");
      break;
    case 14:
      printf("Posicao para insercao na lista: ");
      scanf("%d", &pos);
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);
      erro = Inserir_meio_LD(&ini, info, pos);
      if (erro == 1) {
        printf("\nPosicao invalida para insercao\n");
      } else if (erro == 2) {
        printf("\nPosicao maior que o tamanho da lsita\n");
      } else {
        printf("\nInsercao realizada com sucesso\n");
      }
      system("pause");
      break;
    case 9:
      break;
    default:
      printf("\n\n Opcao nao valida");
    }
    getchar(); /* Limpa o buffer de entrada */
  } while ((q != 9));
}

/* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LD(Tno_ld *c_inicio) {
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
} /* Fim da fun��o de MOSTRAR */

/* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada na ordem inversa
--------------------------------------------------------------------------------------*/
int Listar_Invertido_LD(Tno_ld *c_inicio) {
  int i;
  if (c_inicio == NULL) {
    return 1; /* lista vazia */
  }
  printf("LISTA ::  ");

  while (c_inicio->prox != NULL) // ir ate a ultima posicao
  {
    c_inicio = c_inicio->prox;
  }

  while (c_inicio != NULL) // ir alem da primeira posicao imprimindo
  {
    printf("%d  ", c_inicio->dado);
    c_inicio = c_inicio->ant;
  }
  printf("\n");
  return 0; /* sem erro */
} /* Fim da fun��o de MOSTRAR */

/* ------------------------------------------------------------------------------------
INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LD(Tno_ld **p_inicio) {
  *p_inicio = NULL;
  return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */

// =================================================
int Inicializar2_LD(Tno_ld **p_inicio) {
  Tno_ld *percorre, *aux;
  if (*p_inicio != NULL) {
    percorre = *p_inicio;
    while (percorre != NULL) {
      aux = percorre;
      percorre = percorre->prox;
      free(aux);
    }
    *p_inicio = NULL;
    return 1; // inicializa apagando tudo da listsa
  } else {
    Inicializar_LD(p_inicio); // inicializa
    return 0;
  }
}

// =================================================
int Obter_Tamanho_LD(Tno_ld *c_inicio, int *tam) {
  Tno_ld *percorre;
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

/* -------------------------------------------------------------------------------------
INSER��O
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LD(Tno_ld **p_inicio, int info) {
  Tno_ld *no_novo;

  /* Criacao do novo no - Aloca��o de memoria */
  no_novo = (Tno_ld *)malloc(sizeof(Tno_ld));
  no_novo->dado = info;

  if (*p_inicio == NULL) { // insercao em lista vazia
    no_novo->prox = NULL;
    *p_inicio = no_novo;
    no_novo->ant = NULL;
  } else { // insercao em lista nao vazia
    no_novo->prox = *p_inicio;
    no_novo->ant = NULL;
    (*p_inicio)->ant = no_novo; // anterior do 1o. aponta para o novo
    *p_inicio = no_novo;        // atualizo o 1o., que passa a ser o novo
  }
  return 0;
}

// ------------------------------------------------------------------
int Inserir_meio_LD(Tno_ld **p_inicio, int info, int pos) {
  int tam;
  Tno_ld *no_novo, *percorre;

  // Tratamento de erros =======================================
  if (pos <= 0)
    return 1; // posicao invalida para insercao

  Obter_Tamanho_LD(*p_inicio, &tam);
  if (pos > tam + 1)
    return 2; // posicao invalida. Acima do tamanho da lista
  // ===========================================================

  // Alocacao do novo no
  no_novo = (Tno_ld *)malloc(sizeof(Tno_ld));
  no_novo->dado = info;

  // procura pela posicao de insercao
  if (pos == 1) { // insercao no inicio
    Inserir_inicio_LD(p_inicio, info);
  } else {
    if (pos == tam + 1) {
      Inserir_fim_LD(p_inicio, info);
    } else {
      int pos_aux = 1;
      percorre = *p_inicio;
      while (pos_aux != pos - 1) // parar uma posicao antes
      {
        percorre = percorre->prox;
        pos_aux++;
      }
      no_novo->prox = percorre->prox; // D
      percorre->prox = no_novo;       // B
      no_novo->ant = percorre;        // A
      (no_novo->prox)->ant = no_novo; // C
    }
  }
  return 0;
}

/* ---------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------*/
int Inserir_fim_LD(Tno_ld **p_inicio, int info) {
  Tno_ld *no_novo, *percorre;

  /* Criacao do novo no - Aloca��o de memoria */
  no_novo = (Tno_ld *)malloc(sizeof(Tno_ld));
  no_novo->dado = info;
  no_novo->prox = NULL;
  if (*p_inicio == NULL) { // lista vazia.
    *p_inicio = no_novo;
    no_novo->ant = NULL;
  } else { // lista nao vazia
    percorre = *p_inicio;
    while (percorre->prox != NULL) // ate o ultimo
    {
      percorre = percorre->prox;
    }
    percorre->prox = no_novo; // liga��o do ultimo com o novo
    no_novo->ant = percorre;  // liga o novo ultimo ao anterior
  }
  return 0;
}

int Obter_pos_LD(Tno_ld *c_inicio, int valor, int *pos) {
  *pos = 0;
  while (c_inicio != NULL) {
    (*pos)++;
    if (valor == c_inicio->dado)
      return 0; // dado encontrado
    c_inicio = c_inicio->prox;
  }

  return 1; // dado nao encontrado
}

// =================================================

/* -------------------------------------------------------------------------
REMOCAO
-------------------------------------------------------------------------*/
int Remover_inicio_LD(Tno_ld **p_inicio) {
  Tno_ld *aux;
  if (*p_inicio == NULL) {
    printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
    return 1; /* lista vazia, impossivel remover primeiro */
  } else {
    aux = *p_inicio;
    *p_inicio = (*p_inicio)->prox;
    (*p_inicio)->ant = NULL;
    free(aux);
    return 0;
  }
}

int Remover_meio_LD(Tno_ld **p_inicio, int pos) {
  Tno_ld *percorre;
  int pos_aux;
  int tam;
  // Tratamento de erros =======================================
  if (*p_inicio == NULL) {
    printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
    return 1; // lista vazia, impossivel remover primeiro
  }
  if (pos <= 0)
    return 2; // posicao invalida para remocao
  Obter_Tamanho_LD(*p_inicio, &tam);
  if (pos > tam)
    return 3; // posicao invalida. Acima do tamanho da lista
  // ===========================================================
  percorre = *p_inicio;
  pos_aux = 1;
  while (pos_aux != pos) // encontrar o no para remocao
  {
    percorre = percorre->prox;
    pos_aux++;
  }
  // ligar o vizinho anterior com o vizinho proximo
  (percorre->ant)->prox = percorre->prox;
  // ligar o vizinho proximo com o vizinho anterior
  (percorre->prox)->ant = percorre->ant;

  free(percorre);
}

int Remover_fim_LD(Tno_ld **p_inicio) {
  Tno_ld *percorre, *penultimo;

  if (*p_inicio == NULL)
    return 1; // lista vazia

  percorre = *p_inicio;
  if (percorre->prox == NULL) // Lista com 1 elemento
  {
    free(percorre);
    *p_inicio = NULL;
  }

  while (percorre->prox != NULL) // navegar at� o �ltimo
  {
    percorre = percorre->prox;
  }
  penultimo = percorre->ant;
  free(percorre);         // liberando o �ltimo
  penultimo->prox = NULL; // no penultimo indicando fim de lista
  return 0;
}

/* -------------------------------------------------------------------------
INVERTER LISTA
-------------------------------------------------------------------------*/
int Inverter_LD(Tno_ld **p_inicio) {
  Tno_ld *percorre, *aux1, *aux2;
  percorre = *p_inicio;
  if (percorre == NULL) {
    return 1; // Caso a lista esteja vazia.
  } else if (percorre->prox == NULL) {
    return 0; // Caso a lista tenha apenas um n�.
  } else {
    while (percorre != NULL) // ate o ultimo
    {
      // Troca do ant pelo prox e vice-versa em cada no
      aux1 = percorre->prox;
      percorre->prox = percorre->ant;
      percorre->ant = aux1;

      if (aux1 == NULL)       // o percorre esta no ultimo no
        *p_inicio = percorre; // define novo inicio
      // Avan�ar para o proximo no de inversao
      percorre = percorre->ant;
    }
  }
  return 0;
}

//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//---------------------------------------------------------------------------

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES - Com Descritor
------------------------------------------------------------------------------*/

typedef struct no_ls {
  int dado;
  struct no_ls *prox;
} Tno_ls;

typedef struct descritor_ls {
  int tam;
  struct no_ls *prim;
  struct no_ls *ult;
} Tdescritorno_ls;

// Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS(Tdescritorno_ls *pdesc);
int Inicializar2_LS(Tdescritorno_ls *pdesc);
int Inserir_inicio_LS(Tdescritorno_ls *pdesc, int info);
int Inserir_fim_LS(Tdescritorno_ls *pdesc, int info);
int Inserir_meio_LS(Tdescritorno_ls *pdesc, int info, int pos);
int Remover_inicio_LS(Tdescritorno_ls *pdesc);
int Remover_meio_LS(Tdescritorno_ls *pdesc, int pos);
int Remover_fim_LS(Tdescritorno_ls *pdesc);
int Listar_LS(Tdescritorno_ls cdesc);
int Obter_dado_LS(Tdescritorno_ls cdesc, int pos, int *dado);
int Obter_pos_LS(Tdescritorno_ls cdesc, int dado, int *pos);
int Obter_Tamanho_LS(Tdescritorno_ls cdesc, int *tam);
int Copia_lista(Tdescritorno_ls *l1, Tdescritorno_ls *l2);

/* Variaveis global */

/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void) {

  int info;
  int erro; /* valor de erro retornado pelas funcoes */
  Tdescritorno_ls desc;
  int q; /* receber a opcao do usuario */
  erro = Inicializar_LS(&desc);
  do {
    system("cls");
    printf("1 -> Inserir no inicio\n");
    printf("2 -> Inserir no final\n");
    printf("3 -> Remover no inicio\n");
    printf("4 -> Mostrar toda a lista \n");
    printf("5 -> Inicializar a lista (versao 2)\n");
    printf("6 -> Sair \n");
    printf("7 -> Copiar Lista\n");
    printf("8 -> Inserir no meio\n");
    printf(":");
    scanf("%d", &q); /* Ler a opcao do usuario */
    switch (q) {
    case 1:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);
      erro = Inserir_inicio_LS(&desc, info);
      if (erro == 0)
        printf("Insercao realizada com sucesso\n");
      system("pause");
      break;
    case 2:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);
      Inserir_fim_LS(&desc, info);
      if (erro == 0)
        printf("Insercao realizada com sucesso\n");
      system("pause");
      break;
    case 3:
      erro = Remover_inicio_LS(&desc);
      if (erro == 0) {
        printf("Remocao realizada com sucesso \n");
      } else if (erro == 1) {
        printf("\nLista vazia. Impossivel remover\n");
      }
      system("pause");
      break;
    case 4:
      erro = Listar_LS(desc);
      if (erro == 1) {
        printf("\nLista vazia. Impossivel listar\n");
      }
      system("pause");
      break;
    case 5: erro=Inicializar2_LS (&desc);
      printf("\nInicializacao realizada com sucesso !\n");
      printf("\nLISTA VAZIA !\n");
      system("pause");
      break;
    case 6:
      break;
    case 7:
      //   erro = Copia_lista(&desc);
      break;
    case 8:
      printf("Dado para insercao na lista: ");
      scanf("%d", &info);

      int pos;
      printf("Posicao para insercao na lista: ");
      scanf("%d", &pos);

      erro = Inserir_meio_LS(&desc, info, pos);

      if (erro == 0)
        printf("Insercao realizada com sucesso! \n");
      else if (erro == 1)
        printf("Lista vazia !\n");
      else if (erro == 2)
        printf("A posicao solicitada e maior que o tamanho da lista !\n");

      system("pause");
      break;
    default:
      printf("\n\n Opcao nao valida");
    }
    getchar(); /* Limpa o buffer de entrada */
  } while ((q != 6));
}

int Inicializar_LS(Tdescritorno_ls *pdesc) {
  pdesc->prim = NULL;
  pdesc->ult = NULL;
  pdesc->tam = 0;
}

int Inicializar2_LS(Tdescritorno_ls *pdesc) {
  if(pdesc == NULL) return 1;
  
  Tno_ls *aux = pdesc->prim;
  if(aux == NULL) return 0;

  while(aux->prox != NULL) {
    Remover_inicio_LS(pdesc);
    aux = aux->prox;
  }
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

// int Copia_lista(Tdescritorno_ls *l1, Tdescritorno_ls *l2) {
//   Tno_ls *aux;
//   aux = l1->prim;
// }

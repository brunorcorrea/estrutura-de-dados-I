#if !defined(LES_DESCRITOR_H)
#define LES_DESCRITOR_H

typedef struct no_ls {
  int dado;
  struct no_ls *prox;
} Tno_ls;

typedef struct descritor_ls {
  int tam;
  struct no_ls *prim;
  struct no_ls *ult;
} Tdescritorno_ls;

void clearConsole();
void awaitUserInput();

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

#endif // LES_DESCRITOR_H

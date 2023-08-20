#if !defined(LES_METHODS_H)
#define LES_METHODS_H

struct no_ls {
  int dado;
  struct no_ls *prox;
};

typedef struct no_ls Tno_ls;

int initializeEmptyList(Tno_ls **p_inicio);
int cleanAllListNodes(Tno_ls **p_inicio);
int insertNodeInListStart(Tno_ls **p_inicio, int info);
int insertNodeInListEnd(Tno_ls **p_inicio, int info);
int Inserir_meio_LS(Tno_ls **p_inicio, int info, int pos);
int Remover_inicio_LS(Tno_ls **p_inicio);
int Remover_meio_LS(Tno_ls **p_inicio, int pos);
int Remover_fim_LS(Tno_ls **p_inicio);
int Listar_LS(Tno_ls *c_inicio);
int Obter_pos_LS(Tno_ls *c_inicio, int dado, int *pos);
int Obter_Tamanho_LS(Tno_ls *c_inicio, int *tam);
int Inverter_LS(Tno_ls **p_inicio);
int Inverter_LS_2(Tno_ls **p_inicio);
int Ver_Repete_Dado_LS(Tno_ls *c_inicio, int info, int *resp);
int Maiorque_Dado_LS(Tno_ls *c_inicio, int info, int *quant);

#endif // LES_METHODS_H

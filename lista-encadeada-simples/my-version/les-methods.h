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
int insertNodeInListGivenPosition(Tno_ls **p_inicio, int info, int pos);

int removeNodeInListStart(Tno_ls **p_inicio);
int removeNodeInListEnd(Tno_ls **p_inicio);
int removeNodeInListGivenPosition(Tno_ls **p_inicio, int pos);

int getAllListNodes(Tno_ls *c_inicio);

int getGivenValuePosition(Tno_ls *c_inicio, int dado, int *pos);
int getListSize(Tno_ls *c_inicio, int *tam);

int invertList(Tno_ls **p_inicio);
int invertList_2(Tno_ls **p_inicio);

int VerifyRepeatedValueInList(Tno_ls *c_inicio, int info, int *resp);

int countElementsAboveValue(Tno_ls *c_inicio, int info, int *quant);

#endif // LES_METHODS_H

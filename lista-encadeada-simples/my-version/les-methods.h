#if !defined(LES_METHODS_H)
#define LES_METHODS_H

struct listNode {
  int dado;
  struct listNode *prox;
};

typedef struct listNode ListNode;

int initializeEmptyList(ListNode **p_inicio);
int cleanAllListNodes(ListNode **p_inicio);

int insertNodeInListStart(ListNode **p_inicio, int info);
int insertNodeInListEnd(ListNode **p_inicio, int info);
int insertNodeInListGivenPosition(ListNode **p_inicio, int info, int pos);

int removeNodeInListStart(ListNode **p_inicio);
int removeNodeInListEnd(ListNode **p_inicio);
int removeNodeInListGivenPosition(ListNode **p_inicio, int pos);

int getAllListNodes(ListNode *c_inicio);

int getGivenValuePosition(ListNode *c_inicio, int dado, int *pos);
int getListSize(ListNode *c_inicio, int *tam);

int invertList(ListNode **p_inicio);
int invertList_2(ListNode **p_inicio);

int VerifyRepeatedValueInList(ListNode *c_inicio, int info, int *resp);

int countElementsAboveValue(ListNode *c_inicio, int info, int *quant);

#endif // LES_METHODS_H

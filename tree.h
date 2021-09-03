#ifndef _ARVORE_H_
#define _ARVORE_H_
#include "treeNode.h"

typedef struct {
  PNODE raiz;
} TREE;

TREE* construtorTree();

void addValueInTree();

#endif
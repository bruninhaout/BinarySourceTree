#include <stdio.h>
#include <malloc.h>
#include "treeNode.h"
#include "tree.h"


int main() {
  TREE* arvore1 = construtorTree();

 addValueInTree(arvore1, 15);
 addValueInTree(arvore1, 11);
 addValueInTree(arvore1, 18);

 printf("ARVOREZINHA :3 \n"); 
 imprimirTreeNode(arvore1->raiz);
 printf("\n");

 printf("NUMBER De NOS: %d", contarTreeNode(arvore1->raiz));

 PNODE noProcurado = searchTreeNode(arvore1->raiz, 21);
 if (noProcurado != NULL)
    printf("O NUMERO IS: %d \n", noProcurado->valor);
  return 0;
}


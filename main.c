#include <stdio.h>
#include <malloc.h>
#include "treeNode.h"
#include "tree.h"


int main() {
  TREE* arvore1 = construtorTree();

 addValueInTree(arvore1, 15);
 addValueInTree(arvore1, 11);
 addValueInTree(arvore1, 18);
 addValueInTree(arvore1, 4);
 addValueInTree(arvore1, 8);
 addValueInTree(arvore1, 1);
 addValueInTree(arvore1, 7);

 printf("ARVOREZINHA :3 \n"); 
 imprimirTreeNode(arvore1->raiz);
 printf("\n");

 printf("ARVOREZINHA MAS EXCLUINDO A GALERA :3 \n"); 
 arvore1->raiz = removeTreeNode(arvore1->raiz, 8);
 imprimirTreeNode(arvore1->raiz);
 printf("\n");

 printf("NUMBER De NOS: %d\n", contarTreeNode(arvore1->raiz));

 PNODE noProcurado = searchTreeNode(arvore1->raiz, 18);
 if (noProcurado != NULL)
    printf("O NUMERO IS: %d \n", noProcurado->valor);
  return 0;
}


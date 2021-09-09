#include <stdio.h>
#include <malloc.h>
#include "tree.h"
#include "treeNode.h"


TREE* construtorTree(){
  TREE* newTree = (TREE*) malloc(sizeof(TREE));
  newTree->raiz = NULL;

  return newTree;
}
void addValueInTree(TREE* tree, int valor){
  PNODE nodo = constructTreeNode(valor);
  tree->raiz = addTreeNode(tree->raiz, nodo);
}
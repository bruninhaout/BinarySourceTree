#include <stdio.h>
#include <malloc.h>
#include "tree.h"


TREE* construtorTree(){
  TREE tree;
  tree.raiz = NULL;
  
  return tree;

  TREE* newTree = (TREE*) malloc(sizeof(TREE));
  (*newTree).raiz = NULL;

  return newTree;
}
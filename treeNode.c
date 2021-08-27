#include <stdio.h>
#include <malloc.h>
#include "treeNode.h"

//Construtor
PNODE constructTreeNode(int valor){
  PNODE newNode =(PNODE) malloc(sizeof(TREENODE));
  
  newNode->valor = valor;
  newNode->esquerda = NULL;
  newNode->direita = NULL;

  return newNode;
}
//Adicionar nó
//Endereço de u nó -> PNODE
PNODE addTreeNode(PNODE raiz, PNODE newNode){
  if(raiz == NULL) return newNode;
  //validar se eh maior ou menor
  if(newNode->valor < raiz->valor){
    raiz->esquerda = addTreeNode(raiz->esquerda, newNode);
  } else {
    raiz->direita = addTreeNode(raiz->direita, newNode);
  }
  return raiz;
}
//Contador de nó
int contarTreeNode(PNODE raiz){

return 0;
}
//Imprimi-dor de nó 
void imprimirTreeNode(PNODE raiz){

}
//procurador de nó
PNODE searchTreeNode(PNODE raiz, int search){
return NULL;
}
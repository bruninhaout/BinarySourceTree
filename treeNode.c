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
  if(raiz == NULL) return 0;
      return 0;

  return 1 + contarTreeNode(raiz->esquerda) + contarTreeNode(raiz->direita);
}
//Imprimi-dor de nó 
void imprimirTreeNode(PNODE raiz){
  if(raiz != NULL){
    printf("%d", raiz->valor);
    printf("(");
    imprimirTreeNode(raiz->esquerda);
    imprimirTreeNode(raiz->direita);
    printf(")");
  }

}
//procurador de nó
PNODE searchTreeNode(PNODE raiz, int search){
    if(raiz==NULL) return NULL;
    if(raiz->valor == search) return raiz;

    if (raiz->valor < raiz->valor)
      return searchTreeNode(raiz->esquerda, search);

    return searchTreeNode(raiz->direita, search);


}
/*

    typedef int* PONT
    int valor =8;
    int* pValor = &valor; (PONT pValor = &valor;)

    PONT* ppValor;

    *pValor = 9;
    */


#include <stdio.h>
#include <malloc.h>
#include "treeNode.h"

// Funções "Privadas"

PNODE _procurarComDaddy(PNODE raiz, int valor, PNODE* daddy){
  PNODE aux = raiz;
  *daddy = NULL;

  while(aux != NULL){
      if(valor == aux->valor) return aux;
      *daddy = aux;

      //COND ? TRUE : FALSE;
      aux = valor < aux->valor ? aux->esquerda : aux->direita;
  }

    return NULL;
}

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
  
  //PRE ORDER
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

PNODE removeTreeNode(PNODE raiz, int valor){
    PNODE daddy, mano;
    int ehDeEsquerda = 0;

    if(raiz == NULL) return NULL;
    mano = _procurarComDaddy(raiz, valor, &daddy);

    ehDeEsquerda = mano->valor < daddy->valor ? 1 : 0;

    // Sem criança
    if(mano->direita == NULL && mano->esquerda == NULL){
      if(daddy != NULL){
        if(ehDeEsquerda == 1) daddy->esquerda = NULL;
        else daddy->direita = NULL;
      }

        free(mano);

        return daddy !=NULL ? raiz : NULL;
    }

    // 1 criança na direita
    if (mano->direita != NULL && mano->esquerda == NULL){
      if (daddy != NULL){
          if (ehDeEsquerda == 1 ) 
            daddy->esquerda = mano->direita;
          else 
            daddy->direita = mano->direita;
      } else {
          raiz = mano->direita;
      }

      free(mano);
      return raiz;
    }

    // 1 nene na esquerda
    if (mano->esquerda != NULL && mano->direita == NULL){
      if (daddy != NULL){
          if (ehDeEsquerda == 1 ) 
            daddy->esquerda = mano->esquerda;
          else 
            daddy->direita = mano->esquerda;
      } else {
          raiz = mano->esquerda;
      }

      free(mano);
      return raiz;
    }

    // 2 aborrecente
    PNODE promovido = mano->esquerda;
    PNODE daddyPromovido = mano;

    while (promovido->direita == NULL){
        daddyPromovido = promovido;
        promovido = promovido->direita;
    }

    if (daddyPromovido != mano){
        daddyPromovido->direita = promovido->esquerda;
        promovido->esquerda = mano->esquerda;
    }

    promovido->direita = mano->direita;

    if (daddy != NULL){
      if (ehDeEsquerda == 1 ) 
          daddy->esquerda = promovido;
      else 
          daddy->direita = promovido;
    } else {
      raiz = promovido;
    }

    free(mano);
    return raiz;
}
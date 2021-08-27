#ifndef _TREE_NODE_
#define _TREE_NODE_

typedef struct treeNode{
    int valor;
    struct treeNode* esquerda;
    struct treeNode* direita;
}TREENODE;

typedef TREENODE* PNODE;
/*PNODE = Ponteiro de Tree Node*/
PNODE constructTreeNode(int valor);
PNODE addTreeNode(PNODE raiz, PNODE newNode);
int contarTreeNode(PNODE raiz);
void imprimirTreeNode(PNODE raiz);
PNODE searchTreeNode(PNODE raiz, int search);

#endif
#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

Bst* factoryBst(int data){ // or factory node
    Bst* bst = (Bst*)malloc(sizeof(Bst));
    bst->data = data;
    bst->right = 0;
    bst->left = 0;
    return bst;
}

void getInOrden(Bst* n){
    if(n->left) getInOrden(n->left);
    printf("%d ", n->data);
    if(n->right) getInOrden(n->right);
}

void inOrden(Bst* bst){
    getInOrden(bst);
    printf("\n");
}

void basicInsertion(Bst* bst, int data){ // obligatoria sin sentencia
    // here goes your code
}

void advancedInsertion(Bst* bst, int data){ // solo para pros
    // here goes your code
}

int searchValue(Bst* bst, int data){ // obligatoria con sentencia
    // here goes your code
}

int searchPosition(Bst* n, int k){ // solo para viciosos
    // here goes your code
}
#endif

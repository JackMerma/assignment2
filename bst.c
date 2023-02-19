#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

#define PRINT_ERROR(value) printf("\nValue %d is already in Bst\n", value), exit(1)

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

void basicInsertion(Bst* bst, int data){
    if(bst->data == data) PRINT_ERROR(data);
    Bst* pre = bst; // el anterior
    Bst* actual = (bst->data > data)? bst->left : bst->right; // el actual

    while(actual){ // siempre que el actual exista
        if(actual->data == data) PRINT_ERROR(data);
        pre = actual; // el anterior sera el actual
        actual = (actual->data > data)? actual->left : actual->right; // el actual será el que debe continuar
    }

    // el ultimo nodo (hoja) se guarda en 'pre'
    if(pre->data > data) // insertar a la derecha o izquierda
        pre->left = factoryBst(data);
    else 
        pre->right = factoryBst(data);
}

void advancedInsertion(Bst* bst, int data){
    Bst** iter = &(bst); // direccion de memoria de root

    while(*iter){ // siempre que lo que guarda el puntero (Bst*) exista
        if((*iter)->data == data) PRINT_ERROR(data); // mismo valor
        iter = ((*iter)->data > data)? &((*iter)->left) : &((*iter)->right); // direccion de memoria del siguiente
    }

    *iter = factoryBst(data); // se crea un nodo en la direccion de memoria que se guarda
}

int searchValue(Bst* bst, int data){
    Bst* iter = bst; // iterador

    while(iter){ // siempre que exista el nodo
        if(iter->data == data) // se encontró
            return 1;
        iter = (iter->data > data)? iter->left : iter->right; // se sigue recorriendo
    }
    return 0;
}

int countChild(Bst* n){
    if(!n) return 0; // el nodo no existe
    int count = 1; // conteno del nodo actual
    count += countChild(n->left); // conteo por la izquierda
    count += countChild(n->right); // conteo por la derecha
    return count; // retorna conteo
}

int searchPosition(Bst* n, int k){
    // Hint: La posición de un dato en in-orden (de 0 a n-1), esta dada por la cantidad de nodos en el sub-arbol izquiero de un nodo actual
    
    int pos = countChild(n->left); // se cuenta los hijos del sub-arbol izquierdo
    if(pos > k) // busqueda por la izquierda
        return searchPosition(n->left, k); // k no cambia
    else if(pos < k) // busqueda por la derecha
        return searchPosition(n->right, k - pos - 1); // k cambia
    return n->data; // la cantidad es igual a la posicion buscada
}
#endif

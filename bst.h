#ifndef STRUCTURES_H
#define STRUCTURES_H

// struct node
//      Este struct, va a simular la implementacion de una clase Node
//      donde tendrá como atributos:
//      + data: Valor de tipo 'entero', donde se almacenará un valor
//      + right: Valor de tipo 'puntero' a un 'struct node', donde se
//               almacenará la dirección de memoria del subarbol derecho
//      + left: Valor de tipo 'puntero' a un 'struct node', donde se
//               almacenará la dirección de memoria del subarbol izquierdo
typedef struct node{
    int data;
    struct node* right;
    struct node* left;
}Bst;


// metodo factoryBst
//      Este método actua como un (constructor) en un LP que
//      soporta clases. A este se le pasa un valor inicial al BST
Bst* factoryBst(int);


// metodo getInOrden
//      Llamada recursiva a este mismo metodo para imprimir en orden
//      al BST
void getInOrden(Bst*);


// metodo inOrden
//      Metodo principal para imprimir en orden al BST
void inOrden(Bst*);


// metodo basicInsertion
//      Este realizará una inserción basica (un puntero) en el BST.
//      Se le pasa el puntero del BST que se quiere usar y un valor.
void basicInsertion(Bst*, int);


// metodo advancedInsertion
//      Este realizará una inserción avanzada (doble puntero) en el BST.
//      Se le pasa el puntero del BST que se quiere usar y un valor.
void advancedInsertion(Bst*, int);


// metodo searchValue
//      Se encarga de buscar a un elemento. Devuelve la representacion
//      de True o False mediante un valor numerico
int searchValue(Bst*, int);


// metodo searchPosition
//      Se encarga de buscar a un elemento mediante una posicion,
//      donde esta estará determinada por el mismo orden que 
//      sigue el recorrido in-order
int searchPosition(Bst*, int);

#endif

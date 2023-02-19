#include "bst.c"

int main(){
    Bst* bst;
    bst = factoryBst(17);
    basicInsertion(bst, 30);
    basicInsertion(bst, 10);
    basicInsertion(bst, 15);
    advancedInsertion(bst, -1);
    advancedInsertion(bst, 0);
    advancedInsertion(bst, 19);
    basicInsertion(bst, 5);
    advancedInsertion(bst, 101);
    inOrden(bst);

    for(int i=0;i<9;i++){
        printf("posicion %d: %d\n", i, searchPosition(bst, i));
    }

    advancedInsertion(bst, 5); // repetido

    return 0;
}

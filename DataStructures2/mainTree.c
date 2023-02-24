#include "tree.h"



int main(){
    Node* n7 = createTree(70,NULL,NULL);
    Node* n6 = createTree(60,NULL,NULL);
    Node* n5 = createTree(50,NULL,NULL);
    Node* n4 = createTree(40,n7,NULL);
    Node* n3 = createTree(30,n6,NULL);
    Node* n2 = createTree(20,n4,n5);
    Node* n1 = createTree(10, n2, n3);
    unsigned int k = 0;
    unsigned int treeHeight = 2^k;
    // breathSearch(n1,4);
    // print2(n1,0);
    unsigned int levels = 4;
    // completePrinting(n1, levels);
    preOrderVisit(n1,4);
    // preOrderVisitBinaryPrint(n1,4,0);
    printf("%i",elemCompare(8,8));
    deleteTree(n1);

}
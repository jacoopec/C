#include "CHeaders.h"

int g;

typedef struct Node{
    Node* next;
    int val;
}Node;
//   a = 5   int
//  pa = &a  int*
//  pp = &pa
int main(){
    int y = 3;      //vale 3
    int* p1 = &y;   //punta ad un intero che vale 3
    int* p2 = p1;   //punta ad un intero che vale 3
    int** pp = &p1;
    printf("size of **: %lu, *: %lu, %lu\n", sizeof(pp), sizeof(p1),sizeof(int));
    // printf("pp: %p, p: %p", pp, p);
    //-----------------------
    int *b, *c, *d, *e;
    //l'asterisco è legato al nome della variabile, non al tipo, infatti
    // b,c,d,e sono di tipo int *, mentre f è di tipo int.
    int array[4] = {1,2,3,4};
    //*b = array[0]  questo non si può fare
    b = array;
    c = array+1;
    d = array+2;
    e = array+3;
    *b = 9;     //questo si perchè al puntatore è già stata assegnata una variabile int a cui puntare.
    
    int* DPList[4] = {b,c,d,e};
    for(int i = 0; i < 4; i++){
        printf("%i\n",*(DPList[i]));
    }

    // printf("indirizzo **pp: %p, indirizzo *p1: %p, indirizzo *p2: %p\n", pp, p1, p2);
}
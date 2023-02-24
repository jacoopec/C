#include "../CHeaders.h"

typedef elemType int;

typedef struct node{
    elemType val;
    struct node* next;
} node;

int* elementCompare(const node* n1, const int* n2){
    return((*n1 > *n2) - (*n1 < *n2));
}

int elemRead(FILE* f, node* n){
    return fscanf(f, "%d", e);
}

int elemReadStdIn(node* n){
    return elemRead(stdin, n);
}

void elemWrite(const node* n, FILE* f){
    printf("%d", *n);
}

void elemWriteStdOut(const node* n){
    elemWrite(n, stdout);
}

node nodeCopy(const node* n1){
    return (*n1);
}
node* listCreateEmpty(void);
node* listInsertHead(const node* n, node* n2);
const node* listGetHeadValue(node* n);
node* listGetTail(const node* n1){
    if(listIsEmpty){
        printf("Error");
        exit(2);
    } else { return n1->next;}
}

node* listInsertBack(node* n1, const elemType* v){
    node* n2 = listInsertHead(v, listCreateEmpty());
    if(listIsEmpty(n1)){ return n2;}
    node* tmp = n1;
    while(!listIsEmpty(listGetTail(tmp))){
        tmp = listGetTail(tmp);
    }
    tmp -> next = n2;
    return n1;
}

void listDelete(node* n1){
    while(!listIsEmpty(n1)){
        node* tmp = n1;
        n1 = n1->next;
        elemDelete(&tmp->val);
        free(tmp);
    }
}

bool listIsEmpty(const node* n1){
    return n1 == NULL;
}

void listWrite(const node* n1, FILE* f){
    printf("[");
    while(!listIsEmpty(n1)){
        elemWrite(&n1->val, f);
        n1 = listGetTail(n1);
        if(!listIsEmpty(n1)){
            printf(", ");
        }
        printf("]\n");
    }
}


void listWriteStdOut(const node* n1, FILE* f){
    listWrite(n1, stdout);
}

int main(){
    int y=2;
    int t=2;
    printf("%u, %u, %u", &y, &t, elementCompare(&y, &t));
}
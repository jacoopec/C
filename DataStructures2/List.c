#include "../CHeaders.h"
#include "../myFunctions/myFunctions.h"

typedef int elementType;
typedef struct Node{
    elementType val;
    struct Node *next;
}Node;

Node global = {.next = NULL, .val = 1000};

void Print(Node *e){
    if(e == NULL){
        printf("Error, list is empty.\n");
        exit(1);
    } else {
        // printf("%p  %i ->\t", e, e->val);
        Node *tmp = e;
        while(tmp != NULL){
            printf("%i - %p ->\t",tmp->val,tmp);
            tmp = tmp->next;
        }
        free(tmp);
        printf("END.\n");
        printf("in Print tmp freed %p\n",tmp);
    }
    return;
}

int ElemCompare(const elementType *e1, const elementType *e2){
    if(e1 == NULL || e2 == NULL){
        return INT_MIN;
    }
    if(e1 > e2){
        return 1;
    } else if (e1 == e2){
        return 0;
    } else {
        return -1;
    }
}

elementType ElemCopy(const elementType *e){
    elementType eNew = *e;
    // Print("eNew %p",&eNew);
    return eNew;
}

elementType ElemRead(FILE *f, elementType *e){
    return fscanf(f, "%d",e);
}

elementType ElemReadStdIn(elementType* e){
    return ElemRead(stdin,e);
}

void ElemWrite(const Node *e, FILE *f){
    // Print(e, "e");
}

void ElemWriteStdOut(const Node *e){
    ElemWrite(e, stdout);
}

Node* listCreateEmpty(void){
    // e->val = INT_MAX;
    printf("\t** Created empty list **\n");
    return NULL;
}

bool listIsEmpty(Node* n){
    if(n == NULL){return true;}
    else false;
}

 const elementType *getHeadVal(Node *e){
    if(listIsEmpty(e)){
        printf("List is empty.\n");
        exit(1); 
    } else{
        return ((const elementType)e->val);
    }
}

Node* listInsertHead(elementType e, Node *i){
    Node *newHead = malloc(sizeof(Node));
    newHead->next = i;
    newHead->val = e;
    printf("Inserting element %i at %p new head of the list.\n", newHead->val, newHead);
    return newHead;
}

//usare listgetTail per andare al prossimo elemento senza usare -> next
//usare le primitive rende la lettura più semplice. Nascondere la sintassi a livello più basso.

Node* getTail(const Node *i){
    if(i == NULL){
        return NULL;
    } else{
        return i->next;
    }
}

Node* listInsertBack(const elementType *e, Node *i){
    Node *n; //= listInsertHead(e, listCreateEmpty());

    while(listIsEmpty(i)){
        return n;
    }
    Node *tmp = i;
    while(!listIsEmpty(getTail(tmp))){
        tmp = getTail(tmp);
    }
    tmp->next = n;
    return i;
}

void elemDelete(Node* n){
    free(n);
}

void listDelete(Node *node){
    Node *tmp = node, *del = node;
    while(!listIsEmpty(tmp)){
        del = tmp;
        printf("Deleting node %i, at %p, next is %p.\n", tmp->val, tmp, tmp->next);
        tmp = tmp->next;
        elemDelete(del);
    }
    printf("List deleted.\n");
}

bool isMember(const elementType *e, Node* n){
    if(listIsEmpty(n)){
        return false;
    }
    if(ElemCompare(e, getHeadVal(n)) == 0){
        return true;
    }
    return isMember(e, GetTail(n));
}

int main(){
    int input;
    scanf("%i", &input);
    if(input == 0){
        //CREATING ELEMENTS
        Node *h = listCreateEmpty();
        h = listInsertHead((elementType)2, h);
        printf("h  %p\n",h);
        Print(h);
        h = listInsertHead((elementType)5, h);
        Print(h);
        printf("%i",isMember((const elementType) 2,h));
        listDelete(h);
        //PLAYING WITH MEMORY
    } else if(input == 2){
    } else if(input == 3){

    }
}
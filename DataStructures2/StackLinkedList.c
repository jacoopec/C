#include "../CHeaders.h"

#define STACK_LENGTH 5
#define EMPTY 0
#define STACK_EMPTY INT_MIN

int myStack[STACK_LENGTH];
int top = EMPTY;

typedef struct Node{
    int val;
    struct Node* next; 
} Node;




Node* head = NULL;

int push(myStack* myStack, int value){
    if(myStack->top >= STACK_LENGTH-1) {return false;};
    myStack->top++;
    myStack->values[myStack->top] = value;
    return true;
}

int pop(myStack* myStack){
    if(myStack->top == EMPTY) return STACK_EMPTY;
    int result = myStack->values[myStack->top];
    myStack->top--;
    return result;
}

int main(){
    myStack s1, s2, s3;
    push(&s1,23);
    push(&s1,87);
    push(&s1,34);
    push(&s2,23);
    push(&s2,87);
    push(&s2,34);
    push(&s3,23);
    push(&s3,87);
    push(&s3,34);
    int t;
    while((t = pop(&s2)) != STACK_EMPTY){
        printf("t= %d\n", t);
    }
}
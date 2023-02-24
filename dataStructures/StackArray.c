#include "../CHeaders.h"

#define STACK_LENGTH 5
#define EMPTY -1
#define STACK_EMPTY INT_MIN

int myStack[STACK_LENGTH];
int top = EMPTY;

int push(int value){
    if(top >= STACK_LENGTH-1) return false;
    top++;
    myStack[top] = value;
    return true;
}

int pop(){
    if(top == EMPTY) return STACK_EMPTY;
    int result = myStack[top];
    top--;
    return result;
}

int main(){
    push(38);
    push(78);
    push(278);
    int t;
    while((t = pop()) != STACK_EMPTY){
        printf("t= %d\n", t);
    }
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
int myStack[STACK_LENGTH];
int top = EMPTY;




void push(int val){
    // node* newNode = malloc(sizeof(node));
    if(top >= STACK_LENGTH-1) return;
    top++;
    myStack[top] = val;

    // newNode->value = val;
    // newNode->next = head;
    // head = newNode;
    return;
}

int pop(){
    if(top == EMPTY) return EMPTY;
    int result = myStack[top];
    top--;
    return result;
}

int main(){
    push(34);
    push(73);
    push(235);
    int t;
    while((t = pop()) != EMPTY){
        printf("t:%i\t\n",t);
    }
}
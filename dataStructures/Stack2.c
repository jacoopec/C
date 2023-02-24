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

typedef struct node{
    int value;
    struct node *next;
}node;

typedef node* stack;

void push(stack* myStack, int val){
    node* newNode = malloc(sizeof(node));
    if(newNode == NULL) return;
    
    newNode->value = val;
    newNode->next = *myStack;
    *myStack = newNode;
    // head = newNode;
    return;
}

int pop(stack* myStack){
    if(*myStack == NULL) return EMPTY;
    int result = (*myStack)->value;
    node* tmp = *myStack;
    *myStack = (*myStack)->next;
    free(tmp);
    return result;
}

int main(){
    stack s1 = NULL, s2 = NULL, s3 = NULL;
    push(&s1, 34);
    push(&s2, 73);
    push(&s3, 235);
    int t;
    while((t = pop(&s2)) != EMPTY){
        printf("t:%i\t\n",t);
    }
}
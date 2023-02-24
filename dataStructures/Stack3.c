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

node* head = NULL;


void push( int val){
    node* newNode = malloc(sizeof(node));
    if(newNode == NULL) return;
    
    newNode->value = val;
    newNode->next = head;
    head = newNode;
    return;
}

int pop(){
    if(*myStack == NULL) return EMPTY;
    int result = head->value;
    node* tmp = head;
    head = head->next;
    free(tmp);
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
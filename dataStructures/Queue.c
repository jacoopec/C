#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

#define QUEUE_EMPTY -1

typedef struct node{
    int value;
    struct node *next;
}node;

typedef struct queue{
    node* head;
    node* tail;
}queue;


void init_queue(queue q){
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(queue* Q, int val){
    node* newNode = malloc(sizeof(node));
    newNode->value = val;
    newNode->next = NULL;
    if(Q->tail != NULL){
        Q->tail->next = newNode;
    }
}

int dequeue(queue* Q){
    if(Q->head == NULL) return QUEUE_EMPTY;
    node* tmp = Q->head;
    int result = tmp->value;
    Q->head = Q->head->next;
    if(Q->head == NULL){
        q->tail = NULL;
    }
    free(tmp);
    return result;
}

int main(){ 
    queue q1 = NULL, q2 = NULL, q3 = NULL;
    init_queue(&q1);
    enqueue(&q1, 26);
    enqueue(&q1, 26);
    enqueue(&q1, 35);
    enqueue(&q1, 64);
    enqueue(&q2, 64);
    enqueue(&q2, 64);

}
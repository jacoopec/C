#include "../CHeaders.h"
//Head, in generale, nelle data structure è il punto di partenza. da qui usando next si procede attraverso
//gli  elemetni della lista fino alla tail, che punta a NULL.
//Enqueue avviene vicino alla head, 
typedef struct Node{
    int value;
    struct Node* next;
} Node;

typedef struct{
    Node* head;
    Node* tail;
}queue;

void init_queue(queue* q){
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue* q, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if(q->tail != NULL){
        q->tail->next = newNode;
    }
    if(q->head == NULL){
        q->head = newNode;
    }
}

int dequeue(queue* q){
    if(q->head == NULL) return false;  //can't return anything from an empty queue
    Node* tmp = q->head;
    int result = tmp-> value;
    q->head = q->head->next;
    if(q->head == NULL){
        q->tail = NULL;
    }
    free(tmp);
    return result;
}

int main(){
    queue q1, q2, q3;
    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);

    enqueue(&q1, 48);
    enqueue(&q2, 48);
    enqueue(&q3, 48);
    enqueue(&q2, 48);

}

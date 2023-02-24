#include "../cheaders.h"
#define QUEUE_EMPTY -1



typedef struct queue{
    int* values;
    int head, tail, numEntries, size;
} queue;


void init_queue(queue* q, int maxSize){
    q->size = maxSize;
    q->values = malloc(sizeof(int)* q->size);
    q->numEntries = 0;
    q->head = 0;
    q->tail = 0;
}

bool queueEmpty(queue* q){
    return(q->numEntries == 0);
}

bool queueFull(queue* q){

}

void queueDestroy(queue* q){
    return
}


void enqueue(queue* q, int val){
    if(queueFull(q)){
        return false;
    }
    q->values[q->tail] = val;
    q->numEntries++;
    q->tail = (q->tail + 1) % q->size;

    return true;
}


int dequeue(queue* q){
    int result;
    if(queueEmpty(q)){
        return QUEUE_EMPTY;
    }
    result = q-> values[q->head];
    q->head = (q->head +1) % q->size;
    q->numEntries--;

    return result;
}


int main(){ 
    queue q1;
    init_queue(&q1, 5);
    enqueue(&q1, 26);
    enqueue(&q1, 26);
    enqueue(&q1, 35);
    enqueue(&q1, 64);
    enqueue(&q1, 64);
    int t;
    while((t = dequeue(&q1)) != QUEUE_EMPTY){
        printf("t = %d\n", t);
    }

}
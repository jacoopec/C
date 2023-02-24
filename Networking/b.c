#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
//NULL pointer is generic, it can point to anything.
//fork and exec: fork clona un processo. Avere più processi da 2 benefici.
//cuncurrency:  i processi possono lavorare su cose diversi allo stesso tempo
//isolation: se un processo termina l'altro continua, perchè sono seprati. ANche la memoria è diversa.
//I threads permettono di avere solo la concorrenza, senza isolamento. Il processo è unico.
//threads hanno diverse chiamate allo stack ma sono enllo stesso spazio di memoria. Uno può scrivere nella memoria dell'altro.
//questo facilita la comunicazione.
//pthreads_create richiede un puntatore al codice da eseguire(puntatore alla funzione da eseguire)

void* uno(void* p){
    int* ptr = (int*)malloc(sizeof(int));
    int counter = 0;
    while(counter < 4){
        sleep(1);
        printf("uno");
        (*ptr)++;
        counter++;
    }
    return ptr;
}

void due(){
    int counter = 0;
    while(counter < 4){
        sleep(2);
        printf("due");
        counter++;
    }
    return;
}

int main(){
    int* p;
    pthread_t newThread;
    int v = 3;
    pthread_create(&newThread, NULL,uno, &v);
    due();
    pthread_join(newThread, (void*)&p);
    printf("thread returns: %i", *p);
}
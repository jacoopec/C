#include "../CHeaders.h"
#define ESC "\033"
#define CSI "["
#define PREVIOUSLINE "F"
#define BACKSPACE "D"


const int PROGBARLENGTH = 30;
const int NUMTHREADS = 3;


typedef struct{
    int countToVal;
    int progress;
    pthread_t thread;
} thread_info;


void updateBar(thread_info* tinfo){
    int numChars = (tinfo->progress * 100 / tinfo->countToVal) * PROGBARLENGTH / 100;
    printf("[");
    for(int i = 0; i < numChars; i++){
        printf("-");
    }
    if(tinfo->progress < tinfo->countToVal){
        printf(">");
    }
    for(int i = 0; i < numChars; i++){
        printf(" ");
    }
    printf("]\n");
    fflush(stdout);
}

void* mythreadfunc(void* arg){
    thread_info* tinfo = arg;

    for(tinfo->progress = 0; tinfo->progress < tinfo->countToVal; tinfo->progress++){
        usleep(1000);
    }
    return NULL;
}

int main(){
    thread_info threads[NUMTHREADS];

    for(int i = 0; i < NUMTHREADS;i++){
        threads[i].countToVal = rand() %1000;
        threads[i].progress = 0;
        pthread_create(&threads[i].thread, NULL, mythreadfunc, &threads[i]);
    }

    bool done = false;

    while(!done){
        done = true;
        for(int i = 0; i <NUMTHREADS; i++){
            updateBar(&threads[i]);
            if(threads[i].progress < threads[i].countToVal){
                done = false;
            }
        }
        if(!done){
            printf(ESC CSI "%d" PREVIOUSLINE, NUMTHREADS);
        }
        usleep(10000);
    }
    printf("\nDOne\n");
}
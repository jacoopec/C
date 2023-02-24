#include "../CHeaders.h"

const int PROGBARLENGTH = 30;

typedef struct{
    long totalBytes;
} statusInfo;

void updateBar(int percentDone){
    int numChars = percentDone * PROGBARLENGTH / 100;
    printf("\r[");
    for(int i = 0; i < numChars; i++){
        printf("-");
    }
    for(int i = 0; i < PROGBARLENGTH - numChars; i++){
        printf(" ");
    }
    printf("] %d%% Done", percentDone);
    fflush(stdout);
}

bool download_url(char* url, statusInfo* sinfo){
    
}

int main(){
    for(int i = 0; i <=100; i++){
        updateBar(i);
        usleep(20000);
    }
    printf("\n");
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
//NULL pointer is generic, it can point to anything.
//fork and exec: fork clona un processo. Avere più processi da 2 benefici.
//cuncurrency:  i processi possono lavorare su cose diversi allo stesso tempo
//isolation: se un processo termina l'altro continua, perchè sono seprati. ANche la memoria è diversa.
//I threads permettono di avere solo la concorrenza, senza isolamento. Il processo è unico.
//threads hanno diverse chiamate allo stack ma sono enllo stesso spazio di memoria. Uno può scrivere nella memoria dell'altro.
//questo facilita la comunicazione.
//pthreads_create richiede un puntatore al codice da eseguire(puntatore alla funzione da eseguire)
//race condition, due threads si contendono una risorsa, il risultato è incerto
//operazione atomica, non può essere interrotta.
//perchè due threads possano essere eseguiti in parallelo occorre avere più cores
//threads are also useful with user interfaces, the code has to respond very quickly.


#define BIG 1000000L
#define SERVER_PORT 8002
#define MAXLINE 4096
uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* uno(void* p){
    for(uint32_t i = 0; i < BIG; i++){
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

char* getHomePage(char* ipaddr, int* bytesRead){
    int sockfd, n;
    int sendbytes;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE];
    char* buffer = malloc(MAXLINE);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return NULL;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);

    if(inet_pton(AF_INET, ipaddr, &servaddr.sin_addr) <= 0)
        return NULL;

    if(connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0)
        return NULL;

    sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
    sendbytes = strlen(sendline);

    if(write(sockfd, sendline, sendbytes) != sendbytes)
        return NULL;
    memset(buffer, 0, MAXLINE);

    n = read(sockfd, buffer, MAXLINE-1);
    if(n<0)
        return NULL;

    *bytesRead = n;
    return buffer;
}

int main(){
    int* p;
    pthread_t newThread;
    char* buf;
    int bufLen;

    pthread_create(&newThread, NULL,uno, NULL);
    buf = getHomePage("172.217.0.78", &bufLen);
    pthread_join(newThread, NULL);
    printf("thread returns: %s", *buf);
}
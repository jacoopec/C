#include "headers.h"

//when you run a program it becomes a process, one program can produced many running processes
//fork crea un clone del programma
//come far eseguire ad un processo un altro programma in un child process?
//come faccio a creare un child process che esegue un altro programma?

int main(){
    int p = fork();
    printf("cazzi, process id: %d\n", getpid());
    if(p == 0){
        printf("child\n");
        execlp("./prova", NULL);
    } else {
        printf("parent");
    }

}
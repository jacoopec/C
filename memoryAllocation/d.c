#include "../CHeaders.h"

typedef struct node{
    char c;
    void *next;
}node;


int main(){
    printf("malloc n \n");
    node *n = malloc(sizeof(node));
    n->c = 'j';
    printf("assegno ad n j %c\n",n->c);
    node *n2; //n2 non ha ancora un indirizzo
    printf("stampa indirizzi\n");
    printf("n %p\n",n);
    printf("n2 %p\n",n2);
    printf("n2 punta anche lui a n\n");
    n2 = n;
    printf("n2 punta anche lui a n e gli viene assegnato e\n");
    printf("n2 %c\n",n2->c);
    n2->c = 'e';
    printf("ad n viene assegnato un nuovo indirizzo con malloc\n");
    n = malloc(sizeof(node));
    n->next = n2;
    printf("stampa indirizzi\n");
    printf("n %p\n",n);
    printf("n2 %p\n",n2);
    //controllo valori
    //pulisco
    printf("libera memoria\n");
    free(n2);
    free(n);
    //controllo che siano NULL
    printf("n %c\n",n->c);
    printf("n2 %c\n",n2->c);

}
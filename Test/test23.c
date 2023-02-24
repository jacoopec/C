#include "../CHeaders.h"

//nella funzione g il valore di x non torna a 10 ma rimane incrementato.
//ogni volta che viene incrementato, anche nella stampa rimane così, non torna al valore di prima.
static int f (int i ){
    int x = 1;
    printf("x%i\n",x);
    printf("%i\n",i + x++);
    return i + x++;
}

int g(int i ){
    static int x = 10;
    printf("x%i\n",x++);
    printf("%i\n",i + x++);
    return i + x++;
}

int main(){
    printf("%d\n", g(g(f(f(0)))));
}
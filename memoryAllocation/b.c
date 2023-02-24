#include "headers.h"
//memory allocated statically stays from the beginning till the end. 
//If we don't don't how much memory we need we should use dinamic allocation.
//accesing or freeing a free block of memory can also crash a program
//

int main(){
    int* x = malloc(sizeof(int)); //restituisce un puntatore ad un blocco o NULL se non può darla.
    int* arr = malloc(sizeof(int)*100);

    free(arr);   //we don't need it anymore
    free(x);

    //calloc 
    double* arr = calloc(sizeof(double),100);
    arr = realloc(arr, sizeof(double)*500);
}
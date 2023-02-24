#include "libs.h"

int main(){

        int input[10]= {45,7,5,4,37,25,1,65,74,45};
    // int input[2]= {4,1};
    const char* phrase = Minimo;
    size_t size = sizeof(input)/sizeof(int);
    printf("%s %i %i\n", phrase, input[0], Minimo(input, size));
    // printf("%s %i %i\n", phrase, input[1], Minimo(7,3));
    // printf("%s %i %i\n", phrase, input[2], Minimo(5, 4));
}
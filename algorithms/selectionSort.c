#include "common.h"

void selectionSort(){
    int nop = 0;
    int counter = 0;
    int minimum = counter;
    int traversing = counter+1;

    for(int counter = 0; counter<size; counter++){
        minimum = counter;
        traversing = counter +1;
        printf("counter %i\n",counter);
        for(; traversing < size; traversing++){
            nop++;
            printf("traversing %i\n",traversing);
            if(array[traversing] < array[minimum]){
                minimum = traversing;
                printf("new minimum:%i \n",array[minimum]);
            } else {
                printf("continuing\n");
            }
        }
        printf("minimum %i\n", minimum);
        int temp = array[counter];
        array[counter] = array[minimum];
        array[minimum] = temp;
    }
    printf("Printing\n");
    for(int i = 0; i<size; i++){
        printf("%i \n", array[i]);
    }
    printf("\n");
    printf("Number of op %i",nop);
}
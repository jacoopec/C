#include "common.h"

void oddEvenSort(){
    int nop;
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(int traversing = 1; traversing<size-1; traversing +=2){
                if(array[traversing] > array[traversing+1]){
                nop++;
                int temp = array[traversing];
                array[traversing] = array[traversing+1];
                array[traversing + 1] = temp;
                sorted = false;
                }
        }
        for(int traversing = 0; traversing<size-1; traversing +=2){
                if(array[traversing] > array[traversing+1]){
                nop++;
                int temp = array[traversing];
                array[traversing] = array[traversing+1];
                array[traversing + 1] = temp;
                sorted = false;
                }
        }
    }
        printf("Printing\n");
    for(int i = 0; i<size; i++){
        printf("%i \n", array[i]);
    }
    printf("Number of op %i",nop);
}
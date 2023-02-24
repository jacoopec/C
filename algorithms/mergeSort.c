#include "common.h"

void mergeSort(){
    if(right > left){
        int middle = (left + right)/2;
        mergeSort(left, middle, arr);
        mergeSort(middle+1, right, arr);
        
    }
}
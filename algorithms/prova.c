#include "../cheaders.h"

const int size = 4;
int array[10];
int arrayReturn[4];

void init(){
    array[0] = 100;
    array[1] = 83;
    array[2] = 72;
    array[3] = 68;
    array[4] = 57;
    array[5] = 43;
    array[6] = 38;
    array[7] = 28;
    array[8] = 17;
    array[9] = 2;
}



void selectionSort(){
    int nop = 0;
    int counter = 0;
    int traversing = counter+1;
    int minimum;

    for(;counter < size; counter++){
        traversing = minimum = counter;
        for(;traversing < size; traversing++){
            nop++;
            if(array[traversing] < array[minimum]){
                minimum = traversing;
            } else {continue;}
        }
        int temp = array[counter];
        array[counter] = array[minimum];
        array[minimum] = temp;

    }
    printf("selectionSort: %i\n",nop);
    return;
}

void cocktailShaker(){
    int nop = 0;
    bool swapped = true;
    int traversing = 0;
    while(swapped){
        swapped = false;
        traversing = 0;
        for(;traversing<size-1; traversing++){
            nop++;
            if(array[traversing] > array[traversing+1]){
                int temp = array[traversing];
                array[traversing] = array[traversing+1];
                array[traversing+1] = temp;
                swapped = true;
            }
        }
        for(;traversing>0; traversing--){
            nop++;
            if(array[traversing] < array[traversing-1]){
                int temp = array[traversing];
                array[traversing] = array[traversing-1];
                array[traversing-1] = temp;
                swapped = true;
            }
        }
    }
    printf("cocktailShakerSort: %i\n",nop);
}


void bubbleSort(){
    int nop = 0;
    bool swapped = true;
    int traversing = 0;
    while(swapped){
        swapped = false;
        traversing = 0;
        for(;traversing<size-1; traversing++){
            nop++;
            if(array[traversing] > array[traversing+1]){
                int temp = array[traversing];
                array[traversing] = array[traversing+1];
                array[traversing+1] = temp;
                swapped = true;
            }
        }
    }
    printf("bubbleSort: %i\n",nop);
}

void oddEvenSort(){
    int nop=0;
    bool sorted = false;
    while(!sorted){
        sorted = true;
        int traversing = 1;
        for(; traversing<size-1; traversing+=2){
            if(array[traversing] > array[traversing+1]){
                nop++;
                int temp = array[traversing];
                array[traversing] = array[traversing+1];
                array[traversing+1] = temp;
                sorted = false;
            }
        }
        traversing = 0;
        for(; traversing<size-1; traversing+=2){
            if(array[traversing] > array[traversing+1]){
                nop++;
                int temp = array[traversing];
                array[traversing] = array[traversing+1];
                array[traversing+1] = temp;
                sorted = false;
            }
        }
    }
    printf("oddEvenSort: %i\n",nop);
}

void mergeSortRec(int left, int right, int Array[], int S){

}

void mergeSort(int left, int right, int Array[], int S){

    int traversingR = 0;
    int traversingL = 0;
    int traversingM = 0;
    printf("left: %i, right: %i\n", left, right);
    printf("left element: %i,right element: %i, S:%i: \n\n", Array[left], Array[right], S);

    int arrayL[S/2];
    int arrayR[S/2];
    for(int i = 0; i < S/2; i++){
        arrayL[i] = Array[i];
        arrayR[i+S/2] = Array[i+S/2];
    }

    int middle = (left + right)/2;
    if((right-left)>1){
        mergeSort(left,middle,arrayL, S/2);
        mergeSort(middle+1,right,arrayR,S/2);
    }
    
    while( traversingL < S || traversingR < S || traversingM < size){
        if(arrayL[traversingL] < arrayR[traversingR]){
            printf("left element: %i,right element: %i, S:%i: \n\n", Array[left], Array[right], S);
            arrayReturn[traversingL] = arrayL[traversingL];
            traversingL++;
        } else {
            arrayReturn[traversingM] = arrayR[traversingR];
            traversingR++;
        }
        traversingM++;
    }


    // for(int i = 0; i < S; i++){
    //     arrayReturn[i] = arrayL[i];
    //     arrayReturn[i + S/2] = arrayR[i];
    // }

   return;
}


void cycleSort(int Array[]){
    int current = 0, position = 0, outer = 0;
    int counter = 0;
    int count;
    int temp = Array[current];
    bool cycleCompleted = false;
    int startingIndex = 0;

    while(!cycleCompleted){
        for(int t = 0; t < 5; t++){
            if(Array[t] < temp){
                counter++;
            }
        }
        temp = Array[counter];
        Array[counter] = Array[current];
        current = counter;
        printf("count: %i, temp: %i, counter: %i\n", count, temp, counter);
        visited[count] = counter;
        count++;
        if(counter == startingIndex){
            cycleCompleted = true;
        }
        counter = 0;
    }
    

    // for(; outer < size-2; outer++){
    //     position = outer;
    // }
    // for(; > size - 1){
    //     if( < ){
    //         position++;
    //     }
    //     if(position == outer){

    //     } else
    // }

    // if(position != outer){
    //     int temp = array[current];
    //     array[position] = array[current];
    //     array[traversing+1] = temp;
    // }
    // while(position != outer){

    // }
}


int main(){
    // init();
    // selectionSort();
    // init();
    // bubbleSort();
    // init();
    // cocktailShaker();
    // init();
    // oddEvenSort();
    int array2[size] = {6,32,62,1};
    int array3[5] = {6,32,62,1,3};

    // mergeSort(0, 3, array2, 4);
    cycleSort(array3);

    for(int i = 0; i < size; i++){
        printf("%i: %i \n", i, arrayReturn[i]);
    }
    printf("\n");
}
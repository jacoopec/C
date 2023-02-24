#include "../CHeaders.h"

//the while loop increments k till 3, then, the program continues its execution printing a[3]

int main(){
    enum { N = 4};
    int a[N] = {0,1,2,3};
    int k = 0;
    printf("%i \n",  k < N & a[k] != 2); 
    while( k < N & a[k] != 2) k++;
    printf("%d \n", k); 
    return 0;
}
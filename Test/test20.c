#include "../CHeaders.h"

static void f(unsigned k, int a[], int const n){
    assert(k < n);
    ++a[k++];
}

int main(){
    int i = 2;
    int const d = 3;
    int a[] = {1,2,3,4};
    f(i,a,3);
    printf("%i", assert(d<i));
    printf("i = %d, a = { %d, %d, %d, %d}\n", i, a[0],a[1],a[2],a[3]);
}
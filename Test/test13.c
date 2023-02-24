#include "../CHeaders.h"

//compile time error, for using a undeclared identifier a.
int xyz();
int xyz(int arr[], int n){
    int x = 0;
    for(int i = 0; i < n; i++){
        x += arr[i];
    }
    return x;
}

int main(){
    __int32_t arr[] = {12,6,23,52,6,2};
    int n = sizeof(arr[1]);
    printf("n%i\n",n);
    printf("%d", xyz(arr, n));
    return 0;
}

int a;

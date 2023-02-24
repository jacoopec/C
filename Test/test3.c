#include <stdio.h>
#include <stdbool.h>

int main(){
    char a = 1;
    while(a){
        a++;
    }
    a++;
    printf("%d",a);
    return 0;
}
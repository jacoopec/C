#include <stdio.h>
#include <stdbool.h>

static bool foo(int n){
    return n!=0 & 10 / n < 10;
}
int main(){
    printf("'%s'\n", foo(10) | foo(0) ? "true" : "false");
}
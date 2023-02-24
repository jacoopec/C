#include <stdio.h>
#include <stdbool.h>

static int f(int i){
    int x = 1;
    return i + x++;
}

int g(int i){
    static int x = 10;
    return i + x++;
}



int main(){
    printf("%d\n", g(g(f(f(0)))));
}
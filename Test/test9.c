#include "../CHeaders.h"

char foo(unsigned n){
    char const* const p = "01234567";
    return *(p+n%8);
}

char foo2(unsigned n){
    return "01234567"[n%8];
}

int main(){
    printf("%c\n","01234567"[3]);  //vale 3
    printf("2%4: %i\n", (int)(2%4));  //vale 3
    printf("%c\n", foo(4));
    printf("%c\n",foo2(4));
}
#include <stdio.h>
#include <stdbool.h>

int main(){
    char s[] = "abcdefghijklmnopqrstuvwxyz";
    int n = 26;
    int i = 3;
    for(; i < n; i += 2) s[i] = '_';
    printf("\"%s\"\n", s);
}
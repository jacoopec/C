#include "../CHeaders.h"

static char s[] = "Is this a mystery?";
typedef char *string_t;
static string_t ps = &s[1];

//initializing memory allocated with malloc
int main(){
    size_t n = 10;
    int *p = malloc( n*sizeof(int));

    for(size_t i = 0; i < n;i++){
        *(p+1) = 0;
        //p[i] = 0;
    }
    free(p);
}
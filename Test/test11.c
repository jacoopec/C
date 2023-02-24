#include "../CHeaders.h"

static char s[] = "Is this a mystery?";
typedef char *string_t;
static string_t ps = &s[1];

int main(){
    char s1[3] = {'a','b','c'};   //array without termination, it is not a string
    char s1[2] = {'e','t',0}; // array with termination, it is a string C
    char s1[4] = "pera";
    char s1[] = "jcoi"; //the compiler will determine N which will allocate also psace for the termination
    char s1[10] = "icojd"; //N is larger that it has to, the remaining characters will be initialized to 0

    
}
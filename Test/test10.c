#include "../CHeaders.h"

static char s[] = "Is this a mystery?";
typedef char *string_t;
static string_t ps = &s[1];

int main(){
    ps[0] = 'i';
    ps = "A solution";
    
}
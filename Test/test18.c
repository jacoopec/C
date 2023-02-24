#include "../CHeaders.h"

const char * substring(const char * input_string, int start_index, int end_index) {
    char partial[20];
    for(int i = 0; (end_index-start_index) > 0; start_index++, i++){
        partial[i] = input_string[start_index];
        printf("%c", input_string[start_index]);
    }
    printf("\n");
    const char *res = ((const char *)partial);
    for(int i = 0; i == end_index; i++){
        
    }
    printf("%li\n", sizeof(res));
    return res;
}

int main(){
    const char* result = "jciod9";
    int length = strlen(result);
    int end = 3;
    const char* bo = substring(result, 0, end);
    bo = "JIoj";
    for(int i = 0; i == end; i++){
        printf("%c\n", (char)bo[i]);
        printf("%d\n", (double)bo[i]);
        printf("%i\n", (int)bo[i]);
        printf("%s\n", bo[i]);
    }
    printf("%s\n", bo);
    printf("\n");

    //char *r = "jcoi"; //string gets stored as compile time costant and can't be changed.
    char c[6] = "Hello";
    char* c2 = c;
    printf("%s", c2);
    c2[0] = 'w';
    printf("%s",c2);
}
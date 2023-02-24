#include "../CHeaders.h"



int main(){
    int result;
    const char* path = "text2.txt";
    char str[10];
    char *ret;
    FILE *f = fopen(path, "r");
    int c;
    printf("reading:\n");
    
    while(1){
        ret = fgets(str,8,f);
        printf("%c",str);
    }
    fclose(f);
}
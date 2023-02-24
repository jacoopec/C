#include "../CHeaders.h"



int main(){
    int result;
    const char* path = "text2.txt";
    char *phrase = "mit skifahren";
    FILE *f = fopen(path, "w");
    int c, i =0;
    printf("writing:\n");
    
    while(1){
        c = phrase[i];
        printf("%c",(char)fputc(c,f));
        i++;
        if (i == 13) break;
    }
    fclose(f);
}
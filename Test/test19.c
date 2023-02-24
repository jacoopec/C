#include "../CHeaders.h"

int lengthString(char* str){
    int result = 0;
    for(int i = 0; i < 100; i++){
        if(str[i] != '\0'){result++;}else{break;}
    }
    return (result);
}

typedef struct node{
    char c;
    void *next;
}node;

void reverseWithStack(const char* str){
    int i = 0;
    node* prev = malloc(sizeof(node));
    node* act;
    act->next = prev;
    while(str[i] != '\0'){
        node* tmp = act;
        prev = act;
        act = malloc(sizeof(node));
        act->c = str[i];
        act->next = prev;
        i++;
    }
    char array[20];

}

void reverseString(char* str){
    int c;
    int l = lengthString(str);
    int size = l;
    char *start = str, *end =(str+(char)(l-1)), tmp;

    for(c = 0; c < l/2; c++){
        printf("swapping %c  %c \n", *start,*end);
        tmp = *end;
        *end = *start;
        *start = tmp;
        start++;
        end--;
    }
}

const char* reverse_string(const char * input_string) {
    char str[30]; 
    int c = 0;
    int result = 0;
    for(int i = 0; i < 100; i++){
        if(input_string[i] != '\0'){str[result] = (char)*(input_string+(char)result);result++; }else{break;}
    }
    printf("%i\n",result);

    char *start = str, *end =(str+(char)(result-1)), tmp;

    for(c = 0; c < result/2; c++){
        // printf("swapping %c  %c \n", *start,*end);
        tmp = *end;
        *end = *start;
        *start = tmp;
        start++;
        end--;
    }
    const char* res = (const char*)(str);
    // printf("%s\n", res);

    return res;
}

void reverseRecursive(char *start, char* end){
        // printf("%p  %p\n", start, end);
    if(start != end){
        // printf("%c  %c\n", *start, *end);
        char tmp = *start;
        *start = *end;
        *end = tmp;
        reverseRecursive(start+1, end-1);
    } else {
        return;
    }
}

main(){
    const char* str = "A2sIdJOIZ2IQW29019ijo";
    int i = 0;
    char s[100] = {'c','h','4','j','2'};
    //aritmetica puntatori
    // char* r = malloc(4);
    // printf("%p\n", r+0);
    // printf("%p\n", r+1);
    // printf("%p\n", r+2);
    // printf("%p\n", r+3);
    //stampo indirizzi di emmoria di stack e heap notare come siano vicini tra loro
    // printf("Stack: \n %p\n", s);
    // printf("%p\n", &i);
    // printf("%p\n", &str);
    // printf("Heap:\n%p\n", r);
    // printf("Function:\n %p \n %p\n", examineString, reverseString);
    // examineString(s);
    // char* str2 = reverseString(s);
    // reverseRecursive(s,s+((char)lengthString(s)-1));
    // printf("%s\n", s);
    const char* h =  reverse_string(str);
    reverseWithStack(str);
    printf("%s\n", reverse_string(str));
    return 1;
}
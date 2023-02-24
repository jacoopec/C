#include "../CHeaders.h"

int main(){
    int i = 0;
    int j = 0;
    while(true){
        printf("++j j increases immediately %i\n",++j);
        printf("j %i\n",j);
        printf("i++ i will increase at the next instruction %i\n",i++);
        printf("i %i\n",i);
        printf("-------------\n");
        sleep(1);
    }
}
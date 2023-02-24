#include "../CHeaders.h"

int main(){
    int i = 0;
    int j = 0;
    for(int i = 0; i < 5; ++i){
        static int a = 0;
        ++a;
        i = i + a;
    }
    return 0;
}
#include "../CHeaders.h"

int main(int argc, char** argv){
    if(argc != 2){
        fprintf(stderr,"usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
}
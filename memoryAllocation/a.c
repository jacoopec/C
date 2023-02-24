#include "headers.h"

typedef struct person{
    char* name;
    unsigned int age;
}person;

int main(){
    void* vp = malloc(5); //store 100 bytes, no type information.
    bzero(vp,5); //inizializzazione a 0
    char* cp = (char* )vp; //if I want to store something in that memory I have to give it a type
    //accessing the byte directly
    cp[0] = 0x2A;
    cp[1] = 0x33;
    cp[2] = 0x02;
    cp[3] = 0x63;
    cp[4] = 0x30;
    for(int i = 0; i< 5; i++){
        printf("[%i]: %c %i\n",i,cp[i], cp[i]);
    }
    //------------------------------------------------------------------------------
    int* ip = (int*)vp;
    ip[0] = 0x00000044;
    ip[1] = 0x00000010;
    ip[2] = 0xFFFFFFFF;
    ip[3] = 0x0FFFFFFF;
    for(int i = 0; i< 4; i++){
        printf("[%i]: unsigned   %u    signed   %i\n",i,ip[i], ip[i]);
    }
    //------------------------------------------------------------------------------

    person* p = (person*)vp;
    p->name= "Piero";
    p->age= 83;

}
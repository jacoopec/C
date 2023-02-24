#include "../CHeaders.h"
//the struct has room for all of the members, the union assumes you are storing one of these elements but not all of them.

typedef struct myStr{
    int x;
    double y;
}myStr;

typedef union myUni{
    int x;
    float y;
}myUni;

typedef struct{
    char* name;
    bool isRobot;
    union{
        char* personality;
        int firmware;
    };
} character;

void printCharacter(character* c){
    printf("Character: %s --", c->name);
    if(c->isRobot){
        printf("version %i", c->firmware);
    } else {
        printf("%s", c->personality);
    }
    printf("\n");
}

int main(){
    myUni uni = {.x = 3, .y =4.3};
    printf("%lu\n", sizeof(myStr));
    printf("%lu\n", sizeof(uni));
    character hansolo;
    character r2d2;
    hansolo.name = "Han Solo";
    hansolo.isRobot = false;
    r2d2.name = "R2";
    r2d2.isRobot = true;
    r2d2.firmware = 42;
    printCharacter(&hansolo);
    printCharacter(&r2d2);
}
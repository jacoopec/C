#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

#define MAXNAME 256
#define TABLESIZE 10

typedef struct person{
    char* name;
    int age;
}person;

person* hashTable[TABLESIZE];

bool init_hash_table(){
    for(int i = 0; i < TABLESIZE; i++){
        hashTable[i] = NULL;
    }
}

unsigned int hash(char* name){
    unsigned int length = strlen(name);
    unsigned int sum;
    for(int i = 0; i< length; i++){
        sum += (unsigned int)name[i];
    }
    return sum % TABLESIZE;
}

void print_table(){
    printf("Name:\t Age:\tIndex:\n");
    for (int i = 0; i < TABLESIZE; i++){
        if(hashTable[i] == NULL){
            printf("___\t___\t\t %i\n",i);
        } else{
            printf("%s\t%i\t%i\n",hashTable[i]->name,hashTable[i]->age,i);
        }
    }
}

void addToTable(person* p){
    unsigned int index = hash(p->name);
    if(hashTable[index] == NULL){
        hashTable[index] = p;
    } else {
        printf("Spot already filled.");
    }
}

person* hash_table_lookup(char* name){
    unsigned int index = hash(name);
    if(hashTable[index] != NULL && strncmp(hashTable[index]->name, name, strlen(name))==0){
        return hashTable[index];
    } else {
        return NULL;
    }
}

int main(){
    init_hash_table();
    person icdj = {.name = "icdj", .age = 12};
    person bajukkti = {.name = "bajukkti", .age = 42};
    person bfdvdfv = {.name = "bfdvdfv", .age = 73};
    person sdfgj = {.name = "sdfgj", .age = 23};
    person gukwrrrrilo = {.name = "gukwrrrrilo", .age = 74};
    addToTable(&icdj);
    addToTable(&bajukkti);
    addToTable(&sdfgj);
    addToTable(&gukwrrrrilo);
    printf("df => %u\n", hash("df"));
    printf("23 => %u\n", hash("23"));
    print_table();
}
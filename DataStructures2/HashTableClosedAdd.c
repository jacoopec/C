#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

#define MAXNAME 256
#define TABLESIZE 15

typedef struct person{
    struct person* next;
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
    unsigned int sum = 0;
    for(int i = 0; i< length; i++){
        sum += (unsigned int)name[i];
    }
    return sum % TABLESIZE;
}

void print_table(){
    printf("Name:\t \tAge:\tIndex:\n");
    for (int i = 0; i < TABLESIZE; i++){
        if(hashTable[i] == NULL){
            printf("_________\t\t %i\n",i);
        } else{
            printf("%s\t%i\t%i\n",hashTable[i]->name,hashTable[i]->age,i);
        }
    }
}

bool addToTable(person* p){
    unsigned int index = hash(p->name);
    // printf("Index: %u\n", index);
    p->next = hashTable[index];
    hashTable[index] == p;
    return true;
}

person* hash_table_lookup(person* p ){
    unsigned int index = hash(p->name);
    person* tmp = hashTable[index];
    while(tmp != NULL && (strncmp(hashTable[index]->name, p->name, strlen(p->name))==0)){
        tmp = tmp->next;
    }
    return tmp;
}

person* hash_table_delete(char* name){
    unsigned int index = hash(p->name);
    person* tmp = hashTable[index];
    person* prev = NULL;
    while(tmp != NULL && (strncmp(hashTable[index]->name, p->name, strlen(p->name))==0)){
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL) return NULL;
    if(prev == NULL){
        hashTable[index] = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    return tmp;
}

int main(){
    init_hash_table();
    person Bernardello = {.name = "Bernardello", .age = 12};
    person Apollonio = {.name = "Apollonio", .age = 42};
    person Sirio = {.name = "Sirio", .age = 22};
    person Claudiano = {.name = "Claudiano", .age = 73};
    person Consenzio = {.name = "Consenzio", .age = 23};
    person Tarminide = {.name = "Tarminide", .age = 23};
    person Cosenzio = {.name = "Cosenzio", .age = 23};
    person Catamarano = {.name = "Catamarano", .age = 23};
    person Presenzio = {.name = "Presenzio", .age = 23};
    person Priminio = {.name = "Priminio", .age = 23};
    person GianCosenzio = {.name = "GianCosenzio", .age = 23};
    person PierScafandro = {.name = "PierScafandro", .age = 23};
    person Carpuzio = {.name = "Carpuzio", .age = 343};
    person Tirillo = {.name = "Tirillo", .age = 343};
    person Caterenzio = {.name = "Caterenzio", .age = 63};
    person Germano = {.name = "Germano", .age = 63};
    person gukwrrrrilo = {.name = "Esiodo", .age = 74};
    printf("Bernardello -> %u\n",hash("Bernardello"));
    addToTable(&Bernardello);
    addToTable(&Apollonio);
    addToTable(&Consenzio);
    addToTable(&Sirio);
    addToTable(&Claudiano);
    addToTable(&Presenzio);
    addToTable(&Priminio);
    addToTable(&Caterenzio);
    addToTable(&GianCosenzio);
    addToTable(&PierScafandro);
    addToTable(&Carpuzio);
    addToTable(&Tirillo);
    addToTable(&Tarminide);
    addToTable(&Germano);
    addToTable(&Catamarano);
    addToTable(&gukwrrrrilo);
    print_table();
    person* p = hash_table_lookup(&Apollonio);
    printf("%s\n",p->name);
}
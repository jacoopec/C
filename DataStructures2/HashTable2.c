#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
//hash table = hash function + array

#define MAXNAME 256
#define TABLESIZE 15
#define DELETED 0

typedef struct person{
    person *next;
    char *name;
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
    for(int i = 0; i < length; i++){
        // printf("Name at i:   %c   %i\n", name[i], (unsigned int)name[i]);
        sum += (unsigned int)name[i];
    }
    // printf("Sum: %i\n",sum);
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
    printf("\n");
}

bool addToTable(person* p){
    unsigned int index = hash(p->name);
    // printf("Index: %u\n", hash(p->name));
    if(hashTable[index] == NULL){
        hashTable[index] = p;
        return true;
    } else {
        for(int i = 1; i< TABLESIZE; i++){
                if(hashTable[i] == NULL){
                    hashTable[i] = p;
                    return true;
                } else { continue;
                }
        }
        printf("Table filled, %s left out \n", p->name);
        return false;
    } 
}

bool hash_table_lookup(person* p ){
    unsigned int index = hash(p->name);
    printf("Index: %u", index);
    if((hashTable[index] != NULL) && (strncmp(hashTable[index]->name, p->name, strlen(p->name))==0)){
        return true;
    } else {
        for(int i = 1; i< TABLESIZE; i++){
            if((hashTable[i] != NULL) && (strncmp(hashTable[i]->name, p->name, strlen(p->name))==0)){
                return true;
            } else { continue;}
        }
    return false;
    }
}

person* hash_table_delete(char* name){
    unsigned int index = hash(name);
    for(int i = 0; i < TABLESIZE; i++){
        if(hashTable[i] == NULL) return NULL;
        else if (hashTable[i] == DELETED) continue;
    } 
    if((hashTable[index] != NULL) && (strncmp(hashTable[index]->name, name, strlen(name))==0)){
        // person* tmp = hashTable[index];
        hashTable[index] = NULL;
        return hashTable[index];
    } else {
        return NULL;
    }
}

bool deletePerson(char* name){
    unsigned int index = hash(name);
    if((hashTable[index] != NULL) && (strncmp(hashTable[index]->name, name, strlen(name))==0)){
        // person* tmp = hashTable[index];
        hashTable[index] = NULL;
        return 1;
    }
    return 0;
}

int main(){
    init_hash_table();
    person Bernardello = {.name = "Bernardello", .age = 12};
    person Apollonio = {.name = "Apollonio", .age = 42};
    person Sirio = {.name = "Sirio", .age = 22};
    person Claudiano = {.name = "Claudiano", .age = 73};
    person Prepuzio = {.name = "Prepuzio", .age = 73};
    person Caruggio = {.name = "Caruggio", .age = 73};
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
    // printf("Bernardello -> %u\n",hash("Bernardello"));
    addToTable(&Bernardello);
    addToTable(&Caruggio);
    addToTable(&Prepuzio);
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
    printf("Index: %i\n", hash("Caruggio"));
    print_table();
    hash_table_delete("Prepuzio");
    deletePerson((&Prepuzio)->name);
    print_table();
    // printf(" %i\n", hash_table_lookup(&Apollonio));
}
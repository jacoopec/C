#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

#define MAXNAME 256
#define TABLE_SIZE 10

typedef struct person{
    char* name;
    int age;
}person;

//HASH FUCKING FUNCTION
unsigned int hash(char* name){
    int length = strnlen(name, MAXNAME);
    unsigned int hash_val = 0;
    for(int i = 0; i < length; i++){
        hash_val += name[i];
        hash_val *= 3;
        hash_val =round((hash_val +1) % TABLE_SIZE);
    }
    return hash_val;
}

//HASH FUCKING TABLE
person* hash_table[TABLE_SIZE];

bool init_hash_table(){
    for(int i = 0; i <TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

void hash_table_insert(person* p){
    if(p == NULL){ return;};
    int index = (int)hash((p->name));

    printf("Index %i for %s\n",index, p->name);
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (i+ index) % TABLE_SIZE;
        if(hash_table[try] != NULL){
            printf("Spot already filled for %s, at %i looking for another.\n",p->name,try);
            continue;
        } else {
            printf("Spot found for %s, at %i.\n",p->name,try);
            hash_table[try] = p;
            return;
        }
    }
    return;
}

person* hash_table_delete(char* name){
    int index = hash(name);
    if(hash_table[index] != NULL && strncmp((hash_table[index]->name), name, TABLE_SIZE)==0){
        person* tmp = hash_table[index];
        hash_table[index] = NULL;
        printf("Removed %s\n", tmp->name);
        return tmp;
    } else {
        return NULL;
    }
}

void print_table(){
    for(unsigned int i = 0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n",i);
        } else {
            printf("\t%i\t%s\n",i, hash_table[i]->name);
        }
    }
    return;
}

person* hash_table_lookup(char* name){
    int index = hash(name);
    if(hash_table[index] != NULL && strncmp((hash_table[index]->name), name, TABLE_SIZE)==0){
        return hash_table[index];
    } else {
        return NULL;
    }
}

void findPerson(char name[MAXNAME]){
    person* p = hash_table_lookup(name);
    if(p != NULL){
        printf("Found: %s\n", p->name);
    } else {
        printf("Not Found.\n");
    }
}

int main(){
    init_hash_table();
    print_table();
    person Gianni;
    Gianni.age=53;
    Gianni.name = "Gianni";
    person Tony = {.name = "Tony", .age=13};
    person Pietro = {.name = "Pietro", .age=24};
    person Io = {.name = "Davide", .age=45};
    hash_table_insert(&Gianni);
    hash_table_insert(&Tony);
    hash_table_insert(&Pietro);
    hash_table_insert(&Io);
    print_table();
    findPerson("diojsc");
    findPerson("Gianni");
    person* p = hash_table_delete("Gianni");
    print_table();

    // printf("babacar => %u\n", hash("babacar"));
    // printf("Tony => %u\n", hash("Tony"));
    // printf("Pietro => %u\n", hash("Pietro"));
    // printf("Davide => %u\n", hash("GIno"));
}
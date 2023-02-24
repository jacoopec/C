#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
//hash table = hash function + array
#define MAXNAME 256
#define TABLESIZE 15
#define LISTSIZE 15
#define DELETED (uintptr_t)(0xFFFFFFFFFFFFFFFFUL)
bool tableFilled = false;
int names = 0;

typedef struct person{
    char *name;
    int age;
    void *next;
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
    printf("Names number %i\n", names);
    printf("Name:\t \tAge:\tIndex:\n");
    for (int j = 0; j < TABLESIZE; j++){
        if(hashTable[j] == NULL){
            printf("_________\t\t %i\n", j);
        } else {
            person *tmp = hashTable[j];
            printf("%s\t%i\t",tmp->name,tmp->age,j);
            if(tmp->next != NULL){tmp = tmp->next;}
            while(tmp != NULL){
                if(tmp == DELETED){
                    printf("%p\t\t %i",DELETED);
                } else {
                    printf("%s\t%i\t",tmp->name,tmp->age);
                    if(tmp->next != NULL){tmp = tmp->next;}else{break;}
                }
            }
            printf("%s\t%i\t",tmp->name,tmp->age);
            printf("\n");
        }
    }
    printf("\n");
}

bool addToTableOpen(person* p){
    if(!tableFilled){
        unsigned int index = hash(p->name);
        // printf("Index: %u\n", hash(p->name));
        if(hashTable[index] == NULL){
            hashTable[index] = p;
            return true;
        } else {
            for(int i = 1; i< TABLESIZE; i++){
                    if(hashTable[i] == NULL){
                        printf("For %s Index was: %i, but inserted in: %i \n", p->name, index, i);
                        hashTable[i] = p;
                        return true;
                    } else { continue;}
            }
        } 
    }
    printf("Table filled, %s left out \n", p->name);
    return 0;
}

bool addToTableClosed(person* p){
    names++;
    unsigned int index = hash(p->name);
    // printf("Index: %u\n", hash(p->name));
    if(hashTable[index] == NULL){
        hashTable[index] = p;
        printf("Inserted, %s at: %p  %i, 0\n", p->name, hashTable[index],index);
    } else {
        person *tmp = hashTable[index];
        while(tmp->next != NULL){
            tmp = tmp->next;
            continue;
        }
        (tmp->next) = p;
        printf("Linked to list, %s %i\n", p->name,index);
    }
    return 1;
}

bool hash_table_lookup(person* p ){
    unsigned int index = hash(p->name);
    printf("name: %s,Index: %u\n", p->name, index);
    person *tmp = p;
    if(hashTable[index] == NULL){
        printf("Person doesn't exist.\n");
        return 0;
    }
    while((tmp != NULL)){
        if((strncmp(tmp->name, p->name, strlen(p->name))==0)){
            printf("name: %s, Found at: %u\n",p->name, index);
            return 1;
        } else {
            tmp = tmp->next;
        }
    }
    printf("Person doesn't exist.\n");
    printf("\n");
    printf("\n");
}


// person* hash_table_delete(char* name){
//     unsigned int index = hash(name);
//     for(int i = 0; i < TABLESIZE; i++){
//         if(hashTable[i] == NULL) return NULL;
//         else if (hashTable[i] == DELETED) continue;
//     } 
//     if((hashTable[index] != NULL) && (strncmp(hashTable[index]->name, name, strlen(name))==0)){
//         // person* tmp = hashTable[index];
//         hashTable[index] = DELETED;
//         return hashTable[index];
//     } else {
//         return NULL;
//     }
// }

// bool deletePerson(char* name){
//     for(int i = 0; i < TABLESIZE; i++){
//         if((strncmp(hashTable[i]->name, name, strlen(name))==0)){
//             hashTable[i] = DELETED; printf("deleted: %s found at: %u\n", name, i); return 1;} else {continue;}
//     } 
//     printf("Can't delete person not found %s\n", name);
//     return 0;
// }

int main(){
    init_hash_table();
    person Bernardello = {.name = "Bernardello", .age = 12};
    person Apollonio = {.name = "Apollonio", .age = 42};
    person Sirio = {.name = "Sirio", .age = 22};
    person Claudiano = {.name = "Claudiano", .age = 58};
    person Prepuzio = {.name = "Prepuzio", .age = 23};
    person Caruggio = {.name = "Caruggio", .age = 73};
    person Posentano = {.name = "Posentano", .age = 53};
    person Settimio = {.name = "Settimio", .age = 63};
    person Ginepro = {.name = "Ginepro", .age = 10};
    person Consenzio = {.name = "Consenzio", .age = 83};
    person Tarminide = {.name = "Tarminide", .age = 23};
    person Cosenzio = {.name = "Cosenzio", .age = 23};
    person Catamarano = {.name = "Catamarano", .age = 23};
    person Gisualdo = {.name = "Gisualdo", .age = 93};
    person Presenzio = {.name = "Presenzio", .age = 23};
    person Priminio = {.name = "Priminio", .age = 23};
    person GianCosenzio = {.name = "GianCosenzio", .age = 26};
    person PierScafandro = {.name = "PierScafandro", .age = 74};
    person Carpuzio = {.name = "Carpuzio", .age = 546};
    person Tirillo = {.name = "Tirillo", .age = 343};
    person Caterenzio = {.name = "Caterenzio", .age = 59};
    person Germano = {.name = "Germano", .age = 63};
    person gukwrrrrilo = {.name = "Esiodo", .age = 74};
    person Dimastenide = {.name = "Dimastenide", .age = 64};
    person Gianpietralbo = {.name = "Gianpietralbo", .age = 32};
    person Torosauro = {.name = "Torosauro", .age = 32};
    person Arcamenistone = {.name = "Arcamenistone", .age = 28};
    person Gistlomenide = {.name = "Gistlomenide", .age = 88};
    person PierParmenide = {.name = "PierParmenide", .age = 78};
    // printf("Bernardello -> %u\n",hash("Bernardello"));
    addToTableClosed(&Bernardello);
    addToTableClosed(&Apollonio);
    addToTableClosed(&Sirio);
    addToTableClosed(&Claudiano);
    addToTableClosed(&Prepuzio);
    addToTableClosed(&Caruggio);
    addToTableClosed(&Ginepro);
    addToTableClosed(&Settimio);
    addToTableClosed(&Gisualdo);
    addToTableClosed(&Posentano);
    addToTableClosed(&Consenzio);
    addToTableClosed(&Tarminide);
    addToTableClosed(&Catamarano);
    addToTableClosed(&Presenzio);
    addToTableClosed(&Priminio);
    addToTableClosed(&GianCosenzio);
    addToTableClosed(&PierScafandro);
    addToTableClosed(&Carpuzio);
    addToTableClosed(&Tirillo);
    addToTableClosed(&Caterenzio);
    addToTableClosed(&Germano);
    addToTableClosed(&gukwrrrrilo);
    addToTableClosed(&Dimastenide);
    addToTableClosed(&Gianpietralbo);
    addToTableClosed(&Arcamenistone);
    addToTableClosed(&Gistlomenide);
    // printf("Index: %i\n", hash("Caruggio"));
    print_table();
    // hash_table_delete("Prepuzio");
    // deletePerson((&Prepuzio)->name);
    // print_table();
    // printf(" %p\n", DELETED);
    // printf(" %i\n", hash_table_lookup(&Apollonio));
    hash_table_lookup(&PierParmenide);
    hash_table_lookup(&Gistlomenide);
}
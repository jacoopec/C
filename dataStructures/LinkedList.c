#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

typedef struct node_t{
    int value;
    int* next;
}node_t;

typedef struct Head{
    node_t* next;
}Head;

node_t* insert_at_had(node_t* head, node_t* node_to_insert){
    node_to_insert-> next = head;
    return node_to_insert;
}

void printlist(Head head){
    printf("Head\n");
    node_t* temp = &head;
    while(temp->next != NULL){
        printf("-> %i ", *(temp->next));
    }
    printf("NULL\n");
}

node_t* create_new_node(int value){
    node_t* result = malloc(sizeof(node_t));
    result->value = value;
    return result;
}

int main(){
    Head head;
    //////////
    node_t n1;
    n1.value = 24;
    n1.next = NULL;
    head.next = &n1;
    printlist(head);
    ///////////
    // n2.value = 34;
    // n2.next = &n1;
    // n3.value = 21;
    // n3.next = &n2;

    // for(int i = 0; i < 4; i++){
    //     tmp = create_new_node(1);
    //     tmp-> next = head;
    //     head = tmp;
    // }


    printlist(head);
    return 0;
}
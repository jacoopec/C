#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

node_t* head = NULL;
node_t* tail = NULL;


typedef struct node_t{
    int value;
    int* next;
    int* previous;
}node_t;



node_t* insert_at_had(node_t* head, node_t* node_to_insert){
    node_to_insert-> next = head;
    return node_to_insert;
}

void printlist(node_t head){
    printf("Head\n");
    node_t* temp = &head;
    while(temp->next != NULL){
        printf("-> %i ", *(temp->next));
    }
    printf("NULL\n");
}

node_t* create_new_node(int value, node_t* next, node_t* previous){
    node_t* result = malloc(sizeof(node_t));
    if(previous == NULL){
        head = result;
        result->previous = NULL;
    } else {
        result->previous = NULL;
    }
    if (next == NULL){
        tail = result;
    }
    result->value = value;
    return result;
}

int main(){

    node_t* uno = create_new_node(1, NULL, NULL);
    
    node_t* uno = create_new_node(1, NULL, &uno);
    return 0;
}
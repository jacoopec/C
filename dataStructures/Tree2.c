#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

typedef struct treeNode{
    int value;
    struct tree *left;
    struct tree *right;
}treeNode;

treeNode* createNode(int value){
    treeNode* result = malloc(sizeof(treeNode));
    if(result != NULL){
        result->left  = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printTabs(treeNode* root, int numbtabs){
    for(int i = 0; i < numbtabs; i++){
        printf("\t");
    }
}

void printTree(treeNode* root){
    if(root == NULL){
        printf("----<empty>---\n");
        return;
    }
    printf("value= %d\n", root->value);

}

int main(){ 
    treeNode* n1 = createNode(1); 
    treeNode* n2 = createNode(2); 
    treeNode* n3 = createNode(2); 
    treeNode* n4 = createNode(2); 
    treeNode* n5 = createNode(3); 
    treeNode* n6 = createNode(4); 
    treeNode* n7 = createNode(5); 
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);
}
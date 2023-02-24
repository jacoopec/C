#include "cheaders.h"

typedef struct treenode{
    int value;
    treenode *left;
    treenode *right;
} treenode;


treenode* createNode(int value){
    treenode* result = (treenode*)malloc(sizeof(treenode));
    if (result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printTabs(int nTabs){
    for(int i = 0; i< nTabs; i++){
        printf("\t");
    }
}

void printTreeRec(treenode* root, int level){

    if(root == NULL){
        printTabs(level);
        printf("empty");
        return;
    }

    printTabs(level);
    printf("value = %d\n ", (root->value));
    printTabs(level);
    printf("Left\n ");
    printTreeRec(root->left, level+1);
    printTabs(level);
    printf("Right\n ");
    printTreeRec(root->right, level+1);
    printTabs(level);
    
}



void prova(treenode* node, int level){
    if(node->left != NULL){
        level++;
        printf("left\n");
        prova(node->left,level);
        // return;
    }

    if(node->right != NULL){
        level++;
        printf("right\n");
        prova(node->right,level);
        // return;
    }
    printf("level: %i \n", level);
    level--;
    // return;
}

void printTree(treenode* root){
    printTreeRec(root,0);
}

int main(){
    treenode* n1 = createNode(10);
    treenode* n2 = createNode(1);
    treenode* n3 = createNode(3);
    treenode* n4 = createNode(5);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;

    printTree(n1);
    prova(n1,0);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
}
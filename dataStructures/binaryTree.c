#include "../cheaders.h"

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

bool insertNumber(treenode** rootptr, int value){
    treenode* root = *rootptr;

    if(root == NULL){
        (*rootptr) = createnode(value);
        return true;
    }
    if(value == root->value){
        return false;
    }
    if(value < root->value){
        return insertNumber(&(root->left), value);
    } else {
        return insertNumber(&(root->right), value);
    }
}

bool findNumber(treenode* root, int value){
    if(root == NULL) return false;
    if(root->value == value){
        return true;
    }
    if(value < root->value){
        return findNumber(root->left,value);
    } else {
        return findNumber(root->right,value);
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
    treenode* root = NULL;

    insertNumber(&root, 12);
    insertNumber(&root, 21);
    insertNumber(&root, 43);
    insertNumber(&root, 4);
    insertNumber(&root, 1);

    printf("%d (%d)\n", 16, findNumber(root, 16));
    printf("%d (%d)\n", 21, findNumber(root, 21));
    printf("%d (%d)\n", 16, findNumber(root, 16));
}
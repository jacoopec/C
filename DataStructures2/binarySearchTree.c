#include "../CHeaders.h"
//searched tree can be used with any type that can be ordered.

typedef struct treenode{
    int val;
    struct treenode* left;
    struct treenode* right;
} treenode;

treenode* createNode(int value, treenode* left, treenode* right){
    treenode* result = malloc(sizeof(treenode));
    if(result != NULL){
        result->left = left;
        result->right = right;
        result->val = value;
    }
    return result;
}

void print(treenode* node){
    treenode* leftNode = NULL;
    treenode* rightNode = NULL;
    printf("Node: %i \n", node->val);
    while((node->left != NULL) || (node->right != NULL)){
        if(node->left != NULL){
            printf("\t left: %i \n",node->left->val);
            leftNode = node->left->val;
            print(node->left);
        }
        if(node->right != NULL){
            printf("\t right: %i \n",node->right->val);
            rightNode = node->right->val;
            print(node->right);
        }

    }
    return;
}


bool insertNumber(treenode** rootPtr, int value){
    treenode* root = *rootPtr;
    if(root == NULL){
        (*rootPtr) = createNode(value, (*rootPtr)->left,(*rootPtr)->right);
        return true;
    }
    if(value == root->val){
        return false;
    }
    if(value < root->val){
        return insertNumber(&(root->left), value);
    } else {
        return insertNumber(&(root->right), value);
    }
}

bool findNumber(treenode* root, int value){
    if(root == NULL){ return false;}
    if(value == root->val){
        return true;
    }
    if(value < root->val){
        return findNumber(root->left, value);
    } else {
        return findNumber(root->right, value);
    }
}

int main(){
    treenode* n7 = createNode(70,NULL,NULL);
    treenode* n6 = createNode(60,NULL,NULL);
    treenode* n5 = createNode(50,NULL,NULL);
    treenode* n4 = createNode(40,n7,NULL);
    treenode* n3 = createNode(30,n6,NULL);
    treenode* n2 = createNode(20,n4,n5);
    treenode* n1 = createNode(10,n2,n3);
    print(n1);
    // int a = 1;        //si può cambiare il valore numerico
    // int* ip = &a;     //si può cambiare l'indirizzo che punta ad a
    // int** i2p = &ip; // si può cambiare l'indirizzo, dell'indirizzo che punta ad a.

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);

}
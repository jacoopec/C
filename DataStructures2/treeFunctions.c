#include "tree.h"


Node* createNode(int value, Node* left, Node* right){
    Node* result = malloc(sizeof(Node));
    if(result != NULL){
        result->left = left;
        result->right = right;
        result->val = value;
    }
    return result;
}

void print(Node* node, unsigned int level){
    level++;
    printf("Node: %i ", node->val);
    for(int i = 0; i < level; i++){
        printf("\t");
    }
    if(node->left != NULL){
        printf("\t left: %i ",node->left->val);
        print(node->left,level);
    }
    if(node->right != NULL){
        printf("\t right: %i",node->right->val);
        print(node->right, level);
    }
    return;
}

void print2(Node* node, unsigned int level){
    level++;
    if(node->left != NULL){
        print2(node->left,level);
    }
    if(node->right != NULL){
        print2(node->right, level);
    }
    for(int i = 0; i < level; i++){
        printf("\t");
    }

    printf("Node: %i ", node->val);
    return;
}

void printTree(Node* root){
    if(root == NULL){
        printf("------Empty tree");
        return;
    }
    print(root,0);

}


void completePrinting(Node* root, unsigned int level){
    for(int l = level; l > 0; l--){
        printf("\t");
    }
    if(root != NULL && level > 0){
        printf("\n");
        printf("\n");
        level--;
        if(root->left != NULL){
            completePrinting(root->left,level);
        }
        if(root->right != NULL){
            completePrinting(root->right,level);
        }
        return;
    } else {
        printf("NULL");
        return;
    }
}

bool isEmptyTree(const Node *n){
    if(n == NULL){
        return true;
    } else {
        return false;
    }
}


bool treeIsLeaf(const Node *n){
    return (leftTree(n) == NULL && rightTree(n) == NULL);
}

//visita gli alberi sinistro e destro ricorsivamente. la radice viene analizzata prima della visita dei sottoalberi
void preOrderVisitBinary(Node* root){
    if(root != NULL){
        printf("%i\t", root->val);
        preOrderVisitBinary(root->left);
        preOrderVisitBinary(root->right);
    }
    else{
        printf("-L.\t");
    }
}

void preOrderVisitBinaryPrint(Node* root, int levels, int depth){
    if(root != NULL){
        if(depth == 0){
                for(int y = 0; y < levels; y++){
                    printf("\t");
                }
                printf("%i\n", root->val);
        } else {
            for(int r = 2^depth; r > 0; r--){
                for(int y = 0; y < levels; y++){
                    printf("\t");
                }
            }
        }
        printf("%i\t", root->left->val);
        for(int y = 0; y > levels/2; y--){
            printf("\t");
        }
        printf("%i\n", root->right->val);
        preOrderVisitBinaryPrint(root->left,levels/2,depth++);
        preOrderVisitBinaryPrint(root->right,levels/2, depth++);
    }
    else{
        printf("-L.\t");
    }
}

void inOrderVisitBinary(Node* root){
    if(root != NULL){
        preOrderVisitBinary(root->left);
        printf("%i\n", root->val);
        preOrderVisitBinary(root->right);
    }
    else{
        printf("Leaf\n");
    }
}

//analizza gli n sottoalberi di un nodo
void preOrderVisit(Node* root, const int n){
    if(root != NULL){
        printf("%i\n", root->val);
        for(int j = 0; j < n; j++){
            preOrderVisit(root->right, n);
        }
    }
    else{
        printf("Leaf\n");
    }
}
 
//i sottoalberi sono analizzati prima del nodo.
void postOrderVisitBinary(Node* root){
    if(root != NULL){
        postOrderVisitBinary(root->left);
        postOrderVisitBinary(root->right);
        printf("%i\n", root->val);
    }
    else{
        printf("Leaf\n");
    }
}

//visita in ampiezza
void breathSearch(Node* root, int levels){
    printf("\n");
    if(root != NULL){
        for(int y = levels; y > 0; y--){
            printf("\t");
        }
        printf("%i", root->val);
        breathSearch(root->left,levels-1);
        printf("\t");
        breathSearch(root->right,levels-1);
    } else {
        printf("Leaf\n");
    }
}

int elemCompare(ElemType one, ElemType two){
    return(one > two) - (one < two);
}

Node* createEmptyTree(void){
    printf("Empty tree created.\n");
    Node* root = malloc(sizeof(Node));
    return root;
}

Node* createTree(ElemType e, Node *l, Node *r){
    Node *result = malloc(sizeof(Node));
    result->val = e;
    result->left = l;
    result->right = r;
    return result;
}

const ElemType* getRootValueTree(const Node *n){
    if(isEmptyTree(n)){
        printf("Tree empty\n");
    } else {
        return n->val;
    }
}

Node *root(const Node * n){
    if(isEmptyTree(n)){
        printf("Tree empty\n");
    } else {
        return n;
    }
}

Node *leftTree(const Node * n){
    if(isEmptyTree(n)){
        printf("Tree empty\n");
    } else {
        return n->left;
    }
}

Node *rightTree(const Node * n){
    if(isEmptyTree(n)){
        printf("Tree empty\n");
    } else {
        return n->right;
    }
}

void deleteTree(Node *n){
    printf("Deleting %i\n", n->val);
    if(n->left != NULL){
        deleteTree(n->left);
    }
    if(n->right != NULL){
        deleteTree(n->right);
    }
    free(n);
}


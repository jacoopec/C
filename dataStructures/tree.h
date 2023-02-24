#include "../CHeaders.h"
#pragma once
#ifndef treeH
#define treeH

typedef int ElemType;
typedef struct Node{
    ElemType val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value, Node* left, Node* right);
void print(Node* node, unsigned int level);
void print2(Node* node, unsigned int level);
void printTree(Node* root);
void completePrinting(Node* root, unsigned int level);
bool isEmptyTree(const Node *n);
bool treeIsLeaf(const Node *n);
void preOrderVisitBinary(Node* root);
void inOrderVisitBinary(Node* root);
void preOrderVisit(Node* root, const int n);
void postOrderVisitBinary(Node* root);
void preOrderVisitBinaryPrint(Node* root, int levels, int depth);
void breathSearch(Node* root, int levels);
int elemCompare(ElemType one, ElemType two);
Node* createEmptyTree(void);
Node* createTree(ElemType e, Node *l, Node *r);
const ElemType* getRootValueTree(const Node *n);
Node *root(const Node * n);
Node *leftTree(const Node * n);
Node *rightTree(const Node * n);
void deleteTree(Node *n);

#endif
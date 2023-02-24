#include "../CHeaders.h"

typedef struct Node{
    int val;
    void* next; 
} Node;


void print(Node* n){
    while(n != NULL){
        printf("%i \n",n->val);
        print(n->next);
        return;
    }
    return;
}


// int SumNotWork(Node* n, int sum){
//     while(n != NULL){
//         sum += n->val;
//         printf("Sum before: %i \n",sum);
//         Sum(n->next, sum);
//         printf("Sum next: %i \n",sum);
//         return sum;
//     }
//     return sum;
// }

int Sum(Node* n){
    int S = 0;
    while(n != NULL){
        S = Sum(n->next);
        S += n->val;
        printf("Sum: %i \n",S);
        return S;
    }
    return S;
}

bool find(Node* node, int goal){
    bool found = false;
    printf("node: %p\n", node);
    while(node != NULL){
        if(node->val == goal){
            found = true;
            return found;
        } else {
            found = find(node->next, goal);
            return found;
        }
    }
    return found;
}

Node* reverse(Node* n){
    Node* current = n;           //current è A
    Node* nextNode = n->next;  //salvo B
    current->next = NULL;     //cambio il puntatore next di A

    while(nextNode != NULL){
        current->next = current;         // cambio il puntatore di B
        printf("Current: %i %p Next: %i %p\n", current->val, current, nextNode->val, nextNode);
        current = nextNode;         //current è B
        nextNode = nextNode->next;  //salvo C come prossimo puntatore
    }
    printf("%p", current);
    return &current;
}

int main(){
    Node quattro = {.val = 4, .next = NULL};
    Node tre = {.val = 3, .next = (Node*)&quattro};
    Node due = {.val = 2, .next = (Node*)&tre};
    Node uno = {.val = 1, .next = (Node*)&due};
    print(&uno);
    int sum = 0;
    printf("------------------\n");
    printf("Sum: %i\n", Sum(&uno));
    printf("------------------\n");
    printf("Found 2: %i\n", find(&uno, 8));
    printf("------------------\n");
    Node* n = reverse(&uno);
    print(n);

}
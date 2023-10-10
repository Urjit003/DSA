#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    Node *prev;
    int data;
    Node *next;
}Node;
int main() {
    Node *head=(Node *)malloc(sizeof(Node));
    head->prev = NULL;
    head->data = 10;
    head->next = NULL;
    if(head) {
        printf("doubly LL head node created succssfully \n");
    }
return 0 ;
}
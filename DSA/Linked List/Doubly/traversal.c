#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    Node *prev;
    int data;
    Node *next;
}Node;
void Travese(Node *head) {
    // Traversal of doubly LL 
    Node *p = head;
    while (p != NULL)
    {
        printf("%s%1d%s ",(p->prev == NULL) ? "NULL<-": "<-" ,p->data
                          ,(p->next == NULL) ? "->NULL" : "->" );
        p= p->next;
    }
    
}
int main() {
    Node *head=(Node *)malloc(sizeof(Node));
    Node *sec=(Node *)malloc(sizeof(Node));
    head->prev = NULL;
    head->data = 10;
    head->next = sec;

    sec->prev = head;
    sec->data = 20;
    sec->next = NULL;
    Travese(head);
return 0 ;
}
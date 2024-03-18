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
        printf("%s%1d%s",(p->prev == NULL) ? "NULL_<-": "<-" ,p->data
                          ,(p->next == NULL) ? "->_NULL" : "->" );
        p= p->next;
    }
    
}
Node *AddAtBegin(Node *head ,int data){
    // create PTR
    Node * ptr = (Node *)malloc(sizeof(Node));
    ptr->data =data;
    ptr->next = head;
    head->prev = ptr;
    ptr->prev = NULL;
    head = ptr;
    return head;
}
Node *DeleteAtNode(Node *head) {
    Node *p = head;
    int target;
    Travese(head);
    printf("\nEnter the Node to delete(Give data of the node)\n");
    scanf("%d",&target);
    while (p->data != target)
    {
        p=p->next;
    }
    p->prev->next = p->next;
    p->next = p->prev;
    free(p);
    return head;
}
Node *DeleteEndNode(Node *head) {
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);
    return head;

}
int main() {
    Node *head=(Node *)malloc(sizeof(Node));
    Node *sec=(Node *)malloc(sizeof(Node));
    head->prev = NULL;
    head->data = 1;
    head->next = NULL;

   for (int i = 2; i <= 10; i++)
   {
    head = AddAtBegin(head, i);
   }
   head = DeleteEndNode(head);
    Travese(head);
return 0 ;
}
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    struct  Node *prev;
    int data;
    struct  Node *next;
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
    printf("\n");
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
Node *AddAtEnd(Node *head , int data) {
    Node *p = head , *ptr = (Node *)malloc(sizeof(Node));
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;
    return head;
}
Node *AddBeforeNode (Node *head , int data) {
    Node *p = head;
    int target;
    Node *ptr =(Node *) malloc(sizeof(Node));
    ptr->data = data;
    Travese(head);
    printf("\nEnter the data of node for the new node to be inserted before it\n");
    scanf("%d",&target);

    while (p->data != target && p != NULL)
    {
        p=p->next;

    }
    ptr->next = p;
    ptr->prev = p->prev;
    ptr->prev->next = ptr;

    // DELET THESE lines
    // printf("%x\n",p->prev);
    // printf("%x\n",p->prev->prev);
    // printf("%x\n",p);

    p->prev = ptr;
    // ptr->next = p;

    return(head);
}
int main() {
    Node *head=(Node *)malloc(sizeof(Node));
    Node *sec=(Node *)malloc(sizeof(Node));
    head->prev = NULL;
    head->data = 1;
    head->next = NULL;

   for (int i = 2; i <= 10; i++)
   {
    head = AddAtEnd(head, i);
   }
   head = AddBeforeNode(head, 11);
    Travese(head);
    Travese(head);
    Travese(head);
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

return 0 ;
}
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
typedef struct node {
    struct node *prev , *next ;
    int data;
}node;
node *AddAtEnd(node *head , int data) {
    node *p = head;
    node * ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->prev = p;
    p->next = ptr;
    ptr->next = NULL;

    return head;
}
void traversal(node *head) {
    node *p = head;
    while (p!=NULL)
    {
        cout << (p->prev == NULL ? "" : "<-") << p->data <<(p->next == NULL ? "" : "->") ;
        p=p->next;
    }
    cout << endl;
}
node *DeleteBeforeTarget(node *head ) { 

    int target ;
    cout << "Give target node , the node before that will be deleted " ;
    cin >> target;

    node *p = head,*placeholder;
    while (p->data != target) {
        placeholder = p;
        p=p->next;
    }
    placeholder->prev->next = p;
    p->prev = placeholder->next;

    free(placeholder);
    traversal(head);
    return head;
} 
node *DeleteAfterTarget(node *head ) { 

    int target ;
    cout << "Give target node , the node after that will be deleted " ;
    cin >> target;

    node *p = head,*placeholder;
    while (p->data != target) {
        p=p->next;
    }
    placeholder = p->next;

    p->next = placeholder->next;
    placeholder->next->prev= p;
    free(placeholder);
    traversal(head);
    return head;
} 
int main (){
    node * head = (node *)malloc(sizeof(node));
    head->prev = NULL;
    head->data = 0 ;
    head->next = NULL;

    for (int i = 1; i <= 10; i++)
    {
        head = AddAtEnd(head ,i);
    }
    traversal(head);
    head = DeleteAfterTarget(head);
return 0;
}
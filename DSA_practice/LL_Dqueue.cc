#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
template <typename T>
class node
{
    node *prev, *next;

    T data;

public:
    node(T data) : data(data) ,prev(NULL) ,next (NULL){}
    node() { this->data = 0; }
    node *AddAtEnd(node *head, T data)
    {
        node *p = head ;
        node *ptr= new node(data);

        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;

        ptr->next = NULL;
        ptr->prev = p ;
        return head;
    }
    void Traversal(node *head)
    {
        node *p = head;
        while (p != NULL)
        {
            cout << ((p->prev == NULL) ? "NULL<-" : "<-")
                 << p->data 
                 << ((p->next == NULL) ? "->NULL" : "->");
            p = p->next;
        }
        cout << endl;
    }
    
    node *DeleteTarget(node *head) {
        
    }
};
int main()
{
    node<int> *head = new node(1);
    for (int i = 2; i <= 100; i++)
    {
        head = head->AddAtEnd(head, i);
    }
    head->Traversal(head);

    return 0;
}
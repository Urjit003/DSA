#include <iostream>
#include <stdlib.h>
using namespace std;
class LL
{
    int data;
    LL *next;

public:
    LL(int data, LL *next = NULL) {
        this->data = data ;
        this->next = next;
    }
    void Traverse(LL *head)
    {
        while (head != NULL)
        {
            printf("[%d]%s", head->data, (!head->next) ? "NULL" : "->");
            head = head->next;
        }
        printf("\n");
    }
    LL *AddToBegin(LL *head , int data) {
        LL *ptr = new LL(data);
        ptr->next = head;
        return ptr;
    }
    LL *AddToEnd(LL *head , int data) {
        LL *ptr = new LL(data);
        LL *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = NULL;
        return head;
    }
    LL *DeleteATBegin(LL *head) {
        head = head->next ;
        return head;
        free(head);
    }
};
 int main()
{
    int m= 10;
    LL *head =new LL(m);
    for (int i = 1; i < 10; i++)
    {
        m +=10;
        head = head->AddToEnd(head , m);
    }
        head = head->DeleteATBegin(head); //10
    head->Traverse(head);
    return 0;
}
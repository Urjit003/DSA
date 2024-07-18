#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long int
#define vi vector<ll>
#define pb emplace_back
#define logarr(arr,a,b) for(int i = (a); i <= (b); i++) cout << (arr[i]) << ""; cout << endl;
void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
void swap(int *a, int* b) {int c = *a ; *a=*b; *b = c;}
class Node {
    public :
        int data ;
        Node* next ;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
        friend void free_Node(Node *node) ;
};
  
class SinglyLinkedList  {
    private :
        Node *head;

    public :
    void free_Node(Node *node) {
        while(node) {
            Node* temp = node ;
            node = node->next;
            delete (temp); }
        }

    ~SinglyLinkedList() {
        free_Node(head);
    }
    SinglyLinkedList() {
        head = nullptr;
    }
    void insertAtHead(int data) {
        Node *ptr = new Node(data);
        if(head == nullptr) {
            head = ptr; 
            return ;
        }
        ptr->next = head;
        head = ptr ;
    }
    void insertAtEnd(int data) {
        Node* ptr = new Node(data);
        if (head == nullptr) { // Handle empty list case
          head = ptr;
          return;
        }
        Node* p = head;
        while (p->next != nullptr) {
          p = p->next;
        }
        p->next = ptr;
        ptr->next = nullptr;
    }
     void sort_list() {
        Node *p = head;
        Node *next_node = p;
        while (p != nullptr) {
            next_node = p->next;
            while(next_node != nullptr) {
                if(p->data > next_node->data) {
                    swap(&p->data,&next_node->data);
                }
                next_node= next_node->next; 
            }
            p=p->next;
        }
    }
    void insertData(int data) {
        sort_list();
        Node *p = head;
        Node *prev = new Node(data);
        while(p != nullptr) {
            prev = p ;
            p=p->next;

            if(p->data > data) {
                prev->next = p;
            }
        }
    }
    void traverse() {
        Node *p = head; 
        while(p != nullptr) {
            cout << p->data << (p->next ? "->" : "->NULL") ;
            p = p->next;
        }
        cout << "\n";
    }

    
};
int main()
{
    file_i_o();
    SinglyLinkedList head;

    ll t ;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        head.insertAtEnd(n);
    }
    cout << "Linked List before sorting : " << '\n';
    // head.sort_list();
    head.traverse();
    cout << "Linked List : " << '\n';
    head.insertData(-11);
    head.traverse();
    return 0;
}
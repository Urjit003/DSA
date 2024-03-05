#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
template <typename T> class Node {
    public:
        T data;
        Node *next;
    Node(T data) : data(data) , next(nullptr) {}
};

template <typename T> class LinkedList {
    Node<T> *head;
    public:
    void push(T value) {
        Node<T> *newnode = new Node<T>(value);
        newnode->next = head;
        head = newnode;
    }
    void pop() {
        if(head) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        else {
            cerr << "STACK UNDERFLOW" << endl;
        }
    }
    bool isEmpty() {
        return top == nullptr;
    }
    T top() {
        if(head) {
            return head->data;
        }else {
            exit(1);
        }
    }
};
template<typename T> class Stack {
    LinkedList<T> ls;
    public:
    void push(T value) {
        ls.push(value);
    }
    void pop() {
        ls.pop();
    }
    bool isEmpty() {
        return ls.isEmpty();
    }
    T top() {
        return ls.top();
    }
} ;
int main (){
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    cout << s1.top() << " is the top element \n";

    s1.pop();


return 0;
}
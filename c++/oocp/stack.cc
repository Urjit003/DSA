#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        } else {
            std::cerr << "Stack underflow: Trying to pop from an empty stack." << std::endl;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    T top() const {
        if (head) {
            return head->data;
        } else {
            std::cerr << "Stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }
    }
};

template <typename T>
class Stack {
private:
    LinkedList<T> linkedList;

public:
    void push(T value) {
        linkedList.push(value);
    }

    void pop() {
        linkedList.pop();
    }

    bool isEmpty() const {
        return linkedList.isEmpty();
    }

    T top() const {
        return linkedList.top();
    }
};

int main() {
    Stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element: " << myStack.top() << std::endl;

    myStack.pop();
    std::cout << "Top element after pop: " << myStack.top() << std::endl;

    myStack.pop();
    myStack.pop(); // Trying to pop from an empty stack

    return 0;
}

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class Queue {
private:
    Node* head;

public:
    Queue() {
        head = nullptr;
    }
    void insertFront(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        display();
    }
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            display();
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;

        display();
    }

    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);

        if (position <= 1) {
            newNode->next = head;
            head = newNode;
            display();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        display();
    }

    void display() {
        Node* temp = head;

        cout << "Queue: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.insertEnd(101);
    q.insertEnd(102);
    q.insertFront(100);
    q.insertAtPosition(105, 3);
    q.insertAtPosition(103, 4);

    return 0;
}

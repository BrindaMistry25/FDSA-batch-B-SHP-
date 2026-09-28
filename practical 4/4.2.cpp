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
    }
    void insertEnd(int value) {
        Node* newNode = new Node(value);
if (head == nullptr) {
            head = newNode;
            return;
        }
Node* temp = head;
while (temp->next != nullptr) {
            temp = temp->next;
        }
temp->next = newNode;
    }
    void insertAtPosition(int value, int position) {
        if (position <= 1) {
            insertFront(value);
            return;
        }
Node* temp = head;
for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
if (temp == nullptr) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
Node* temp = head;
        while (temp->next != nullptr &&
               temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Patient token not found." << endl;
            return;
        }
        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }
    void displayForward() {
        Node* temp = head;
        cout << "Front to Back: ";
while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
    void displayReverse(Node* temp) {
        if (temp == nullptr)
            return;

        displayReverse(temp->next);
        cout << temp->data << " ";
    }
    void reversePrint() {
        cout << "Back to Front: ";
        displayReverse(head);
        cout << endl;
    }
};
int main() {
    Queue q;
    q.insertEnd(101);
    q.insertEnd(102);
    q.insertEnd(103);
    q.insertFront(100);
    q.insertAtPosition(105, 3);
    cout << "Initial Queue:" << endl;
    q.displayForward();
cout << "\nDeleting patient 102..." << endl;
    q.deleteByValue(102);
    q.displayForward();
    cout << "\nForward Traversal:" << endl;
    q.displayForward();
cout << "\nReverse Printing:" << endl;
    q.reversePrint();

    return 0;
}

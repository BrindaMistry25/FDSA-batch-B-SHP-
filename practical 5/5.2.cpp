#include <iostream>
using namespace std;
struct DNode {
    string name;
    DNode* prev;
    DNode* next;
DNode(string n) {
        name = n;
        prev = nullptr;
        next = nullptr;
    }
};
class DoublyCircular {
private:
    DNode* head;

public:
    DoublyCircular() {
        head = nullptr;
    }
    void join(string name) {
        DNode* newNode = new DNode(name);
if (head == nullptr) {
            head = newNode;

            newNode->next = head;
            newNode->prev = head;
        } else {
            DNode* tail = head->prev;

            newNode->next = head;
            newNode->prev = tail;

            tail->next = newNode;
            head->prev = newNode;
        }

        display();
    }
    void leave(string name) {
        if (head == nullptr) {
            cout << "Circle is empty!" << endl;
            return;
        }
DNode* current = head;
do {
            if (current->name == name)
                break;
            current = current->next;
} while (current != head);
        if (current->name != name) {
            cout << "Student not found!" << endl;
            return;
        }
        if (current->next == current) {
            delete current;
            head = nullptr;
            display();
            return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        if (current == head) {
            head = current->next;
        }
        delete current;
display();
    }
    void display() {
        if (head == nullptr) {
            cout << "Circle is empty!" << endl;
            return;
        }

        DNode* temp = head;

        cout << "Circle: ";

        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    DoublyCircular circle;

    circle.join("Alice");
    circle.join("Bob");
    circle.join("Charlie");
    circle.join("David");

    circle.leave("Charlie");
    circle.leave("Alice");

    return 0;
}

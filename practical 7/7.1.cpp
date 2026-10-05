#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int n;
    int front, rear, count;

public:
    Queue(int size) {
        n = size;
        arr = new int[n];
        front = 0;
        rear = 0;
        count = 0;
    }

    void join(int token) {
        if (count == n) {
            cout << "Error: Queue is full" << endl;
            return;
        }

        arr[rear] = token;
        rear = (rear + 1) % n;
        count++;

        printFront();
    }

    void serve() {
        if (count == 0) {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        front = (front + 1) % n;
        count--;

        printFront();
    }

    void printFront() {
        if (count == 0)
            cout << "Front: Empty" << endl;
        else
            cout << "Front: " << arr[front] << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Queue q(n);

    int operations;
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        char operation;
        cin >> operation;

        if (operation == 'J') {
            int token;
            cin >> token;
            q.join(token);
        }
        else if (operation == 'S') {
            q.serve();
        }
    }

    return 0;
}
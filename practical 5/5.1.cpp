#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
Node(string s) {
        song = s;
        prev = nullptr;
        next = nullptr;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = nullptr;
        tail = nullptr;
    }
    void addBeginning(string song) {
        Node* newNode = new Node(song);
if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
display();
    }
    void addEnd(string song) {
        Node* newNode = new Node(song);
if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        display();
    }
    void insertAfter(string givenSong, string newSong) {
        Node* temp = head;
        while (temp != nullptr && temp->song != givenSong) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Song not found!" << endl;
            return;
        }
        Node* newNode = new Node(newSong);
newNode->prev = temp;
        newNode->next = temp->next;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }
        temp->next = newNode;
display();
    }
    void removeFirst() {
        if (head == nullptr) {
            cout << "Playlist is empty!" << endl;
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;

        display();
    }
    int countSongs() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }
    void display() {
        Node* temp = head;

        cout << "Playlist: ";

        while (temp != nullptr) {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << endl;
        cout << "Song count: " << countSongs() << endl;
    }
};

int main() {
    Playlist p;

    p.addEnd("Song A");
    p.addEnd("Song B");
    p.addBeginning("Song X");
    p.insertAfter("Song A", "Song C");
    p.removeFirst();

    return 0;
}

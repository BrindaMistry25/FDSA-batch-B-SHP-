#include <iostream>
using namespace std;
struct Node
{
    string page;
    Node* next;
};
void visit(Node*& top, string page)
{
    Node* newNode = new Node;
    newNode->page = page;
    newNode->next = top;
    top = newNode;
}
void back(Node*& top)
{
    if (top == NULL)
    {
        cout << "No previous page.\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}
void display(Node* top)
{
    if (top == NULL)
    {
        cout << "No page open.\n";
        return;
    }
    cout << "Current page: " << top->page << endl;
}
int main()
{
    Node* top = NULL;
    int choice;
    string page;
    do
    {
        cout << "\n--- BROWSER HISTORY ---\n";
        cout << "1. Visit page\n";
        cout << "2. Back\n";
        cout << "3. Display current page\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter page name: ";
            cin >> page;
            visit(top, page);
            display(top);
            break;
        case 2:
            back(top);
            display(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            cout << "Program ended.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}

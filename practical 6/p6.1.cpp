#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter stack capacity: ";
    cin >> n;
    int stack[n];
    int top = -1;
    int choice, value;
    do
    {
        cout << "\n--- TRAY STACK ---\n";
        cout << "1. Place tray\n";
        cout << "2. Take tray\n";
        cout << "3. Display top tray\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (top == n - 1)
            {
                cout << "Error: Stack is full. Cannot place tray.\n";
            }
            else
            {
                cout << "Enter tray number: ";
                cin >> value;
                top++;
                stack[top] = value;
                cout << "Tray placed successfully.\n";
                cout << "Current top tray: " << stack[top] << endl;
            }
            break;
        case 2:
            if (top == -1)
            {
                cout << "Error: Stack is empty. Cannot take tray.\n";
            }
            else
            {
                cout << "Tray taken: " << stack[top] << endl;
                top--;
                if (top != -1)
                    cout << "Current top tray: " << stack[top] << endl;
                else
                    cout << "Stack is now empty.\n";
            }
            break;
        case 3:
            if (top == -1)
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                cout << "Current top tray: " << stack[top] << endl;
            }
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

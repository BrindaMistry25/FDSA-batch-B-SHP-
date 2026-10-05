#include <iostream>
using namespace std;

int main() {
    int table[10];
    for (int i = 0; i < 10; i++) {
        table[i] = -1;
    }

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int registration;
        cin >> registration;
        int index = registration % 10;
        int start = index;
        while (table[index] != -1) {
            index = (index + 1) % 10;
            if (index == start) {
                cout << "Error: Parking lot is full" << endl;
                break;
            }
        }
        if (table[index] == -1) {
            table[index] = registration;
        }
    }
    cout << "\nFinal parking lot:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}
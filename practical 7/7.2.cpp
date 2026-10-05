#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> patients;

    int operations;
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        char operation;
        cin >> operation;

        if (operation == 'A') {
            int patient;
            cin >> patient;

            patients.push(patient);

            if (!patients.empty())
                cout << "Front: " << patients.front() << endl;
        }
        else if (operation == 'T') {
            if (patients.empty()) {
                cout << "Error: Ward is empty" << endl;
            }
            else {
                patients.pop();

                if (patients.empty())
                    cout << "Front: Empty" << endl;
                else
                    cout << "Front: " << patients.front() << endl;
            }
        }
    }

    return 0;
}
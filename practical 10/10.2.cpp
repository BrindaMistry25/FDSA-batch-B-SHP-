#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> shelf[10];

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int code;
        cin >> code;
        int index = code % 10;
        shelf[index].push_back(code);
    }
    cout << "\nFinal shelf contents:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        if (shelf[i].empty()) {
            cout << "Empty";
        }
        else {
            for (int book : shelf[i]) {
                cout << book << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
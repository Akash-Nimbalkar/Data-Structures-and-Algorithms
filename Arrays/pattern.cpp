#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter any n" << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || i + j == n - 1) {
                cout << j + 1 << " ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }

    return 0;
}

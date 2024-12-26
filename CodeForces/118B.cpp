#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            cout << "  ";
        }
        for (int j = 0; j <= n - i; j++) {
            cout << j;
            if (j != n - i) cout << " ";
        }
        for (int j = n - i - 1; j >= 0; j--) {
            cout << " " << j;
        }
        cout << endl;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - i - 1; j >= 0; j--) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << j;
            if (j != i) cout << " ";
        }
        for (int j = i - 1; j >= 0; j--) {
            cout << " " << j;
        }
        cout << endl;
    }

    return 0;
}

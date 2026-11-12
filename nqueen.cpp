#include <iostream>
#include <cstdlib>
using namespace std;

int x[20];
int n;

bool place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void nqueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;

            if (k == n) {
                for (int j = 1; j <= n; j++) {
                    cout << x[j] << " ";
                }
                cout << endl;
            }
            else {
                nqueens(k + 1, n);
            }
        }
    }
}

int main() {
    cout << "Enter no. of queens: ";
    cin >> n;

    if (n < 1 || n > 19) {
        cout << "Enter n between 1 and 19.";
        return 0;
    }

    cout << "Solutions:\n";
    nqueens(1, n);

    return 0;
}
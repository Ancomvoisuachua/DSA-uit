#include <iostream>
using namespace std;

int main() {
    int n, a[100];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        int x = a[i];
        int j = i - 1;

        while (j >= 0 &&
            (abs(a[j]) > abs(x) ||
                (abs(a[j]) == abs(x) && a[j] > x))
            ) {

            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << a[i];
    }

    return 0;
}
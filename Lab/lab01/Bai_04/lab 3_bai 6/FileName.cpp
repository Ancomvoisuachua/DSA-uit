#include <iostream>
using namespace std;

void inMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Cai dat quick sort tang dan.
// Moi lan co swap lam mang thay doi thi in ra mang.
void quickSort(int a[], int left, int right, int n) {
    int x = a[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;

        if (i <= j) {
            if (i != j && a[i] != a[j]) {
                swap(a[i], a[j]);
                inMang(a, n);
            }
            i++; j--;
        }
    }

    if (left < j) {
        quickSort(a, left, j, n);
    }
    if (i < right) {
        quickSort(a, i, right, n);
    }
}

int main() {
    int n;
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1, n);

    return 0;
}
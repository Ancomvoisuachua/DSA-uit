#include <iostream>
using namespace std;

void inMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int timViTriChen(int a[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}

// Cai dat binary insertion sort tang dan.
// Moi lan mang thay doi thi in ra mang.
void binaryInsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int pos = timViTriChen(a, 0, i - 1, x);

        if (pos != i) {
            for (int j = i; j > pos; j--) {
                a[j] = a[j - 1];
                inMang(a, n);
            }
            a[pos] = x;
            inMang(a, n);
        }
    }
}

int main() {
    int n;
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    binaryInsertionSort(a, n);
    return 0;
}

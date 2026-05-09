#include <iostream>
using namespace std;

void inMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Cai dat heap sort tang dan.
// Moi lan co swap thi in ra mang
void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        int root = i;
        while (true) {
            int max_id = root;
            int left = 2 * root + 1;
            int right = left + 1;

            if (left < n && a[max_id] < a[left]) max_id = left;
            if (right < n && a[max_id] < a[right]) max_id = right;

            if (max_id != root) {
                swap(a[max_id], a[root]);
                inMang(a, n);
                root = max_id;            }
            else break;
        }

    }

    for (int i = n - 1; i >= 1; i--) {
        swap(a[0], a[i]);
        inMang(a, n);
        int root = 0;
        int Size = i;

        while (true) {
            int max_id = root;
            int left = 2 * root + 1;
            int right = left + 1;

            if (left < Size && a[max_id] < a[left]) max_id = left;
            if (right < Size && a[max_id] < a[right]) max_id = right;

            if (max_id != root) {
                swap(a[max_id], a[root]);
                inMang(a, n);
                root = max_id;
            }
            else break;
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

    heapSort(a, n);
    return 0;
}

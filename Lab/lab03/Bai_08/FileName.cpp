#include <iostream>
using namespace std;

void inMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int timMax(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > mx) {
            mx = a[i];
        }
    }
    return mx;
}

bool countingSortTheoChuSo(int a[], int n, int exp) {
    int output[10000];
    int dem[10] = { 0 };

    for (int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 10;
        dem[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        dem[i] += dem[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[dem[digit] - 1] = a[i];
        dem[digit]--;
    }

    bool changed = false;
    for (int i = 0; i < n; i++) {
        if (a[i] != output[i]) {
            changed = true;
        }
        a[i] = output[i];
    }
    return changed;
}

// Cai dat radix sort tang dan.
// Moi luot theo chu so neu mang thay doi thi in ra mang.
void radixSort(int a[], int n) {
    int m = timMax(a, n); 
    for (int exp = 1; m / exp > 0; exp *= 10) {
        if (countingSortTheoChuSo(a, n, exp)) {
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

    radixSort(a, n);
    return 0;
}

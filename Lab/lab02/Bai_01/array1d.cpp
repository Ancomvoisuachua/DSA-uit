#include <iostream>
#include <algorithm>
using namespace std;
void selection_sort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_index])
				min_index = j;
		}
		swap(a[i], a[min_index]);
	}
	output(a, n);
}
void insertion_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j = i - 1;

		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
	output(a, n);
}
void interchange_sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	output(a, n);
}
void input(int a[], int& n) {
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
int main() {
	int a[100];
	int n;
	cin >> n;
	input(a, n);
	cout << "Selection sort: " << endl;
	selection_sort(a, n);
	cout << "Insertion sort: " << endl;
	insertion_sort(a, n);
	cout << "Interchange sort: " << endl;
	interchange_sort(a, n);
	return 1;
}
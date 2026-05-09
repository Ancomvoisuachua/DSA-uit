#include <iostream>
#include <algorithm>
using namespace std;
void input(int a[], int& n) {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void insertion_sort_incr(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j = i - 1;

		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
void insertion_sort_desc(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j = i - 1;

		while (j >= 0 && a[j] < key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
int main()
{
	int n, a[100];
	input(a, n);

	int temp[100], k = 0, 
	int temp1[100], k1 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) temp[k++] = a[i];
		else temp1[k1++] = a[i];
	}
	insertion_sort_incr(temp, k);
	insertion_sort_desc(temp1, k1);

	int k2 = 0;
	for (int i = 0; i < k; i++) a[k2++] = temp[i];
	for (int i = 0; i < k1; i++) a[k2++] = temp1[i];

	output(a, k2);
	return 0;
}
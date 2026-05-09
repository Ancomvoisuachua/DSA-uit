#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
};

int getNth(Node* head, int n) {
	Node* cur = head;
	int index = 0;

	while (cur != nullptr) {
		if (index == n) return cur->val;
		cur = cur->next;
		index++;
	}
	return -1; 
}

int main() {
	int t;
	cin >> t;

	Node* head = nullptr;
	Node* tail = nullptr;

	while (t--) {
		int x;
		cin >> x;

		if (x == 0) return 0;
		else {
			Node* p = new Node(x);

			if (head == nullptr)
				head = tail = p;
			else {
				tail->next = p;
				tail = tail->next;
			}
		}
	}
	int n;
	cin >> n;
	cout << getNth(head, n);
	return 0;
}
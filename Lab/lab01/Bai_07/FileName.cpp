#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
};

void Insert_K(Node*& head, int k) {
	int x;
	cin >> x;
	Node* n = new Node(x);

	if (k == 0) {
		n->next = head;
		head = n;
		return;
	}

	Node* p = head;
	int count = 0;

	while (p && count < k - 1) {
		p = p->next;
		count++;
	}

	if (p) {
		n->next = p->next;
		p->next = n;
	}
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

	int k;
	cin >> k;
	Insert_K(head, k);

	while (head) {
		cout << head->val;
		head = head->next;
	}
	return 0;
}
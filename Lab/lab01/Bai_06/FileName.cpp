#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
};

void Insert_K(Node* p, int k) {
	int x;
	cin >> x;
	Node* n = new Node(x);

	while (p) {
		if (k == p->val) {
			if (p->next == nullptr) 
				p->next = n;
			else {
				n->next = p->next;
				p->next = n;
			}
		}
		p = p->next;
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
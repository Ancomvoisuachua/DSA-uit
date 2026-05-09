#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
};

int Delete(Node*& head) {
	int x;
	cin >> x;

	while (head) {
		if (x == head->val) 
			return 1;
		head = head->next;
	}
	return 0;
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
	cout << Delete(head);
	return 0;
}